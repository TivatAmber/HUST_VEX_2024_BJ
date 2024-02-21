#ifndef ROBOT_CONFIG_H_
#define ROBOT_CONFIG_H_
#include "vex.h"
#include "chassis.h"

#include "unfold.h"

using namespace vex;

extern brain Brain;

// VEXcode devices
extern inertial Inertial;
// Base motors
// Left/Right Front/Back Up/Down
extern motor Motor_BaseLF;
extern motor Motor_BaseLB;
extern motor Motor_BaseRF;
extern motor Motor_BaseRB;
extern motor Motor_raise;
// extern motor Collector_raise;
// extern motor Collector_spin;
extern digital_out air_cylinder_folder;

extern motor Motor_Shoot;

extern Unfold unfold1;
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