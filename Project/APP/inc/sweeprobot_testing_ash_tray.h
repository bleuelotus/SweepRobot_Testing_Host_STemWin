#ifndef __SWEEPROBOT_TESTING_ASH_TRAY_H
#define __SWEEPROBOT_TESTING_ASH_TRAY_H

#include "sweeprobot_testing.h"

typedef struct{
    int value;
    int onValue;
    int offValue;
    u8 validCnt;
    u8 validFlag;
}ASH_TRAY_TestTypeDef;

void SweepRobot_AshTrayTestTask(void *pdata);
void ASH_TRAY_TestDataSave(void);
void SweepRobot_AshTrayTestInsCtrlTestPos(void);
void SweepRobot_AshTrayTestInsCtrlIdlePos(void);
void SweepRobot_AshTrayTestInsCtrlOff(void);

#endif