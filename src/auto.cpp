#include "PIDProcess.h"
#include "stdio.h"
#include "vex.h"
#include "auto.h"
#include"robot-config.h"

void autonomous_task(){
    Rotate.resetPosition();
    printf("Start\n");

    PIDStraightFast(720);
    wait(200, msec);
    PIDRotate(180);
    wait(200, msec);
    PIDStraightSlow(720);
    wait(200, msec);
    PIDRotate(180);

    printf("End\n");
}