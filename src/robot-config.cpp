#include "vex.h"
#include "robot-config.h"
#include "chassis.h"

#include "unfold.h"
#include <iostream>

using namespace vex;

// A global instance of brain used for printing to the V5 Brain screen
brain Brain;

// VEXcode device constructors
inertial Inertial = inertial(PORT11);

motor Motor_BaseLF = motor(PORT1, ratio18_1, true);
motor Motor_BaseLB = motor(PORT2, ratio18_1, true);
motor Motor_BaseRF = motor(PORT3, ratio18_1, false);
motor Motor_BaseRB = motor(PORT4, ratio18_1, false);

motor Motor_Shoot = motor(PORT7, ratio18_1, true);
motor Motor_raise = motor(PORT6, ratio18_1, true);


rotation Rotate = rotation(PORT5, true);

digital_out air_cylinder_folder = digital_out(Brain.ThreeWirePort.A);

Chassis chassis;   
Unfold unfold1;                                  

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
    Controller.Screen.print("GO!");
    Motor_raise.setStopping(vex::brakeType::hold);
    Motor_raise.setVelocity(40, vex::velocityUnits::pct);
    Motor_Shoot.setStopping(hold);
    Motor_Shoot.setVelocity(50, pct);
}
