unsigned long tiempoAnterior = 0;
unsigned long intervalo = 1000;
int contador = 0;

void setup() {
  
  Serial.begin(9600);

}

void loop() {
  unsigned long tiempoActual = millis();
  
  if (tiempoActual - tiempoAnterior >= intervalo) {
    tiempoAnterior = tiempoActual;
    contador++;
    Serial.print("Contador: ");
    Serial.println(contador);
  }

}
