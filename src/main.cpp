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
//#define TO_AUTO     //����TO_AUTO������Զ�ģʽ

using namespace vex;



int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  #ifdef TO_AUTO
  autonomous_task();
  chassis.count_task();
  #endif
  
  thread controller_thread(My_Controller);
  while (true)
  {
    this_thread::sleep_for(10);
  }
  
}