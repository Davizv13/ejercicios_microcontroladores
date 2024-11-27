void setup() {
  
  Serial.begin(9600);

}

void loop() {
  
  if (Serial.available() > 0) {
    char recibido = Serial.read();

    
    if (isUpperCase(recibido)) {
      recibido = toLowerCase(recibido);
    } else if (isLowerCase(recibido)) {
      recibido = toUpperCase(recibido);
    }

    Serial.print(recibido);
    }

}