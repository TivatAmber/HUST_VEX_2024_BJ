#ifndef PIDPROCESS_H_
#define PIDPROCESS_H_

static const int DefaultMaxTimeMsec = 6000;

void PIDStraightMostFast(float target, int MaxTimeMsec = DefaultMaxTimeMsec);
void PIDStraightFast(float target, int MaxTimeMsec = DefaultMaxTimeMsec);
void PIDStraightSlow(float target, int MaxTimeMsec = DefaultMaxTimeMsec);
void PIDStraight(float target, int MaxTimeMsec = DefaultMaxTimeMsec);
void PIDRotate(float deg, int MaxTimeMsec = DefaultMaxTimeMsec);

#endif