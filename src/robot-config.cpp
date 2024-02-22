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

motor Motor_BaseLB = motor(PORT14, ratio18_1, true);
motor Motor_BaseRB = motor(PORT15, ratio18_1, false);
motor Motor_BaseLM = motor(PORT16, ratio18_1, false);
motor Motor_BaseRM = motor(PORT17, ratio18_1, true);
motor Motor_BaseLF = motor(PORT6, ratio18_1, true);
motor Motor_BaseRF = motor(PORT2, ratio18_1, false);
motor_group GroupL = motor_group(Motor_BaseLB, Motor_BaseLF, Motor_BaseLM);
motor_group GroupR = motor_group(Motor_BaseRB, Motor_BaseRF, Motor_BaseRM);

Chassis chassis;                                        
rotation Rotate = rotation(PORT9, false);
controller Controller = controller(primary);

digital_out DigitalRight = digital_out(Brain.ThreeWirePort.F);
digital_out DigitalLeft = digital_out(Brain.ThreeWirePort.E);

motor Right_Give = motor(PORT10, ratio18_1, false);
motor Left_Give = motor(PORT3, ratio18_1, false);

motor UP1 = motor(PORT4, ratio18_1, false);
motor UP2 = motor(PORT5, ratio18_1, false);


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
    this_thread::sleep_for(1000);
}
