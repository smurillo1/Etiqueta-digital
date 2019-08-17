import json

from flask import Flask, render_template, redirect, request
from flask_socketio import SocketIO, send, emit
from flask_cors import CORS

app = Flask(__name__)
socketio = SocketIO(app)
CORS(app)

valor = {
    "nome" : 0,
    "desconto" : 0,
    "desconto_atacado": 0,
    "preco_bruto":0
}
    
@socketio.on("enviandoJSON")
def desligar_led(mensagem):
    global valor
    nome,desconto,desconto_atacado,preco_bruto=mensagem.split(',')
    valor["nome"]=nome
    valor["desconto"]=desconto
    valor["desconto_atacado"]=desconto_atacado
    valor["preco_bruto"]=preco_bruto

    
@app.route("/")
def rota_inicial():
    return render_template("index.html")
    
@app.route("/upload", methods = ["POST"])
def rota_upload():
    mensagem = request.get_json()
    socketio.emit("atualiza", mensagem)
    return "200"

@app.route("/download", methods=['GET'])
def rota_download():
    global valor
    temp=valor
    valor = {
        "nome" : 0,
        "desconto" : 0,
        "desconto_atacado": 0,
        "preco_bruto":0
    }
    return json.dumps(temp)

    
if __name__ == "__main__":
    app.run("0.0.0.0",port=8080)