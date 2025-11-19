#include <Arduino.h>

int button = 13;
int led = 14;
int buttVa = 0;

int preVa = 0;
int currVa = 0;

int ledState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  currVa = digitalRead(button);
  Serial.println(currVa);
  
  if (preVa == 0 && currVa == 1) {
    if (ledState == 0) {
      digitalWrite(led, HIGH);
      ledState = 1;
    }
    else {
      digitalWrite(led, LOW);
      ledState = 0;
    }
  }

  preVa = currVa;

}

