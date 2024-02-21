#include "vex.h"
#include "auto.h"
#include"robot-config.h"
#include "PID.h"
#include "tools.h"
#include "math.h"
#include "my-timer.h"
#include "PIDProcess.h"

void PIDStraightFast(float target, int MaxTimeMsec) {
    static PID pidRot;
    static bool used = false;
    static MyTimer timer;

    printf("PIDStaright %f\n", target);

    if (false == used) {
        pidRot.setCoefficient(0.3, 0.5, 2);
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
        delta = fmin(fabs(delta), 100) * sign(delta) * 0.5;

        chassis.Move_forward(delta);
        if (timer.getTime() % OutputDeltaTime == 0) printf("%f\n", now);
        if (pidRot.targetArrived()) {
            chassis.chassis_stop();
            break;
        }
        chassis.Move();
        wait(5, msec);
        timer.click();
        if (timer.getTime() > MaxTimeMsec) break;
    }
}

void PIDStraightMostFast(float target, int MaxTimeMsec) {
    static PID pidRot;
    static bool used = false;
    static MyTimer timer;

    printf("PIDStaright %f\n", target);

    if (false == used) {
        pidRot.setCoefficient(2.2, 1, 0);
        pidRot.setDTolerance(1);
        pidRot.setErrorTolerance(3);
        pidRot.setIMax(20);
        pidRot.setIRange(10);
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
        delta = fmin(fabs(delta), 100) * sign(delta) * 0.8;

        chassis.Move_forward(delta);
        if (timer.getTime() % OutputDeltaTime == 0) printf("%f\n", now);
        if (pidRot.targetArrived()) {
            chassis.chassis_stop();
            break;
        }
        chassis.Move();
        wait(5, msec);
        timer.click();
        if (timer.getTime() > MaxTimeMsec) break;
    }
}


void PIDStraightSlow(float target, int MaxTimeMsec) {
    static PID pidRot;
    static bool used = false;
    static MyTimer timer;

    printf("PIDStaright %f\n", target);

    if (false == used) {
        pidRot.setCoefficient(0.25, 0.4, 1);
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
        if (timer.getTime() % OutputDeltaTime == 0) printf("%f\n", now);
        if (pidRot.targetArrived()) {
            chassis.chassis_stop();
            break;
        }
        chassis.Move();
        wait(5, msec);
        timer.click();
        if (timer.getTime() > MaxTimeMsec) break;
    }
}

void PIDStraight(float target, int MaxTimeMsec) {
    PIDStraightFast(target);
}

/// @brief Positive Right - Negetive Left
/// @param deg 
void PIDRotateSlow(float deg, int MaxTimeMsec) {
    static PID pidRot;
    static bool used = false;
    static MyTimer timer;

    printf("PIDRotate %f\n", deg);
    
    if (false == used) {
        pidRot.setCoefficient(0.88, 1, 0);
        pidRot.setDTolerance(0.5);
        pidRot.setErrorTolerance(1);
        pidRot.setIMax(7);
        pidRot.setIRange(10);
    }

    pidRot.setTarget(deg);
    pidRot.refresh();
    timer.reset();

    while (true) {
        float now = Inertial.rotation(rotationUnits::deg);
        pidRot.update(now);
        float delta = pidRot.getOutput();
        delta = fmin(fabs(delta), 100) * sign(delta) * 0.25;

        chassis.Move_free(0, delta);
        if (timer.getTime() % OutputDeltaTime == 0) printf("%f\n", now);
        if (pidRot.targetArrived()) {
            chassis.chassis_stop();
            break;
        }
        chassis.Move();
        wait(5, msec);
        timer.click();
        if (timer.getTime() > MaxTimeMsec) break;
    }
}

/// @brief Positive Right - Negetive Left
/// @param deg 
void PIDRotateFast(float deg, int MaxTimeMsec) {
    static PID pidRot;
    static bool used = false;
    static MyTimer timer;

    printf("PIDRotate %f\n", deg);
    
    if (false == used) {
        pidRot.setCoefficient(2, 0.2, 8);
        pidRot.setDTolerance(2);
        pidRot.setErrorTolerance(5);
    }

    pidRot.setTarget(deg);
    pidRot.refresh();
    timer.reset();

    while (true) {
        float now = Inertial.rotation(rotationUnits::deg);
        pidRot.update(now);
        float delta = pidRot.getOutput();
        delta = fmin(fabs(delta), 100) * sign(delta) * 0.4;

        chassis.Move_free(0, delta);
        if (timer.getTime() % OutputDeltaTime == 0) printf("%f\n", now);
        if (pidRot.targetArrived()) {
            chassis.chassis_stop();
            break;
        }
        chassis.Move();
        wait(5, msec);
        timer.click();
        if (timer.getTime() > MaxTimeMsec) break;
    }
}

/// @brief Positive Right - Negetive Left
/// @param deg 
void PIDRotate(float target, int MaxTimeMsec) {
    PIDRotateSlow(target);
}