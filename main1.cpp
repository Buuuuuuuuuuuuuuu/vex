/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       tang                                                      */
/*    Created:      2023/10/22 20:03:37                                       */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;

// define your global instances of motors and other devices here


int main() {
    while(1){
    vex::controller  Controller;
    int dy = Controller.Axis3.position();
    int dx = Controller.Axis4.position();
    vex::motor motor1(18);
    vex::motor motor2(16,true);
    vex::motor motor3(19);
    vex::motor motor4(17,true);
    int vm = 5;
    float vy = vm*dy;
    float vl;
    float vr;
    if (dx >= 0){
        vl = vy;
        vr = vy + 0.5*dx*vm;
    }
    else{
        vr = vy;
        vl = vy - 0.5*dx*vm;
    }
    motor1.spin(fwd, vl, dps);
    motor2.spin(fwd, vr, dps);
    motor3.spin(fwd, vl, dps);
    motor4.spin(fwd, vr, dps);
    }
    return 0;
}
