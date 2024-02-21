#include "vex.h"
#include "robot-config.h"
#include "chassis.h"
#include <iostream>

using namespace vex;

// A global instance of brain used for printing to the V5 Brain screen
brain Brain;

// VEXcode device constructors
inertial Inertial = inertial(PORT10);

vex::distance Distance = vex::distance(PORT5);

motor Motor_BaseLF1 = motor(PORT1, ratio18_1, true);
motor Motor_BaseLB1 = motor(PORT3, ratio18_1, true);
motor Motor_BaseRF1 = motor(PORT5, ratio18_1, false);
motor Motor_BaseRB1 = motor(PORT7, ratio18_1, false);
motor Motor_BaseLF2 = motor(PORT10, ratio18_1, true);
motor Motor_BaseLB2 = motor(PORT4, ratio18_1, true);
motor Motor_BaseRF2 = motor(PORT6, ratio18_1, false);
motor Motor_BaseRB2 = motor(PORT8, ratio18_1, false);


motor_group Motor_BaseLF = motor_group(Motor_BaseLF1, Motor_BaseLF2);
motor_group Motor_BaseLB = motor_group(Motor_BaseLB1, Motor_BaseLB2);
motor_group Motor_BaseRF = motor_group(Motor_BaseRF1, Motor_BaseRF2);
motor_group Motor_BaseRB = motor_group(Motor_BaseRB1, Motor_BaseRB2);

motor Collector_raise = motor(PORT12, ratio18_1, true);
motor Collector_spin = motor(PORT11, ratio18_1, false);
motor xuan_gua = motor(PORT9, ratio18_1, false);

Chassis chassis;
Collector collector1;                                        
rotation Rotate = rotation(PORT5, false);
controller Controller = controller(primary);


// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */



void vexcodeInit(void){
    Inertial.calibrate();
    std::cout << "calibrated!" << std::endl;
    while (Inertial.isCalibrating());
    std::cout << "calibrated2!" << std::endl;
    this_thread::sleep_for(3000);
    Controller.Screen.print("GO!");
    Controller.Screen.newLine();
    xuan_gua.setVelocity(50, percent);
    xuan_gua.setStopping(hold);
}
