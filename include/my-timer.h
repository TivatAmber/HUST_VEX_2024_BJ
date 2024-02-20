#ifndef MYTIMER_H_
#define MYTIMER_H_
#include "vex.h"
#include "robot-config.h"
class MyTimer
{
private:
    int time;

public:
    MyTimer();
    void reset();
    void click();
    int getTime() const;
};

#endif