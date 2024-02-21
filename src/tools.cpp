#include "tools.h"
int sign(float x) {
    return x < 0 ? -1 : x == 0 ? 0 : 1;
}

void distanceCloseWings(void* arg) {
    int angle = *static_cast<int*>(arg);
    while (true) {
        if (fabs(Rotate.position(vex::rotationUnits::deg) - angle) < 10) {
            air_cylinder_folder.set(false);
            break;
        }
        wait(10, msec);
    }
}