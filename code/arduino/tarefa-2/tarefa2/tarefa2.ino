/*
 * PARTICIPANTES: 
 *    - Bruno Freire
 *    - Fernando Lima
 *    - Rafael Najjar
 */

#define LED_PIN 13
#define BUT1_PIN  2
#define BUT2_PIN  3

int speed = 1000;
unsigned long previousTime = millis();
int stateLed = LOW;
int lastTimePressedBut1 = 0;
int lastTimePressedBut2 = 0;
int startTimePressedBoth = 0;
int lastTimePressedBoth = 0;

void setup () {
  pinMode(LED_PIN, OUTPUT);       // Enable pin 13 for digital output
  pinMode(BUT1_PIN, INPUT);        // Enable pin  1 for digital input
  pinMode(BUT2_PIN, INPUT);        // Enable pin  2 for digital input
}

void loop () {

  int but1 = digitalRead(BUT1_PIN); // Read button 1
  int but2 = digitalRead(BUT2_PIN); // Read button 2

  unsigned long now = millis();
  if (now - previousTime >= speed) {
    stateLed = !stateLed;
    digitalWrite(LED_PIN, stateLed);     // Copy state to LED
    previousTime = millis();
  }

  if (!but1 && but2 && now - lastTimePressedBut1 > 300) {
    if (speed > 300) {
      speed -= 200;
    }
    lastTimePressedBut1 = millis();
  }

  if (!but2 && but1 && now - lastTimePressedBut2 > 300) {
    if (speed < 2300) {
      speed += 200;
    }
    lastTimePressedBut2 = millis();
  }

  if (!but1 && !but2) {
    if (startTimePressedBoth == 0) {
      startTimePressedBoth = millis();
    }
  } else {
    lastTimePressedBoth = millis();
    if(startTimePressedBoth != 0 && lastTimePressedBoth - startTimePressedBoth < 500){
      while(1);
    }
    startTimePressedBoth = 0;
  }

}
