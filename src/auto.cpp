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

    int ang = 800;
    thread openHeadTask(openHead, &ang);
    PIDStraightFast(1240);//(1)1080 51.5cm  58.5
    // Ballstop();

    // wait(300,msec );
    PIDRotate(-45);//(a)
    // wait(300,msec );

    // DigitalRight.set(true);
    // Open Wings
    ang = 170;
    thread OpenWingsTask(distanceOpenWings, &ang);
    PIDStraight(370);//(2)14.5
    // wait(300,msec );

    PIDRotate(-135);//(b)
    // wait(300,msec );
    
    DigitalRight.set(false);

    PIDRotate(-45);
    // wait(300, msec);
    PIDStraight(150);
    // wait(300, msec);
    PIDRotate(-90);
    // Ballout();
    // wait(300, msec);

    // Addition
    

    PIDStraight(307);//(3)13
    wait(300, msec);
    PIDStraight(-120);

    // wait(300,msec);
    Ballstop();

    PIDRotate(-180);//(c)
    // wait(300,msec );
    PIDStraight(500);//(4)17
    // wait(300,msec );
    PIDRotate(-90);//(d)
    // wait(300,msec );

    Ballin();
    PIDStraight(520);//(5)226.5  461
    // wait(300,msec );
    PIDRotate(0);//(e)
    // wait(300,msec );
    // Ballout();
    PIDStraightFast(270);//(6)11
    wait(300,msec );
    Ballstop();
    PIDStraight(-450);//(7)16
    // wait(300,msec ); 
    PIDRotate(-90);//(f)
    // wait(300,msec );
    DigitalRight.set(true);
    Ballin();
    PIDStraight(210);//(8)14.5
    // wait(300, msec);
    PIDRotate(0);//(g)
    // wait(300, msec);
    PIDStraight(500);//(9)14
    wait(300, msec);
    PIDStraight(-150);
    // Ballout();
    UP1.spin(reverse,30,pct);
    UP2.spin(forward,30,pct);
    wait(1000, msec);

    UP1.stop();
    UP2.stop();
    DigitalRight.set(false);
    Right_Give.stop();//ballstop;
    Left_Give.stop();
    Ballstop();

    printf("End\n");
}
