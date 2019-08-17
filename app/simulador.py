import requests

while(True):
    valor = int(input("Informe um valor: "))
    r = requests.post( "https://etiquetadigital.herokuapp.com/" , json = {"repor_produto":"false"} )
    print(r.status_code)

    r = requests.get( "https://etiquetadigital.herokuapp.com/" )
    print(r.json())
