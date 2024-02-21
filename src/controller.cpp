/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Description: 通过手柄控制                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "controller.h"
#include "robot-config.h"
#include "chassis.h"
#include <math.h>
#include <thread>

using namespace vex;
float speed_ratio = 0.4;//防止摇感过于灵敏
double speed = 30.0;

void controller_task(){
    if(Controller.Axis1.position()!=0 || Controller.Axis3.position()!=0)
    {chassis.Move_free(Controller.Axis3.position()*speed_ratio,Controller.Axis1.position()*speed_ratio);}
    else if(chassis.stop_Monitor()){chassis.Move_stop();}
    chassis.Move();
}

void Ballstop()
{
    Right_Give.stop();
    Left_Give.stop();

}

void Ballin() 
{
    Right_Give.spin(reverse,100,pct);
    Left_Give.spin(forward,100,pct);   
}


void Ballout()
{
    Right_Give.spin(forward,100,pct);
    Left_Give.spin(reverse,100,pct);
} 

void My_Controller(){
    Controller.ButtonX.pressed(Ballin);
    Controller.ButtonB.pressed(Ballout);
    Controller.ButtonA.pressed(Ballstop);
    if(Controller.ButtonR1.pressing()) DigitalRight.set(true);
    if(Controller.ButtonR2.pressing()) DigitalRight.set(false);
    if(Controller.ButtonL1.pressing()) DigitalLeft.set(true);
    if(Controller.ButtonL2.pressing()) DigitalLeft.set(false);
    while (true)
    {
        controller_task();
        this_thread::sleep_for(10);
    }
}