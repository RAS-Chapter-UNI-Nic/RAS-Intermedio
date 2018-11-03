

#include <LiquidCrystal.h> //Llamado de la libreria de "LiquidCrystal.h" la cual permite trabajar al Arduino con lCD.
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);//Asignacion de pines que utiliza el LCD

#include <DHT.h>
#include <DHT_U.h>

// Incluimos librería
#include "DHT.h"
 
// Definimos el pin digital donde se conecta el sensor
#define DHTPIN 2
// Dependiendo del tipo de sensor
#define DHTTYPE DHT11
 
// Inicializamos el sensor DHT11
DHT dht(DHTPIN, DHTTYPE);

int PWM_Out=0;

void setup() {
  // put your setup code here, to run once:
  dht.begin();
  lcd.begin(16, 2);
  pinMode(3,OUTPUT);
  pinMode(1,OUTPUT);
}

void loop() {

  
  // Leemos la humedad relativa
  int h = dht.readHumidity();
  // Leemos la temperatura en grados centígrados (por defecto)
  int t = dht.readTemperature();
  
  lcd.clear();// put your main code here, to run repeatedly:
  lcd.setCursor(0,0);
  lcd.print("Temperature:");
  lcd.setCursor(13,0);
  lcd.print(t);
  lcd.setCursor(0,2);
  lcd.print("Humidity:");
  lcd.setCursor(10,2);
  lcd.print(h);
  PWM_Out=(t-20)/2;
  PWM_Out=PWM_Out*17;
 analogWrite( 3,PWM_Out);
 if(t>=30){digitalWrite(1,HIGH);}
 else{digitalWrite(1,LOW);}
 delay(100);                                                                                                                                                                                                                                                                                                                                                                                                                                                
}
