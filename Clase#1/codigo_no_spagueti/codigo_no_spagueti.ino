const byte analogPin = 0;  //permite hacer modificaciones en 
                      //la distribucion de los pines desde
                      //una sola linea de codigo 

int sample = 0;       //inicializar variables;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sample = analogRead(analogPin);
  Serial.print("La lectura analogica en el pin ");
  Serial.print(analogPin);
  Serial.print(" es: ");
  if(sample >= 768){              //solo es necesario evaluar
    Serial.println("Alta");       //una condicion por intervalo
  } 
  else if(sample >= 512){
    Serial.println("Medio alta");
  }
  else if(sample >= 256){
    Serial.println("Medio baja");
  } else {
    Serial.println("Baja");
  }
  delay(1000);
}
