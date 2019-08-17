#include "Produto.h"

Produto::Produto( int npino_sensor_prateleira,LiquidCrystal_I2C *temp){
  setNome("NULL");
  setDesconto_atacado(0);
  setDesconto(0);
  setPino_sensor_prateleira(npino_sensor_prateleira);
  lcd=temp;
  AtualizarLCD();
}

void Produto::setPreco_bruto(float npreco_bruto){
  preco_bruto=npreco_bruto;
  AtualizarPrecos();
}

void Produto::setNome(String nnome){ 
  nome=nnome;
}

void Produto::setDesconto_atacado(int ndesconto_atacado){
  
   if(ndesconto_atacado>=0&&ndesconto_atacado<=100){
      desconto_atacado=ndesconto_atacado;
   }else{
      desconto_atacado=0;
   }
   
   AtualizarPrecos();
}

void Produto::setDesconto(int ndesconto){
  
   if(ndesconto>=0&&ndesconto<=100){
      desconto=ndesconto;
   }else{
      desconto=0;
   }

   AtualizarPrecos();
}

void Produto::setPino_sensor_prateleira(int npino_sensor_prateleira){
  pino_sensor_prateleira=npino_sensor_prateleira;
}





String Produto::getNome(){
  return nome;
}
float Produto::getPreco_atacado(){
  return preco_atacado;
}
float Produto::getPreco_varejo(){
  return preco_varejo;
}
float Produto::getPreco_bruto(){
  return preco_bruto;
}
int Produto::getDesconto_atacado(){
  return desconto_atacado;
}
int Produto::getDesconto(){
   return desconto;
}

int Produto::getPino_sensor_prateleira(){
   return pino_sensor_prateleira;
}



bool Produto::VerificarPrateleira(){
  delay(100);
  return digitalRead(pino_sensor_prateleira);
}

void Produto::AtualizarDados(String nnome,float npreco_bruto, int ndesconto, int ndesconto_atacado){
    setNome(nnome);
    setPreco_bruto(npreco_bruto);
    setDesconto(ndesconto);
    setDesconto_atacado(ndesconto_atacado);
    AtualizarLCD();
}

void Produto::AtualizarPrecos(){
  preco_varejo=preco_bruto*((100.0-desconto)/100);
  preco_atacado=preco_varejo*(100.0-desconto_atacado)/100;
}

void Produto::AtualizarLCD(){
  lcd->clear();
  lcd->setCursor(0,0);
  lcd->print(nome);
  lcd->setCursor(0,1);
  lcd->print("V:");lcd->print(preco_varejo);
  lcd->setCursor(9,1);
  lcd->print("A:");lcd->print(preco_atacado);
}
