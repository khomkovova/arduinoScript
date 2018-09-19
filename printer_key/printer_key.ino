#include <Keyboard.h>
#include "DRV8825.h"
#include <Arduino.h>
#define MOTOR_STEPS 200
#define RPM 200
#define MOTOR_ACCEL 2000
#define MOTOR_DECEL 1000
#define MICROSTEPS 16
#define DIR 13
#define STEP 12
#define ENABLE 11
#define COEFF 10
#define MODE0 10
#define MODE1 11
#define MODE2 12
DRV8825 stepper(MOTOR_STEPS, DIR, STEP, ENABLE, MODE0, MODE1, MODE2);
boolean buttonsState = true;
const int buttonUp = 5;
const int buttonDown = 4;
const int buttonRight = 3;
const int buttonLeft = 6;

//const int buttonUpdate = 4;
const int buttonNext = 1;
const int buttonBack = 0;
const int buttonPrint = 2;

//const int ledPin =  13;      // the number of the LED pin

void setup() {
  Serial.begin(9600);
  pinMode(buttonUp, INPUT);
  pinMode(buttonDown, INPUT);
  pinMode(buttonRight, INPUT);
  pinMode(buttonLeft, INPUT);
//  pinMode(buttonUpdate, INPUT);
  pinMode(buttonNext, INPUT);
  pinMode(buttonBack, INPUT);
  pinMode(buttonPrint, INPUT);
  Keyboard.begin();

    stepper.begin(RPM, 1);
    stepper.rotate(10 * 200); 
    stepper.disable();
  
}

void type(int key, boolean release) {
  Keyboard.press(key);
  if (release)
    Keyboard.release(key);
}
void print(const __FlashStringHelper *value) {
  Keyboard.print(value);
}
void loop() {
  int value = 0;
  while (Serial.available() > 0 ) {
    value = Serial.read();
    if (value == -1) {
      continue;
    }
  }
  if (value > 0) {               // start motor
    stepper.begin(RPM, 1);
    stepper.rotate(value * COEFF); 
    stepper.disable();
  }
  
if(buttonsState){
  if (digitalRead(buttonUp) == HIGH) {
    Keyboard.press(KEY_UP_ARROW);
    Keyboard.releaseAll();
    buttonsState = false;
    //return;

  }
  if (digitalRead(buttonDown) == HIGH ) {
    
    Keyboard.press(KEY_DOWN_ARROW);
    Keyboard.releaseAll();
    buttonsState = false;
    //return;
  }

  if (digitalRead(buttonRight) == HIGH ) {
    Keyboard.press(KEY_F10);
    Keyboard.releaseAll();
    buttonsState = false;
    //return;
  }

  if (digitalRead(buttonLeft) == HIGH ) {
    Keyboard.press(KEY_F9);
    Keyboard.releaseAll();
    buttonsState = false;
    //return;
  }

  if (digitalRead(buttonNext) == HIGH ) {
    Keyboard.press(KEY_F6);
    Keyboard.releaseAll();
    buttonsState = false;
    //return;
  }

  if (digitalRead(buttonBack) == HIGH ) {
    Keyboard.press(KEY_F5);
    Keyboard.releaseAll();
    buttonsState = false;
    //return;
  }

//  if (digitalRead(buttonUpdate) == HIGH) {
//    Keyboard.press(KEY_F3);
//    Keyboard.releaseAll();
//    return;
//  }

  if (digitalRead(buttonPrint) == HIGH ) {
    Keyboard.press(KEY_F7);
    Keyboard.releaseAll();
    buttonsState = false;
//    return;
  }

}
if(digitalRead(buttonPrint) == LOW &&
digitalRead(buttonBack) == LOW &&
digitalRead(buttonNext) == LOW &&
digitalRead(buttonLeft) == LOW &&
digitalRead(buttonRight) == LOW &&
digitalRead(buttonDown) == LOW  &&
digitalRead(buttonUp) == LOW){
buttonsState = true;

  }




delay(10);
}
