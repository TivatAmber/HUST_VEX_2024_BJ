#ifndef ROBOT_CONFIG_H_
#define ROBOT_CONFIG_H_
#include "vex.h"
#include "chassis.h"

using namespace vex;

extern brain Brain;

// VEXcode devices
extern inertial Inertial;
// Base motors
// Left/Right Front/Back Up/Down
extern motor Motor_BaseLF;
extern motor Motor_BaseLB;
extern motor Motor_BaseLM;
extern motor Motor_BaseRM;
extern motor Motor_BaseRF;
extern motor Motor_BaseRB;
extern motor_group GroupL;
extern motor_group GroupR;
// extern motor Motor_BaseLF1;extern motor Motor_BaseLF2;
// extern motor Motor_BaseLB1;extern motor Motor_BaseLB2;
// extern motor Motor_BaseRF1;extern motor Motor_BaseRF2;
// extern motor Motor_BaseRB1;extern motor Motor_BaseRB2;


extern controller Controller;

extern Chassis chassis;
extern rotation Rotate;

extern digital_out DigitalRight;
extern digital_out DigitalLeft;

extern motor Right_Give;
extern motor Left_Give;

extern motor UP1;
extern motor UP2;


/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );

#endif