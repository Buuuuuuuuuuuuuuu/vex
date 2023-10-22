/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       tang                                                      */
/*    Created:      2023/9/27 19:40:54                                        */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;

// define your global instances of motors and other devices here


int main() {
    while (1) {
    vex::motor motor1(0);
    vex::motor motor2(9);
    motor2.spinTo(-500, rotationUnits::deg,-100, velocityUnits::dps,false);
    motor1.spinTo(4450, rotationUnits::deg,800, velocityUnits::dps,true);
    motor1.resetPosition();
    motor2.resetPosition();
    motor1.spinTo(500, rotationUnits::deg,100, velocityUnits::dps,false);
    motor2.spinTo(-4450, rotationUnits::deg,-800, velocityUnits::dps,true);
    motor1.resetPosition();
    motor2.resetPosition();
    }
    return 0;
}
