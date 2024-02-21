#ifndef PIDPROCESS_H_
#define PIDPROCESS_H_

static const int DefaultMaxTimeMsec = 4000;
static const int OutputDeltaTime = 100;

void PIDStraightMostFast(float target, int MaxTimeMsec = DefaultMaxTimeMsec);
void PIDStraightFast(float target, int MaxTimeMsec = DefaultMaxTimeMsec);
void PIDStraightSlow(float target, int MaxTimeMsec = DefaultMaxTimeMsec);
void PIDStraight(float target, int MaxTimeMsec = DefaultMaxTimeMsec);
void PIDRotate(float deg, int MaxTimeMsec = DefaultMaxTimeMsec);
void PIDRotateFast(float deg, int MaxTimeMsec = DefaultMaxTimeMsec);
void PIDRotateSlow(float deg, int MaxTimeMsec = DefaultMaxTimeMsec);


#endif