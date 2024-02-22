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
float speed_ratio = 1.0;//防止摇感过于灵敏
float rotate_ratio = 0.4;//防止转向过于灵敏
double speed = 30.0;

void controller_task(){
    if(abs(Controller.Axis1.position())>=5 || abs(Controller.Axis3.position())>=5)
    {chassis.Move_free(Controller.Axis3.position()*speed_ratio,Controller.Axis1.position()*speed_ratio*rotate_ratio);}
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

void Up()
{
    UP1.spin(forward,30,pct);
    UP2.spin(reverse,30,pct);
} 

void Down()
{
    UP1.spin(reverse,50,pct);
    UP2.spin(forward,50,pct);
} 

void Hold()
{
    UP1.stop(hold);
    UP2.stop(hold);
}

void ChangeWings() {
    static bool flag = false;
    if (!flag) {
        DigitalRight.set(true);
        DigitalLeft.set(true);
        flag = true;
    } else {
        DigitalRight.set(false);
        DigitalLeft.set(false);
        flag = false;
    
    }
}

void My_Controller(){
    Controller.ButtonX.pressed(Ballin);
    Controller.ButtonB.pressed(Ballout);
    Controller.ButtonA.pressed(Ballstop);
    Controller.ButtonL1.pressed(ChangeWings);
    while (true)
    {
        controller_task();
        this_thread::sleep_for(10);
        //TODO
        Controller.ButtonUp.pressed(Up);
        Controller.ButtonUp.released(Hold);
        Controller.ButtonDown.pressed(Down);
        Controller.ButtonDown.released(Hold);
       

    
    }
}