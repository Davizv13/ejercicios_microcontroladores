unsigned long last_publish_time = 0;
unsigned long publish_interval = 1000;
bool publishing = false;
bool mode_fixed = true;
int value = 1;

void setup() {

  Serial.begin(9600);
  Serial.println("Microcontrolador listo para recibir comandos.");
  Serial.println("Escribe 'h' para ver el menú de ayuda.");

}

void loop() {

  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();

    if (input == "H" || input == "h" || input == "help") {

      Serial.println("Comandos:");
      Serial.println("H o h (help): muestra este menu de ayuda.");
      Serial.println("START o start: publica cada segundo un valor por el puerto serie.");
      Serial.println("STOP o stop: detiene la publicación del valor.");
      Serial.println("T o t (time): El siguiente valor enviado cambiará el periodo de publicación de la señal entre 1 y 10 veces por segundo.");
      Serial.println("M o m (mode): cambia el modo de fijo a alternativo. En modo fijo la señal se emite mantiene siempre el mismo valor siendo el ultimo emitido, por defecto debe ser un 1. Por otra parte, en modo alternativo cada vez que se publica el valor se alterna entre 0 y 1.");
    
    } 
    else if (input == "START" || input == "start") {

      publishing = true;

    } 
    else if (input == "STOP" || input == "stop") {

      publishing = false;

    } 
    else if (input == "T" || input == "t" || input == "time") {

      Serial.println("Escribe el numero de veces por segundo para publicar el valor:");
      while (Serial.available() == 0) { }
      int new_time = Serial.parseInt();

      if (new_time >= 1 && new_time <= 10) {
        publish_interval = 1000 / new_time;
        Serial.print("Nuevo periodo: ");
        Serial.print(new_time);
        Serial.println(" veces por segundo.");
      } else {
        Serial.println("Valor invalido. El intervalo debe ser entre 1 y 10.");
      }
      while (Serial.available() > 0) {
        Serial.read();
      }

    } 
    else if (input == "M" || input == "m" || input == "mode") {

      if (mode_fixed) {
        mode_fixed = false;
        Serial.println("Modo alternativo. Se alternara entre 0 y 1.");
      } else {
        mode_fixed = true;
        Serial.println("Modo fijo. El valor sera siempre el mismo.");
      }

    }
    else {

      Serial.println("Comando no existente. Escribe 'h' para ayuda.");

    }
  }

  if (publishing) {
    unsigned long current_millis = millis();
    if (current_millis - last_publish_time >= publish_interval) {
      last_publish_time = current_millis;
      if (mode_fixed) {
        Serial.println(value);
      } else {
        value = (value == 1) ? 0 : 1;
        Serial.println(value);
      }
    }
  }
}