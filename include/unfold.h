#ifndef UNFOLD_H
#define UNFOLD_H

class Unfold
{
private:
    enum{state_fold = 0, state_unfold = 1};
    int state = state_fold;
public:
    Unfold();
    void to_unfold();
    void to_fold();
};

#endif