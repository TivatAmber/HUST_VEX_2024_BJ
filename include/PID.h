#ifndef PID_H_
#define PID_H_
class PID {
protected:
    float errorCurt, errorPrev, errorDev, errorInt;
    float P, I, D;
    bool firstTime;
    bool arrived;
    float kp, ki, kd;
    float target, errorTol, DTol;
    float IMax, IRange;
    float output;
    float jumpTime;
public:
    PID();
    void refresh();
    float getOutput();
    void update(float input);
    void setTarget(float _Target);
    void setIMax(float _IMax);
    void setIRange(float _IRange);
    void setErrorTolerance(float _errorTol);
    void setDTolerance(float _DTol);
    void setJumpTime(float _jumptime);
    bool targetArrived();
    void setCoefficient(float kp, float ki, float kd);
};

#endif