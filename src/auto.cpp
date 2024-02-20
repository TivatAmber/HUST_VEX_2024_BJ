#include "vex.h"
#include "auto.h"
#include"robot-config.h"

void autonomous_task(){
    chassis.Move_forward(30);
    chassis.Move();
    while (true)
    {
        if(chassis.count_circle()>=3){
            chassis.chassis_stop();
            break;
        }
    }
}