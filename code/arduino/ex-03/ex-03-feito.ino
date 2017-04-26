#include "xtea.c.h"

#define LED 13

int i = 0;

void setup () {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

uint32_t key[] = { 100000, 112000, 123000, 125000 };
uint32_t v[10][2]  = {
  {10, 20},
  {30, 40},
  {50, 60},
  {70, 80},
  {90, 100},
  {110, 120},
  {130, 140},
  {150, 160},
  {170, 180},
  {190, 200}
};

void loop () {
  {
    static int led = 0;
    digitalWrite(LED, led = !led);
  }

  unsigned long t1 = micros();

  //        Serial.print(" ");
  //        Serial.println(v[1]);


  encipher(32, v[i], key);

  //    Serial.print("durante: ");
  //        Serial.print(v[0]);
  //        Serial.print(" ");
  //        Serial.println(v[1]);

  decipher(32, v[i], key);

  //    Serial.print("depois: ");
  //        Serial.print(v[0]);
  //        Serial.print(" ");
  //        Serial.println(v[1]);

  unsigned long t2 = micros();
//  Serial.println(t2 - t1);
  if (i < 10) {
    i++;
  } else {
    i = 0;
  }

}
