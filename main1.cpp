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
vex::motor motorbase1(18);
vex::motor motorbase2(16,true);
vex::motor motorbase3(19);
vex::motor motorbase4(17,true);
vex::motor motorpop1(1);
vex::motor motorpop2(8,true);
vex::motor motorcatch1(0);
vex::motor motorcatch2(9,true);
vex::motor motorup1(10);
vex::motor motorup2(11,true);
int flagp = 0;
int vp;
int vc;
int vu;
void Pop(){
    if (flagp == 0){
        flagp = 1;
        vp = 500;
    }
    else{
        flagp = 0;
        vp = 0;
    }
}
int main() {
    while(1){
    vex::controller  Controller;
    int dy = Controller.Axis3.position();
    int dx = Controller.Axis4.position();
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
    motorbase1.spin(fwd, vl, dps);
    motorbase2.spin(fwd, vr, dps);
    motorbase3.spin(fwd, vl, dps);
    motorbase4.spin(fwd, vr, dps);
    Controller.ButtonA.pressed(Pop);
    motorpop1.spin(fwd, -vp, dps);
    motorpop2.spin(fwd, -vp, dps);
    int dc = Controller.Axis2.position();
    if (dc > 1){
        vc = 500;
    }
    else if (dc < -1){
        vc = -500;
    }
    else {
        vc = 0;
    }
    motorcatch1.spin(fwd, -vc, dps);
    motorcatch2.spin(fwd, -vc, dps);
    if (Controller.ButtonUp.pressing() == true){
        vu = 300;
    }
    else if (Controller.ButtonDown.pressing() == true){
        vu = -300;
    }
    else{
        vu = 0;
    }
    motorup1.spin(fwd, vu, dps);
    motorup2.spin(fwd, vu, dps);
    }
    return 0;
}
