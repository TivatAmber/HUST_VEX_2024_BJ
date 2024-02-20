#include "vex.h"
#include "robot-config.h"
#include "chassis.h"
#include <iostream>

using namespace vex;

// A global instance of brain used for printing to the V5 Brain screen
brain Brain;

// VEXcode device constructors
inertial Inertial = inertial(PORT19);

vex::distance Distance = vex::distance(PORT5);

motor Motor_BaseLF = motor(PORT14, ratio18_1, true);
motor Motor_BaseLB = motor(PORT15, ratio18_1, false);
motor Motor_BaseRF = motor(PORT16, ratio18_1, false);
motor Motor_BaseRB = motor(PORT17, ratio18_1, true);


Chassis chassis;                                        
rotation Rotate = rotation(PORT9, false);
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
}
