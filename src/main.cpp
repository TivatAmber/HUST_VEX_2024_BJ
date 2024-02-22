#pragma region VEXcode Generated Robot Configuration
// Make sure all required headers are included.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include "chassis.h"
#include "controller.h"
#include "robot-config.h"
#include "vex.h"
#include "auto.h"
// #define TO_AUT     //定义TO_AUTO则进入自动模式

using namespace vex;

competition Competition;

void user_control() {
  thread controller_thread(My_Controller);
  while (true)
  {
    this_thread::sleep_for(10);
  }
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  #ifdef TO_AUTO
  autonomous_task();
  #endif
  Competition.autonomous(autonomous_task);
  Competition.drivercontrol(user_control);
  vexcodeInit();
  
  while (true) {
    wait(100, msec);
  }
}