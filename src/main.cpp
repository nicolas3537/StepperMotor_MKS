#include <Arduino.h>

const uint8_t dirPin = 2;
const uint8_t stepPin = 3;

uint8_t speed = 100;
uint8_t steps = 0;

// déclaration de la fonction
void step(int steps);

void setup() {
  // put your setup code here, to run once:
  pinMode(dirPin,OUTPUT);
  pinMode(stepPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Entrer une valeur : ");
}

void loop() {
  // put your main code here, to run repeatedly:
  // premier mouvement
  step(200000);
  delay(100);
  step(-20000);
}

void step(int steps) {
uint8_t stepdelay = 100/speed;
uint8_t stepsleft;

//détermine la direction en fonction du caractére
  if (steps > 0)
  {
    digitalWrite(dirPin,HIGH);
    stepsleft= steps;
  }
  if (steps < 0)
  {
    digitalWrite(dirPin,LOW);
    stepsleft= -steps;
  }
  
  while (stepsleft > 0)
  {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(1);
    digitalWrite(stepPin,LOW);
    delay(stepdelay);
    stepsleft--;
  }
}