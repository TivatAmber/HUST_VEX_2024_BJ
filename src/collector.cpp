#include "collector.h"
#include "robot-config.h"

Collector::Collector()
{
    Collector_raise.setStopping(brakeType::hold);
    Collector_spin.setStopping(brakeType::brake);
    Collector_raise.setVelocity(30, velocityUnits::pct);
    Collector_spin.setVelocity(50, velocityUnits::pct);
}

void Collector::lower()
{
    if (state_height == state1::up)
    {
        Collector_raise.spinFor(forward, 135 , degrees); 
        state_height = state1::down;
    }
}

void Collector::raise()
{
    if (state_height == state1::down)
    {
        Collector_raise.spinFor(reverse, 135 , degrees); 
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