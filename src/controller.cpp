/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Description: 通过手柄控制                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "controller.h"
#include "robot-config.h"
#include "chassis.h"
#include "collector.h"
#include <math.h>
#include <thread>

using namespace vex;
float speed_ratio = 0.6;//防止摇感过于灵敏
double speed = 30.0;

void controller_task(){
    if(Controller.ButtonUp.pressing()){chassis.Move_forward(speed);}
    else if(Controller.ButtonDown.pressing()){chassis.Move_backward(speed);}
    else if(Controller.ButtonLeft.pressing()){chassis.Move_left(speed);}
    else if(Controller.ButtonRight.pressing()){chassis.Move_right(speed);}
    else if(Controller.Axis1.position()!=0 || Controller.Axis3.position()!=0)
    {chassis.Move_free(Controller.Axis3.position()*speed_ratio,Controller.Axis1.position()*speed_ratio);}
    else if(chassis.stop_Monitor()){chassis.Move_stop();}
    chassis.Move();
    if(Controller.ButtonL2.PRESSED){collector1.Spin();}
    if(Controller.ButtonR1.PRESSED){collector1.raise();}
    if(Controller.ButtonR2.PRESSED){collector1.lower();}
}

void My_Controller(){
    while (true)
    {
        controller_task();
        this_thread::sleep_for(10);
    }
}