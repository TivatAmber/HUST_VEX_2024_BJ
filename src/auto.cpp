#include "PIDProcess.h"
#include "stdio.h"
#include "vex.h"
#include "auto.h"
#include"robot-config.h"

void autonomous_task(){
    Rotate.resetPosition();
    printf("Start\n");

    // PIDStraightFast(720);
    // wait(200, msec);
    printf("%f\n", Brain.timer(vex::timeUnits::msec));
    PIDRotateFast(180);
    printf("%f\n", Brain.timer(vex::timeUnits::msec));
    wait(2000, msec);
    
    printf("%f\n", Brain.timer(vex::timeUnits::msec));
    PIDRotateFast(180);
    printf("%f\n", Brain.timer(vex::timeUnits::msec));
    // PIDStraightMostFast(720);
    // wait(200, msec);
    // PIDRotateSlow(180);
    // wait(200, msec);
    // PIDRotateFast(180);
    // wait(2000, msec);
    // PIDRotateSlow(180);
    // wait(200, msec);

    printf("End\n");
}