/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Description: 通过手柄控制                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "controller.h"
#include "robot-config.h"
#include <math.h>
#include <thread>

using namespace vex;
float speed_ratio = 0.6;//防止摇感过于灵敏
float rotate_ratio = 0.25;
double speed = 30.0;

void controller_task(){
    if(Controller.ButtonUp.pressing()){chassis.Move_forward(speed);}
    else if(Controller.ButtonDown.pressing()){chassis.Move_backward(speed);}
    else if(Controller.ButtonLeft.pressing()){chassis.Move_left(speed);}
    else if(Controller.ButtonRight.pressing()){chassis.Move_right(speed);}
    else if(abs(Controller.Axis1.position())>=10 || abs(Controller.Axis3.position())>=10)
    {chassis.Move_free(Controller.Axis3.position()*speed_ratio,Controller.Axis1.position()*rotate_ratio);}
    else if(chassis.stop_Monitor()){chassis.Move_stop();}
    chassis.Move();
    if(Controller.ButtonR1.PRESSED){unfold1.to_unfold();}
    if(Controller.ButtonR2.PRESSED){unfold1.to_fold();}
    if(Controller.ButtonA.pressing()){Motor_raise.spin(forward);}
    else if(Controller.ButtonB.pressing()){Motor_raise.spin(reverse);}
    else{Motor_raise.stop();}
    
}
void My_Controller(){
    Controller.ButtonX.pressed(shoot);
    Controller.ButtonX.released(shoot_stop);
    while (true)
    {
        controller_task();
        this_thread::sleep_for(10);
    }
}

void shoot(){
    Motor_Shoot.spin(forward,30,pct);
}
void shoot_stop(){
    Motor_Shoot.stop();
}
