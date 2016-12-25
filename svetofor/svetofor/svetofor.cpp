#include <Arduino.h>

int switchPin = 1;
int redPin=5;
int yellowPin=6;
int greenPin=10;
bool isGreen=false;
int redPassPin=9;
int greenPassPin=11;
int yellowDelay=4000;
int redDelay=7000;
int callRedDelay=3000;
int prepareToStartDelay=3000;

void blinkPin(int pinNumber, int blinkFreq, int blinkDelay);


void setup() {
  // put your setup code here, to run once:
  pinMode(switchPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}


void blinkPin(int pinNumber, int blinkFreq, int blinkDelay){
  bool isOn = false;
  for(int i=0; i*blinkFreq<blinkDelay; i++) {
    isOn = !isOn;
    digitalWrite(pinNumber, isOn);
    delay(blinkFreq);
  }
  digitalWrite(pinNumber,LOW);
}

void loop() {
  if (digitalRead(switchPin) == HIGH)
  {
    blinkPin(greenPin, 500, callRedDelay);
    digitalWrite(yellowPin, HIGH);
    delay(yellowDelay);
    digitalWrite(yellowPin, LOW);
    digitalWrite(redPin, HIGH);
    digitalWrite(redPassPin, LOW);
    digitalWrite(greenPassPin, HIGH);
    delay(redDelay);
    digitalWrite(yellowPin, HIGH);
    blinkPin(greenPassPin, 500, prepareToStartDelay);
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
    delay(500);
  }
  digitalWrite(greenPassPin, LOW);
  digitalWrite(redPassPin, HIGH);
  digitalWrite(greenPin, HIGH);
}
