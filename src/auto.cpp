#include "vex.h"
#include "auto.h"
#include"robot-config.h"
#include "PID.h"
#include "tools.h"
#include "math.h"
#include "my-timer.h"

static const int MaxTimeMsec = 5000;

void PIDStraightFast(float target) {
    static PID pidRot;
    static bool used = false;
    static MyTimer timer;

    printf("PIDStaright %f\n", target);

    if (false == used) {
        pidRot.setCoefficient(0.6, 0.5, 6);
        pidRot.setDTolerance(0.5);
        pidRot.setErrorTolerance(1);
        used = true;
    }

    pidRot.setTarget(target);
    pidRot.refresh();
    timer.reset();

    Rotate.resetPosition();
    
    while (true) {
        float now = Rotate.position(rotationUnits::deg);
        pidRot.update(now);
        float delta = pidRot.getOutput();
        delta = fmin(fabs(delta), 100) * sign(delta) * 0.6;

        chassis.Move_forward(delta);
        printf("%f\n", now);
        if (pidRot.targetArrived()) {
            chassis.chassis_stop();
            break;
        }
        chassis.Move();
        wait(10, msec);
        timer.click();
        if (timer.getTime() > MaxTimeMsec) break;
    }
}

void PIDStraightSlow(float target) {
    static PID pidRot;
    static bool used = false;
    static MyTimer timer;

    printf("PIDStaright %f\n", target);

    if (false == used) {
        pidRot.setCoefficient(0.4, 0.4, 6);
        pidRot.setDTolerance(0.5);
        pidRot.setErrorTolerance(1);
        used = true;
    }

    pidRot.setTarget(target);
    pidRot.refresh();
    timer.reset();

    Rotate.resetPosition();
    while (true) {
        float now = Rotate.position(rotationUnits::deg);
        pidRot.update(now);
        float delta = pidRot.getOutput();
        delta = fmin(fabs(delta), 100) * sign(delta) * 0.4;

        chassis.Move_forward(delta);
        printf("%f\n", now);
        if (pidRot.targetArrived()) {
            chassis.chassis_stop();
            break;
        }
        chassis.Move();
        wait(10, msec);
        timer.click();
        if (timer.getTime() > MaxTimeMsec) break;
    }
}

void PIDStraight(float target) {
    PIDStraightFast(target);
}

/// @brief Positive Right - Negetive Left
/// @param deg 
void PIDRotate(float deg) {
    static PID pidRot;
    static bool used = false;
    static MyTimer timer;

    printf("PIDRotate %f\n", deg);
    
    if (false == used) {
        pidRot.setCoefficient(0.3, 0.3, 8);
        pidRot.setDTolerance(0.5);
        pidRot.setErrorTolerance(1);
    }

    pidRot.setTarget(deg);
    pidRot.refresh();
    timer.reset();

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
        timer.click();
        if (timer.getTime() > MaxTimeMsec) break;
    }
}

void autonomous_task(){
    Rotate.resetPosition();
    printf("Start\n");

    PIDStraightFast(720);
    wait(200, msec);
    PIDRotate(180);
    wait(200, msec);
    PIDStraightSlow(720);
    wait(200, msec);
    PIDRotate(180);

    printf("End\n");
}