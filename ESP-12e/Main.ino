//{"preco_bruto":100,"nome":"biscouto","desconto":10,"desconto_bruto":10}

#include <WiFiServerSecure.h>
#include <WiFiClientSecureAxTLS.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFi.h>
#include <CertStoreBearSSL.h>
#include <ESP8266WiFiScan.h>
#include <WiFiServer.h>
#include <ESP8266WiFiGeneric.h>
#include <WiFiClientSecure.h>
#include <BearSSLHelpers.h>
#include <ESP8266WiFiType.h>
#include <WiFiClientSecureBearSSL.h>
#include <WiFiServerSecureAxTLS.h>
#include <WiFiServerSecureBearSSL.h>
#include <WiFiClient.h>
#include <WiFiUdp.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266HTTPClient.h>

#include <ArduinoJson.h>
#include "Produto.h"
#define SENSOR D3

#define SSID "projetofinal"
#define PASS "ifpb2019"

HTTPClient http;
const String LOCATION="http://etiquetadigital.herokuapp.com";
const String DOWN="/download";
const String UP="/upload";

const size_t capacity = JSON_OBJECT_SIZE(4) + 60;
DynamicJsonDocument doc(capacity); 

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE); //Cria um objeto para controlar o lcd;
Produto prod(SENSOR,&lcd);

void GET_JSON_SERIAL(){
  if(Serial.available()>0){
    String payload=Serial.readString();
    if(payload.startsWith("{") && payload.endsWith("}")){
      deserializeJson(doc, payload);
      prod.AtualizarDados(doc["nome"],doc["preco_bruto"],doc["desconto"],doc["desconto_atacado"]);
      doc.clear();
    }
  }
}

void POST_JSON_SERIAL(){
  doc["repor_produtos"]=prod.VerificarPrateleira();
  serializeJson(doc, Serial);
  Serial.print("\n");
  doc.clear();
}


void GET_JSON_WEB(){
    
    http.begin(LOCATION+DOWN); 
    http.GET();
    String payload = http.getString();
    http.end();  
    deserializeJson(doc, payload);
    if(doc["nome"])
      prod.AtualizarDados(doc["nome"],doc["preco_bruto"],doc["desconto"],doc["desconto_atacado"]);
    doc.clear();
}


void POST_JSON_WEB(){
  
  String payload;
  doc["repor_produtos"]=(prod.VerificarPrateleira()?"true":"false");
  serializeJson(doc, payload);
  
  http.begin(LOCATION+UP); 
  http.addHeader("Content-Type", "application/json");
  http.POST(payload); 
  http.end();

  doc.clear();
}

void setup(void){
  pinMode(SENSOR,INPUT);
  Serial.begin(115200);
  lcd.begin(16,2);
  prod.AtualizarLCD();

  
  WiFi.begin(SSID, PASS);    
  while (WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.println("Aguardando conexão");
  }
}

void loop(){

  GET_JSON_SERIAL();
  POST_JSON_SERIAL();
  GET_JSON_WEB();
  POST_JSON_WEB();
  delay(1000);
}
