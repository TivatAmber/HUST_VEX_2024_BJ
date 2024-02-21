#include "vex.h"
#include "chassis.h"
#include "robot-config.h"
using namespace vex;

Chassis::Chassis()
{
    Motor_speed[0] = 0;Motor_speed[1] = 0;
    Motor_speed[2] = 0;Motor_speed[3] = 0;
    angle[0] = 0;angle[1] = 0;angle[2] = 0;
    circle = 0;
    Motor_BaseLF.setStopping(brakeType::hold);    
    Motor_BaseLB.setStopping(brakeType::hold);
    Motor_BaseRF.setStopping(brakeType::hold);
    Motor_BaseRB.setStopping(brakeType::hold);
    Rotate.setPosition(0.0, degrees);    
}
void Chassis::Move()
{
    Motor_BaseLF.spin(forward, Motor_speed[0], percent);
    Motor_BaseLB.spin(forward, Motor_speed[1], percent);
    Motor_BaseRF.spin(forward, Motor_speed[2], percent);
    Motor_BaseRB.spin(forward, Motor_speed[3], percent);
}
void Chassis::Move_forward(double speed)
{
    Motor_speed[0] = speed;Motor_speed[1] = speed;
    Motor_speed[2] = speed;Motor_speed[3] = speed;
}
void Chassis::Move_backward(double speed)
{
    Motor_speed[0] = -speed;Motor_speed[1] = -speed;
    Motor_speed[2] = -speed;Motor_speed[3] = -speed;
}
void Chassis::Move_right(double speed)
{
    Motor_speed[0] = speed;Motor_speed[1] = -speed;
    Motor_speed[2] = -speed;Motor_speed[3] = speed;
}
void Chassis::Move_left(double speed)
{
    Motor_speed[0] = -speed;Motor_speed[1] = speed;
    Motor_speed[2] = speed;Motor_speed[3] = -speed;
}
void Chassis::Move_free(double x, double y)
{
    Motor_speed[0] = x + y;Motor_speed[1] = x + y;
    Motor_speed[2] = x - y;Motor_speed[3] = x - y;

}

void Chassis::Move_stop()
{
    Motor_speed[0] = 0;Motor_speed[1] = 0;
    Motor_speed[2] = 0;Motor_speed[3] = 0;
}
int Chassis::stop_Monitor()
{
    if (Controller.ButtonUp.RELEASED==0 && Controller.ButtonDown.RELEASED==0
        && Controller.ButtonLeft.RELEASED==0 && Controller.ButtonRight.RELEASED==0)
    {
        return 1;
    }
    return 0;
}
int Chassis::count_circle()
{
    angle[2] = angle[1];
    angle[1] = angle[0];
    angle[0] = Rotate.angle(rotationUnits::deg);
    if (angle[2]- angle[0]>345 || angle[2]- angle[0]<-345)
    {
        circle++;
        printf("the circle is:%d\n",circle);
        Controller.Screen.print("the circle is:%d",circle);
        Controller.Screen.newLine();
        Brain.Screen.print("the circle is:%d",circle);
        Brain.Screen.newLine();
        wait(50,msec);
    }
    return circle;
}
void Chassis::count_task()
{
    while (true)
    {
        count_circle();
        this_thread::sleep_for(10);
    }
}
void Chassis::chassis_stop()
{
    Motor_BaseLF.stop();
    Motor_BaseLB.stop();
    Motor_BaseRF.stop();
    Motor_BaseRB.stop();
}