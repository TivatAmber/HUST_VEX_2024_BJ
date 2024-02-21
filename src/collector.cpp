#include "collector.h"
#include "robot-config.h"

Collector::Collector()
{
    Collector_raise.setStopping(brakeType::brake);
    Collector_spin.setStopping(brakeType::brake);
    Collector_raise.setVelocity(25, velocityUnits::pct);
    Collector_spin.setVelocity(55, velocityUnits::pct);
    Collector_raise.setPosition(0, degrees);
    Collector_spin.setPosition(0, degrees);
    Collector_raise.setTimeout(3, timeUnits::sec);
}

void Collector::lower()
{
    if (state_height == state1::up)
    {
        Collector_raise.spinFor(forward, 155 , degrees); 
        state_height = state1::down;
    }
}

void Collector::raise()
{
    if (state_height == state1::down)
    {
        Collector_raise.spinFor(reverse, 155, degrees); 
        state_height = state1::up;
    }
}

void Collector::Spin()
{
    if (state_spin == state2::stop)
    {
        Collector_spin.spin(forward);
        state_spin = state2::spin;
    }
    else if (state_spin == state2::spin)
    {
        Collector_spin.stop();
        state_spin = state2::stop;
    }
}