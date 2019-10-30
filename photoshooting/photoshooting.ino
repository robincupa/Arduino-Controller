#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

IRsend irsend;

#define BUTTONPIN 4
#define PIN_STATUS_LED 13 

int numOfPhotos = 3; 
int Speed = 1;
int shootingDelay = 2000;
int angle = 360;
int start = 0; 
const int pin1 = 8;
const int pin2 = 9;
const int pin3 = 10;
const int pin4 = 11;

void setup() {
  pinMode(BUTTONPIN, INPUT); 
  pinMode(PIN_STATUS_LED, OUTPUT); 
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
}
 

void loop() {
  digitalWrite(PIN_STATUS_LED,  1);
  if (digitalRead(BUTTONPIN)==HIGH){
      for(int i=0;i<numOfPhotos;i++){
        delay(500);
        start=1;
        photoshooting();
        for(int i=0;i<(2*(angle*64/45));i++){
          rotate();
        }
        delay(500); 
      }   
  }
  delay(200);
}

void rotate(){
    motorSwitching1();
    motorSwitching2();
    motorSwitching3();
    motorSwitching4();
    motorSwitching5();
    motorSwitching6();
    motorSwitching7();
    motorSwitching8();
  }

void motorSwitching1(){
    digitalWrite(pin1,HIGH);
    digitalWrite(pin2,LOW);
    digitalWrite(pin3,LOW);
    digitalWrite(pin4,LOW);
    delay(Speed);
  }


void motorSwitching2(){
    digitalWrite(pin1,HIGH);
    digitalWrite(pin2,HIGH);
    digitalWrite(pin3,LOW);
    digitalWrite(pin4,LOW);
    delay(Speed);
  }


void motorSwitching3(){
    digitalWrite(pin1,LOW);
    digitalWrite(pin2,HIGH);
    digitalWrite(pin3,LOW);
    digitalWrite(pin4,LOW);
    delay(Speed);
  }


void motorSwitching4(){
    digitalWrite(pin1,LOW);
    digitalWrite(pin2,HIGH);
    digitalWrite(pin3,HIGH);
    digitalWrite(pin4,LOW);
    delay(Speed);
  }


void motorSwitching5(){
    digitalWrite(pin1,LOW);
    digitalWrite(pin2,LOW);
    digitalWrite(pin3,HIGH);
    digitalWrite(pin4,LOW);
    delay(Speed);
  }


void motorSwitching6(){
    digitalWrite(pin1,LOW);
    digitalWrite(pin2,LOW);
    digitalWrite(pin3,HIGH);
    digitalWrite(pin4,HIGH);
    delay(Speed);
  }


void motorSwitching7(){
    digitalWrite(pin1,LOW);
    digitalWrite(pin2,LOW);
    digitalWrite(pin3,LOW);
    digitalWrite(pin4,HIGH);
    delay(Speed);
  }


void motorSwitching8(){
    digitalWrite(pin1,HIGH);
    digitalWrite(pin2,LOW);
    digitalWrite(pin3,LOW);
    digitalWrite(pin4,HIGH);
    delay(Speed);
  }

void photoshooting() {
  digitalWrite(PIN_STATUS_LED,  0);
  for(int i=0;i<3;i++){
    if (start==1) {
      shot();
      delay(shootingDelay);
    }
    else {break;}
  }
}


  void shot(){
    for(int i =0; i < 3; i++){
          irsend.sendSony(0xB4B8F, 20);
          delay(40);
        }
  }




















  
