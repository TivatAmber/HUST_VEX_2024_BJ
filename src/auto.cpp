#include "vex.h"
#include "auto.h"
#include"robot-config.h"
#include "PID.h"
#include "tools.h"
#include "PIDProcess.h"

#define DEBUG
#define WAY2

//1000deg~164.5cm

void DebugEnd() {
    exit(0);
}

void autonomous_task(){
    Rotate.resetPosition();

    #ifdef DEBUG
    Controller.ButtonA.pressed(DebugEnd);
    #endif

    // for (int i = 0; i < 5; i++) {
    //     printf("%d\n", i + 1);
    //     air_cylinder_folder.set(true);
    //     wait(1000, msec);
    //     air_cylinder_folder.set(false);
    //     wait(3000, msec);
    // }

    PIDStraight(340);
    wait(300, msec);
    PIDRotate(-45);
    // air_cylinder_folder.set(true);
    // int angle = 900;
    // thread CloseWings(distanceCloseWings, &angle);
    PIDStraight(1250);
    wait(300, msec);
    PIDStraight(-500);
    PIDRotate(-45);
    PIDStraight(-500);
    PIDRotate(0);
    PIDStraight(-240);
    PIDRotate(-90);

    #ifdef WAY1
    PIDStraight(-400);
    #endif

    #ifdef WAY2
    air_cylinder_folder.set(true);
    PIDStraight(1350);
    // air_cylinder_folder.set(false);
    #endif
}