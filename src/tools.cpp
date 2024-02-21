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

void openHead(void* args) {
    printf("Open Head Start");
    int angle = *static_cast<int*>(args);
    while (true) {
        if (fabs(Rotate.position(vex::rotationUnits::deg) - angle) < 10) {
            UP1.spin(forward,30,pct);
            UP2.spin(reverse,30,pct);
            break;
        }
        wait(10, msec);
    }
    wait(1000, msec);
    UP1.stop();
    UP2.stop();
}