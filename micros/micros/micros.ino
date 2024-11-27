  unsigned long tiempoAnteriorCtr1 = 0;
  unsigned long tiempoAnteriorCtr2 = 0;
  unsigned long intervaloCtr1 = 100000;
  unsigned long intervaloCtr2 = 2000000;
  int ctr1 = 0;
  int ctr2 = 0;

  void setup() {
    
    Serial.begin(9600);

  }

  void loop() {
    unsigned long tiempoActual = micros();
    
    if (tiempoActual - tiempoAnteriorCtr1 >= intervaloCtr1) {
    tiempoAnteriorCtr1 = tiempoActual;
      ctr1++;

      Serial.print("C1: ");
      Serial.print(ctr1);
      Serial.print(" C2: ");
      Serial.println(ctr2);
    }

    if (tiempoActual - tiempoAnteriorCtr2 >= intervaloCtr2) {
    tiempoAnteriorCtr2 = tiempoActual;
      ctr2++;
      ctr1 -= ctr2;

      Serial.print("C1: ");
      Serial.print(ctr1);
      Serial.print(" C2: ");
      Serial.println(ctr2);

    }
  }
