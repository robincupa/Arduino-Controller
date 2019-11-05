#include <Arduino.h>
#include <IRremote.h>
#include <Stepper.h>


IRsend irsend;

#define BUTTONPIN 2
#define PIN_STATUS_LED 13

int numOfPhotos = 3; 
int start = 0; 
const int stepsPerRevolution = 2048;

Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);



void shot(){
  for(int i=0; i<3; i++){
        irsend.sendSony(0xB4B8F, 20);
        delay(40);
      }
}

void photoshooting() {
  digitalWrite(PIN_STATUS_LED,  0);
  for(int i=0;i<3;i++){
    if (start==1) {
      shot();
      myStepper.step(stepsPerRevolution);
    }
    else {break;}
  }
}

void InterruptFunction(){
  
}

void setup() {
  pinMode(BUTTONPIN, INPUT); 
  pinMode(PIN_STATUS_LED, OUTPUT); 
  myStepper.setSpeed(5);
  }

 
void loop() {
  digitalWrite(PIN_STATUS_LED,  1);
  if(digitalRead(BUTTONPIN)==HIGH){
    for(int i=0;i<numOfPhotos;i++){
        start=1;
        photoshooting();
      } 
  }
}
