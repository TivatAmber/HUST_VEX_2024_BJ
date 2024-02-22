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
#define TO_AUTO

using namespace vex;

void count_task()
{
    while (true)
    {
        // chassis.count_circle();
        this_thread::sleep_for(10);
    }
}

int main() {
    // Initializing Robot Configuration. DO NOT REMOVE!
    vexcodeInit();
    #ifdef TO_AUTO
    Rotate.changed(count_task);
    autonomous_task();
    #endif
    thread controller_thread(My_Controller);
    chassis.Move_forward(0);
    while (true)
    {
        this_thread::sleep_for(10);
    }
}