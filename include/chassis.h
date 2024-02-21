#ifndef CHASSIS_H_
#define CHASSIS_H_
#include "vex.h"

class Chassis
{
private:
    double Motor_speed[4];//LF��LB��RF��RB,ֵΪ�ٷֱ�
    int angle[3];// ��¼����������ת�ĽǶ�
    int circle;//��¼������ת��Ȧ��
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
    int count_circle();//���������ת��Ȧ��
    void count_task();
    void chassis_stop();
};



#endif