#ifndef CHASSIS_H_
#define CHASSIS_H_
#include "vex.h"

class Chassis
{
private:
    double Motor_speed[2];//GroupL, GroupRֵΪ�ٷֱ�
    // int angle[3];// ��¼����������ת�ĽǶ�
public:
    // int circle;//��¼������ת��Ȧ��
    Chassis();
    void Move_forward(double speed=30);
    void Move_backward(double speed=30);
    void Move_left(double speed=30);
    void Move_right(double speed=30);
    void Move_free(double x =0.0,double y =0);
    int stop_Monitor();
    void Move_stop();
    void Move();
    // void count_circle();//���������ת��Ȧ��
    // void count_task();
    void chassis_stop();
};



#endif