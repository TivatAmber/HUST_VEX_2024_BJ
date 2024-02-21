#include "my-timer.h"
#include "vex.h"

MyTimer::MyTimer():time(int(0)) {}

void MyTimer::reset()
{
    time = 0;
}

int MyTimer::getTime() const
{
    return time;
}

void MyTimer::click()
{
    time += 5;
}