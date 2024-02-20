#ifndef CHASSIS_H_
#define CHASSIS_H_
#include "vex.h"

class Chassis
{
private:
    double Motor_speed[4];//LF、LB、RF、RB,值为百分比
    int angle[3];// 记录底盘轮子旋转的角度
    int circle;//记录底盘旋转的圈数
public:
    Chassis();
    void Move_forward(double speed=30);
    void Move_backward(double speed=30);
    void Move_left(double speed=30);
    void Move_right(double speed=30);
    void Move_free(double x =0.0,double y =0);
    int stop_Monitor();
    void Move_stop();
    void Move();
    int count_circle();//计算底盘旋转的圈数
    void count_task();
    void chassis_stop();
};



#endif