#ifndef COLLECTOR_H
#define COLLECTOR_H

class Collector
{
private:
    enum state1{up,down};
    enum state2{stop,spin};
    state1 state_height = state1::up;    // 0 for up, 1 for down
    state2 state_spin = state2::stop;      // 0 for stop, 1 for spin

public:
    Collector();
    void raise();
    void lower();
    void Spin();
};


#endif