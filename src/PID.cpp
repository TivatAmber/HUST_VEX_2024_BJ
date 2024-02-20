#include "PID.h"
#include "math.h"
#include "tools.h"

PID::PID():firstTime(true), arrived(false), IMax(20), IRange(50), jumpTime(100) {
}

void PID::setTarget(float _target) {target = _target;}
void PID::setIMax(float _IMax) {IMax = _IMax;}
void PID::setIRange(float _IRange) {IRange = _IRange;}
void PID::setErrorTolerance(float _errorTol) {errorTol = _errorTol;}
void PID::setDTolerance(float _DTol){DTol = _DTol;}
void PID::setJumpTime(float _jumpTime) {jumpTime = _jumpTime;}
bool PID::targetArrived() {return arrived;}
void PID::setCoefficient(float _kp, float _ki, float _kd) {kp = _kp; ki = _ki; kd = _kd;}

void PID::refresh() {
    firstTime = true;
    arrived = false;
}

void PID::update(float input) {
    errorCurt = target - input;
    P = kp * errorCurt;
    if (firstTime) {
        firstTime = false;
        errorPrev = errorCurt;
        errorInt = 0;
    }
    errorDev = errorCurt - errorPrev;
    errorPrev = errorCurt;
    D = kd * errorDev;
    if (fabs(P) >= IRange) {
        errorInt = 0;
    } else {
        errorInt += errorCurt;
        if (fabs(errorInt) * ki > IMax)
            errorInt = sign(errorInt) * IMax / ki;
    }
    if (sign(errorInt) != sign(errorCurt) || fabs(errorCurt) <= errorTol) errorInt = 0;
    I = ki * errorInt;
    if (fabs(errorCurt) <= errorTol && fabs(D) <= DTol) {
        arrived = true;
    } else {
        arrived = false;
    }
    output = P + I + D;
}

float PID::getOutput() {return output;}