#include "PIDProcess.h"
#include "stdio.h"
#include "vex.h"
#include "auto.h"
#include"robot-config.h"

void autonomous_task(){
    Rotate.resetPosition();
    printf("Start\n");

    Right_Give.spin(reverse,100,pct);//ballin
    Left_Give.spin(forward,100,pct);
    PIDStraightFast(1238);//(1)1080 51.5cm  58.5
    wait(500,msec );
    PIDRotate(-45);//(a)
    wait(500,msec );
    DigitalRight.set(true);
    PIDStraightSlow(307);//(2)14.5
    wait(500,msec );
    PIDRotate(-45);//(b)
    wait(500,msec );
    PIDStraightSlow(251);//(3)13
    wait(500,msec );
    DigitalRight.set(false);
    PIDRotate(-90);//(c)
    wait(500,msec );
    PIDStraight(355);//(4)17
    wait(500,msec );
    PIDRotate(90);//(d)
    wait(500,msec );
    PIDStraight(520);//(5)226.5  461
    wait(500,msec );
    PIDRotate(90);//(e)
    wait(500,msec );
    PIDStraightFast(230);//(6)11
    wait(500,msec );
    PIDStraight(-335);//(7)16
    wait(500,msec ); 
    PIDRotate(-90);//(f)
    wait(500,msec );
    DigitalRight.set(true);
    PIDStraight(304);//(8)14.5
    PIDRotate(90);//(g)
    PIDStraight(293);//(9)14
    DigitalRight.set(false);
    Right_Give.stop();//ballstop;
    Left_Give.stop();



    printf("End\n");
}
