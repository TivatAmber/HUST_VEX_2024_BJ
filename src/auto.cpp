#include "PIDProcess.h"
#include "stdio.h"
#include "vex.h"
#include "auto.h"
#include "robot-config.h"
#include "controller.h"
#include "tools.h"

void autonomous_task(){
    Rotate.resetPosition();
    printf("Start\n");


    
    Ballin();
    PIDStraightFast(1200);//(1)1080 51.5cm  58.5
    // Ballstop();

    wait(500,msec );
    PIDRotate(-45);//(a)
    wait(500,msec );

    // DigitalRight.set(true);
    // Open Wings
    int ang = 170;
    thread OpenWings(distanceOpenWings, &ang);

    PIDStraight(327);//(2)14.5
    wait(500,msec );

    PIDRotate(-45);//(b)
    wait(500,msec );
    
    Ballout();
    DigitalRight.set(false);
    wait(200, msec);
    PIDStraight(451);//(3)13
    PIDStraight(-180);

    wait(500,msec);
    Ballstop();

    PIDRotate(-90);//(c)
    wait(500,msec );
    PIDStraight(375);//(4)17
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
    Ballin();
    PIDStraight(304);//(8)14.5
    PIDRotate(90);//(g)
    PIDStraight(350);//(9)14
    Ballout();
    wait(1000, msec);
    DigitalRight.set(false);
    Right_Give.stop();//ballstop;
    Left_Give.stop();

    printf("End\n");
}
