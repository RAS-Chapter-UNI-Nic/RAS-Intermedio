int sample;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sample = analogRead(0);
  Serial.print("La lectura analogica en el pin 0 es: ");
  if(sample >= 0 && sample < 256){
  Serial.println("Baja");
  } 
  else{
  if(sample >= 256 && sample < 512){
  Serial.println("Medio baja");
  } else{
  if(sample >= 512 && sample < 768){
  Serial.println("Medio alta");
  } else{
  if(sample >= 768 && sample < 1024){
  Serial.println("Alta");
  }
  }
  }
  }
  delay(1000);
}
