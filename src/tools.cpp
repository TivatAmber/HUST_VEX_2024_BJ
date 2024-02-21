#include "tools.h"
#include "robot-config.h"

int sign(float x) {
    return x < 0 ? -1 : x == 0 ? 0 : 1;
}

void distanceOpenWings(void* args) {
    printf("StartOpenWings");
    int angle = *static_cast<int*>(args);
    while (true) {
        if (fabs(Rotate.position(vex::rotationUnits::deg) - angle) < 10) {
            DigitalRight.set(true);
            break;
        }
        wait(10, msec);
    }
}