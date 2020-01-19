#include <Arduino.h>
#include <IRremote.h>
#include <Stepper.h>

IRsend irsend;

#define BUTTONPIN 2
#define SECBUTTONPIN 4
#define PIN_STATUS_LED 13

int numOfPhotos = 38; 
unsigned long time_now;
unsigned long startMillis;
const unsigned long interval = 3000;
const int stepsPerRevolution = 56;
Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

void shot(){
  for(int i=0; i<3; i++){
        irsend.sendSony(0xB4B8F, 20);
        delay(40);
      }
}

void photoshooting() {
  time_now = millis();
  digitalWrite(PIN_STATUS_LED,  0);
  if(time_now - startMillis >= interval){
    for(int i=0;i<numOfPhotos;i++){
      shot();
      myStepper.step(stepsPerRevolution);   
    }  
    startMillis = time_now;
  }  
}

void (*resetFunc)(void)=0;

void InterruptFunction(){
  resetFunc();
}

void setup() {
  pinMode(BUTTONPIN, INPUT_PULLUP); 
  pinMode(SECBUTTONPIN, INPUT_PULLUP); 
  pinMode(PIN_STATUS_LED, OUTPUT); 
  myStepper.setSpeed(10);  
  attachInterrupt(digitalPinToInterrupt(BUTTONPIN), InterruptFunction, LOW);
  startMillis = millis();
  Serial.begin(9600);
}


void loop() {
  digitalWrite(PIN_STATUS_LED,  1);
  if(digitalRead(SECBUTTONPIN) == LOW){
      photoshooting();
  }
}

