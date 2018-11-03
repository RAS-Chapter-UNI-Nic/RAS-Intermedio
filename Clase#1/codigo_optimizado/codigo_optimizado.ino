#define ANALOG_PIN 0

byte sample = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sample = analogRead(ANALOG_PIN)>>8;                 //optimizado para espacio de memoria y tiempo de ejecucion
  //sample = map(analogRead(ANALOG_PIN),0,1023,0,3);  //optimizado para legibilidad
  Serial.print("La lectura analogica en el pin ");
  Serial.print(ANALOG_PIN);
  Serial.print("es: ");
  switch(sample){
    case 0:
      Serial.println("Baja");
    break;
    case 1:
      Serial.println("Medio baja");
    break;
    case 2:
      Serial.println("Medio alta");
    break;
    case 3:
      Serial.println("Alta");
    break;
  }
  delay(1000);
}
