#ifndef PRODUTO_H
#define PRODUTO_H

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

class Produto{

  private:
  
    String nome;
    float preco_bruto;
    float preco_atacado;
    float preco_varejo;
    int desconto_atacado;
    int desconto;
    int pino_sensor_prateleira;
    LiquidCrystal_I2C *lcd;

  public:

    Produto(int pino_sensor_prateleira,LiquidCrystal_I2C *temp);
    
    void setNome(String nnome);
    void setPreco_bruto(float npreco_bruto);
    void setDesconto_atacado(int ndesconto_atacado);
    void setDesconto(int ndesconto);
    void setPino_sensor_prateleira(int npino_sensor_prateleira);
    
    String getNome();
    float getPreco_atacado();
    float getPreco_varejo();
    float getPreco_bruto();
    int getDesconto_atacado();
    int getDesconto();
    int getPino_sensor_prateleira();

    void AtualizarPrecos();
    void AtualizarDados(String nnome,float preco_bruto, int desconto, int desconto_atacado);
    void AtualizarLCD();
    bool VerificarPrateleira();
};


#endif
