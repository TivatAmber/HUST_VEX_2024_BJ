#include "vex.h"
#include "auto.h"
#include"robot-config.h"
#include "PID.h"
#include "tools.h"
#include "math.h"

void PIDStraight(float target) {
    static PID pidRot;
    static bool used = false;

    printf("PIDStaright %f\n", target);

    if (false == used) {
        pidRot.setCoefficient(0.5, 0.5, 6);
        pidRot.setDTolerance(0.5);
        pidRot.setErrorTolerance(1);
        used = true;
    }

    pidRot.setTarget(target);
    pidRot.refresh();

    Rotate.resetPosition();
    while (true) {
        float now = Rotate.position(rotationUnits::deg);
        pidRot.update(now);
        float delta = pidRot.getOutput();
        delta = fmin(fabs(delta), 100) * sign(delta) * 0.5;

        chassis.Move_forward(delta);
        printf("%f\n", now);
        if (pidRot.targetArrived()) {
            chassis.chassis_stop();
            break;
        }
        chassis.Move();
        wait(10, msec);
    }
}

/// @brief Positive Right - Negetive Left
/// @param deg 
void PIDRotate(float deg) {
    static PID pidRot;
    static bool used = false;

    printf("PIDRotate %f\n", deg);
    
    if (false == used) {
        pidRot.setCoefficient(0.3, 0.3, 8);
        pidRot.setDTolerance(0.5);
        pidRot.setErrorTolerance(1);
    }

    pidRot.setTarget(deg);
    pidRot.refresh();

    Inertial.resetRotation();
    while (true) {
        float now = Inertial.rotation(rotationUnits::deg);
        pidRot.update(now);
        float delta = pidRot.getOutput();
        delta = fmin(fabs(delta), 100) * sign(delta) * 0.25;

        chassis.Move_free(0, delta);
        printf("%f\n", now);
        if (pidRot.targetArrived()) {
            chassis.chassis_stop();
            break;
        }
        chassis.Move();
        wait(10, msec);
    }
}

void autonomous_task(){
    Rotate.resetPosition();
    printf("Start\n");

    PIDStraight(720);
    wait(200, msec);
    PIDRotate(180);
    wait(200, msec);
    PIDStraight(720);
    wait(200, msec);
    PIDRotate(180);

    printf("End\n");
}