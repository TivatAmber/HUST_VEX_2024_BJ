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
extern motor_group Motor_BaseLF;
extern motor_group Motor_BaseLB;
extern motor_group Motor_BaseRF;
extern motor_group Motor_BaseRB;
extern motor Motor_BaseLF1;extern motor Motor_BaseLF2;
extern motor Motor_BaseLB1;extern motor Motor_BaseLB2;
extern motor Motor_BaseRF1;extern motor Motor_BaseRF2;
extern motor Motor_BaseRB1;extern motor Motor_BaseRB2;


extern controller Controller;

extern Chassis chassis;
extern rotation Rotate;


/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );

#endif