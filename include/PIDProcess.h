#ifndef PIDPROCESS_H_
#define PIDPROCESS_H_

static const int MaxTimeMsec = 6000;

void PIDStraightFast(float target);
void PIDStraightSlow(float target);
void PIDStraight(float target);
void PIDRotate(float deg);

#endif