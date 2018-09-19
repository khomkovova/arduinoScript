
#include <Arduino.h>
#define MOTOR_STEPS 200
#define RPM 200
#define MOTOR_ACCEL 2000
#define MOTOR_DECEL 1000
#define MICROSTEPS 16

#define DIR 55
#define STEP 54
#define ENABLE 38 // optional (just delete ENABLE from everywhere if not used)

 #include "DRV8825.h"
 #define MODE0 10
 #define MODE1 11
 #define MODE2 12
 DRV8825 stepper(MOTOR_STEPS, DIR, STEP, ENABLE, MODE0, MODE1, MODE2);

//A4988 stepper(MOTOR_STEPS, DIR, STEP, MS1, MS2, MS3);

int value = 0;

void setup() {
    Serial.begin(9600);
    stepper.begin(500, 1);
}

void loop() {
  while (Serial.available() > 0 ) {

     value = Serial.read();

     if(value == -1) {
      continue;
     }

//      Serial.println("Value: " + String(value));
   }

     

     if(value > 128) {
      value = value - 256;
     }
    
     if(value > 1) {
//      Serial.println("rr");
      stepper.rotate(-5);
     }
     
     if(value < -1) {
//      Serial.println("ll");    
      stepper.rotate(5);
     }

    

   delay(20);

}

//void setup() {
//    Serial.begin(115200);
//
//    stepper.begin(RPM, MICROSTEPS);
//
//    stepper.setSpeedProfile(stepper.LINEAR_SPEED, MOTOR_ACCEL, MOTOR_DECEL);
//
//    Serial.println("START");
//     stepper.startRotate(360);
//}
//
//void loop() {
////    static int step = 0;
////    unsigned wait_time = stepper.nextAction();
////    if (wait_time){
////        Serial.print("  step="); Serial.print(step++);
////        Serial.print("  dt="); Serial.print(wait_time);
////        Serial.print("  rpm="); Serial.print(stepper.getCurrentRPM());
////        Serial.println();
////    } else {
////        stepper.disable();
////        Serial.println("END");
////        delay(3600000);
////    }
//
//}
