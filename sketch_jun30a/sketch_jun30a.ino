// MultiStepper.pde
// -*- mode: C++ -*-
//
// Shows how to multiple simultaneous steppers
// Runs one stepper forwards and backwards, accelerating and decelerating
// at the limits. Runs other steppers at the same time
//
// Copyright (C) 2009 Mike McCauley
// $Id: HRFMessage.h,v 1.1 2009/08/15 05:32:58 mikem Exp mikem $

#include <AccelStepper.h>

// Define some steppers and the pins the will use

AccelStepper stepper(1, 55, 54, 38);

void setup()
{  

    
    stepper.setMaxSpeed(300.0);
    stepper.setSpeed(45);
//    stepper.setAcceleration(100.0);
//    stepper.moveTo(100000); 
    
}

void loop()
{

stepper.moveTo(200);
stepper.runSpeed();
stepper.run();
    
}
