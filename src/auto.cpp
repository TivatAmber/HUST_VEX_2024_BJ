#include "vex.h"
#include "auto.h"
#include"robot-config.h"
#include "PID.h"
#include "tools.h"
#include "PIDProcess.h"

//1000deg~164.5cm

void autonomous_task(){
    PIDStraightFast(1000);
}