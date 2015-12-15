#ifndef __SWEEPROBOT_TESTING_H
#define __SWEEPROBOT_TESTING_H

#include "includes.h"

#include <stdio.h>
#include <string.h>

#include "delay.h"
#include "usart.h"
#include "malloc.h"

#include "ff.h"
#include "exfans.h"
#include "w25qxx.h"
#include "fattester.h"

#include "DIALOG.h"

#include "sram.h"
#include "RTC.h"
#include "ILI93xx.h"
#include "timer.h"
#include "touch.h"
#include "led.h"
#include "key.h"
#include "sdio_SDcard.h"
#include "crypto_tea.h"

#include "eje_logo_char.h"
#include "myChineseText.h"

enum SWRB_Test_State_Pos{

  SWRB_TEST_WHEEL_L_STATE_POS,
  SWRB_TEST_WHEEL_R_STATE_POS,
  SWRB_TEST_BRUSH_L_STATE_POS,
  SWRB_TEST_BRUSH_R_STATE_POS,

  SWRB_TEST_BRUSH_M_STATE_POS,
  SWRB_TEST_FAN_POS,
  SWRB_TEST_IFRD_FL_POS,
  SWRB_TEST_IFRD_FR_POS,

  SWRB_TEST_IFRD_L_POS,
  SWRB_TEST_IFRD_R_POS,
  SWRB_TEST_IFRD_B_FL_POS,
  SWRB_TEST_IFRD_B_FR_POS,

  SWRB_TEST_IFRD_B_SL_POS,
  SWRB_TEST_IFRD_B_SR_POS,
  SWRB_TEST_COLLISION_L_POS,
  SWRB_TEST_COLLISION_FL_POS,

  SWRB_TEST_COLLISION_R_POS,
  SWRB_TEST_COLLISION_FR_POS,
  SWRB_TEST_WHEEL_FLOAT_L_POS,
  SWRB_TEST_WHEEL_FLOAT_R_POS,

  SWRB_TEST_ASH_TRAY_INS_POS,
  SWRB_TEST_ASH_TRAY_LVL_POS,
  SWRB_TEST_UNIWHEEL_POS,
  SWRB_TEST_KEY_POS,

  SWRB_TEST_IRDA_B_POS,
  SWRB_TEST_IRDA_L_POS,
  SWRB_TEST_IRDA_FL_POS,
  SWRB_TEST_IRDA_FR_POS,
  
  SWRB_TEST_IRDA_R_POS,
  SWRB_TEST_BUZZER_POS,
  SWRB_TEST_RGB_LED_POS,

  SWRB_TEST_STATE_POS_BOUND,
};

enum SWRB_TEST_STATE{

  SWRB_TEST_STATE_WHEEL = 1,
  SWRB_TEST_STATE_BRUSH,
  SWRB_TEST_STATE_FAN,
  SWRB_TEST_STATE_IFRD,
  SWRB_TEST_STATE_COLLISION,
  SWRB_TEST_STATE_WHEEL_FLOAT,
  SWRB_TEST_STATE_ASH_TRAY,
  SWRB_TEST_STATE_UNIWHEEL,
  SWRB_TEST_STATE_KEY,
  SWRB_TEST_STATE_IRDA,
  SWRB_TEST_STATE_BUZZER,
  SWRB_TEST_STATE_RGB_LED,
  SWRB_TEST_STATE_CHARGE,

  SWRB_TEST_STATE_BOUND,
};

enum SWRB_TEST_SELECT{
    
    SWRB_TEST_SELECT_NONE,
    SWRB_TEST_SELECT_PCB,
    SWRB_TEST_SELECT_POWER_STATION,
    SWRB_TEST_SELECT_SLAM,
};

enum SWRB_TEST_MODE{
    
    SWRB_TEST_MODE_IDLE,
    SWRB_TEST_MODE_SET,
    SWRB_TEST_MODE_PAUSE,
    SWRB_TEST_MODE_RUN,
};

enum SWRB_TEST_SET_STATE{
    
    SWRB_TEST_SET_STATE_SN,
    SWRB_TEST_SET_STATE_TIME,
    SWRB_TEST_SET_STATE_RESERVE1,
};

#define SWRB_TEST_FAULT_WHEEL_MASK            0x00000003
#define SWRB_TEST_FAULT_WHEEL_L_MASK          0x00000001
#define SWRB_TEST_FAULT_WHEEL_R_MASK          0x00000002

#define SWRB_TEST_FAULT_BRUSH_MASK            0x0000001C
#define SWRB_TEST_FAULT_BRUSH_L_MASK          0x00000004
#define SWRB_TEST_FAULT_BRUSH_R_MASK          0x00000008
#define SWRB_TEST_FAULT_BRUSH_M_MASK          0x00000010

#define SWRB_TEST_FAULT_FAN_MASK              0x00000020

#define SWRB_TEST_FAULT_IFRD_MASK             0x00003FC0
#define SWRB_TEST_FAULT_IFRD_FL_MASK          0x00000040
#define SWRB_TEST_FAULT_IFRD_FR_MASK          0x00000080
#define SWRB_TEST_FAULT_IFRD_L_MASK           0x00000100
#define SWRB_TEST_FAULT_IFRD_R_MASK           0x00000200
#define SWRB_TEST_FAULT_IFRD_B_FL_MASK        0x00000400
#define SWRB_TEST_FAULT_IFRD_B_FR_MASK        0x00000800
#define SWRB_TEST_FAULT_IFRD_B_SL_MASK        0x00001000
#define SWRB_TEST_FAULT_IFRD_B_SR_MASK        0x00002000

#define SWRB_TEST_FAULT_COLLISION_MASK        0x0003C000
#define SWRB_TEST_FAULT_COLLISION_L_MASK      0x00004000
#define SWRB_TEST_FAULT_COLLISION_FL_MASK     0x00008000
#define SWRB_TEST_FAULT_COLLISION_R_MASK      0x00010000
#define SWRB_TEST_FAULT_COLLISION_FR_MASK     0x00020000

#define SWRB_TEST_FAULT_WHEEL_FLOAT_MASK      0x000C0000
#define SWRB_TEST_FAULT_WHEEL_FLOAT_L_MASK    0x00040000
#define SWRB_TEST_FAULT_WHEEL_FLOAT_R_MASK    0x00080000

#define SWRB_TEST_FAULT_ASH_TRAY_MASK         0x00300000
#define SWRB_TEST_FAULT_ASH_TRAY_INS_MASK     0x00100000
#define SWRB_TEST_FAULT_ASH_TRAY_LVL_MASK     0x00200000

#define SWRB_TEST_FAULT_UNIWHEEL_MASK         0x00400000

#define SWRB_TEST_FAULT_KEY_MASK              0x00800000

#define SWRB_TEST_FAULT_IRDA_MASK             0x1F000000
#define SWRB_TEST_FAULT_IRDA_B_MSAK           0x01000000
#define SWRB_TEST_FAULT_IRDA_L_MSAK           0x02000000
#define SWRB_TEST_FAULT_IRDA_FL_MSAK          0x04000000
#define SWRB_TEST_FAULT_IRDA_FR_MSAK          0x08000000
#define SWRB_TEST_FAULT_IRDA_R_MSAK           0x10000000

#define SWRB_TEST_FAULT_BUZZER_MASK           0x20000000

#define SWRB_TEST_FAULT_RGB_LED_MASK          0x40000000

enum SWRB_TEST_DATA_POS{
    
    SWRB_TEST_DATA_WHEEL_L_SPEED_POS,
    SWRB_TEST_DATA_WHEEL_R_SPEED_POS,
    
    SWRB_TEST_DATA_BRUSH_L_CUR_POS,
    SWRB_TEST_DATA_BRUSH_R_CUR_POS,
    SWRB_TEST_DATA_BRUSH_M_CUR_POS,
    
    SWRB_TEST_DATA_FAN_CUR_POS,
    
    SWRB_TEST_DATA_IFRD_FL_TxOn_POS,
    SWRB_TEST_DATA_IFRD_FR_TxOn_POS,
    SWRB_TEST_DATA_IFRD_L_TxOn_POS,
    SWRB_TEST_DATA_IFRD_R_TxOn_POS,
    SWRB_TEST_DATA_IFRD_B_FL_TxOn_POS,
    SWRB_TEST_DATA_IFRD_B_FR_TxOn_POS,
    SWRB_TEST_DATA_IFRD_B_SL_TxOn_POS,
    SWRB_TEST_DATA_IFRD_B_SR_TxOn_POS,
    
    SWRB_TEST_DATA_IFRD_FL_TxOff_POS,
    SWRB_TEST_DATA_IFRD_FR_TxOff_POS,
    SWRB_TEST_DATA_IFRD_L_TxOff_POS,
    SWRB_TEST_DATA_IFRD_R_TxOff_POS,
    SWRB_TEST_DATA_IFRD_B_FL_TxOff_POS,//19
    SWRB_TEST_DATA_IFRD_B_FR_TxOff_POS,
    SWRB_TEST_DATA_IFRD_B_SL_TxOff_POS,
    SWRB_TEST_DATA_IFRD_B_SR_TxOff_POS,
    
    SWRB_TEST_DATA_COLLISION_L_ON_VALUE_POS,
    SWRB_TEST_DATA_COLLISION_FL_ON_VALUE_POS,
    SWRB_TEST_DATA_COLLISION_R_ON_VALUE_POS,
    SWRB_TEST_DATA_COLLISION_FR_ON_VALUE_POS,
    SWRB_TEST_DATA_COLLISION_L_OFF_VALUE_POS,
    SWRB_TEST_DATA_COLLISION_FL_OFF_VALUE_POS,
    SWRB_TEST_DATA_COLLISION_R_OFF_VALUE_POS,
    SWRB_TEST_DATA_COLLISION_FR_OFF_VALUE_POS,
    
    SWRB_TEST_DATA_WHEEL_FLOAT_L_VALUE_POS,
    SWRB_TEST_DATA_WHEEL_FLOAT_R_VALUE_POS,
    
    SWRB_TEST_DATA_ASH_TRAY_INS_VALUE_POS,
    SWRB_TEST_DATA_ASH_TRAY_LVL_VALUE_TxOn_POS,
    SWRB_TEST_DATA_ASH_TRAY_LVL_VALUE_TxOff_POS,
    
    SWRB_TEST_DATA_UNIWHEEL_VALUE_TxOn_POS,
    SWRB_TEST_DATA_UNIWHEEL_VALUE_TxOff_POS,
    
    SWRB_TEST_DATA_KEY_VALUE_POS,
    
    SWRB_TEST_DATA_IRDA_B_RxCODE_POS,
    SWRB_TEST_DATA_IRDA_L_RxCODE_POS,
    SWRB_TEST_DATA_IRDA_FL_RxCODE_POS,
    SWRB_TEST_DATA_IRDA_FR_RxCODE_POS,
    SWRB_TEST_DATA_IRDA_R_RxCODE_POS,
    
    SWRB_TEST_DATA_BUZZER_OK_POS,
    
    SWRB_TEST_DATA_RGB_LED_OK_POS,
    
    SWRB_TEST_DATA_CHARGE_CUR_POS,
    SWRB_TEST_DATA_CHARGE_VOL_POS,
    SWRB_TEST_DATA_CHARGE_24V_POS,
    
    SWRB_TEST_DATA_POWER_STATION_SIG_LL_POS,
    SWRB_TEST_DATA_POWER_STATION_SIG_LS_POS,
    SWRB_TEST_DATA_POWER_STATION_BKOFF_SIG_L_POS,
    SWRB_TEST_DATA_POWER_STATION_SIG_CENTER_POS,
    SWRB_TEST_DATA_POWER_STATION_BKOFF_SIG_R_POS,
    SWRB_TEST_DATA_POWER_STATION_SIG_RS_POS,
    SWRB_TEST_DATA_POWER_STATION_SIG_RL_POS,
    SWRB_TEST_DATA_POWER_STATION_24V_STATE_POS,
};

enum SWRB_TEST_TASK_PRIO{

    KEY_TASK_PRIO=3,
    TOUCH_TASK_PRIO,
    EMWIN_TASK_PRIO,
    SWRB_TEST_CTRL_TASK_PRIO,
    SWRB_TEST_EXCEPTION_CHECK_TASK_PRIO,
    SWRB_TEST_TASK_PRIO_START_BOUND,
    SWRB_WHEEL_TEST_TASK_PRIO,//9
    SWRB_BRUSH_TEST_TASK_PRIO,
    SWRB_FAN_TEST_TASK_PRIO,
    SWRB_IFRD_TEST_TASK_PRIO,
    SWRB_COLLISION_TEST_TASK_PRIO,
    SWRB_WHEEL_FLOAT_TEST_TASK_PRIO,
    SWRB_ASH_TRAY_TEST_TASK_PRIO,
    SWRB_UNIWHEEL_TEST_TASK_PRIO,
    SWRB_KEY_TEST_TASK_PRIO,
    SWRB_IRDA_TEST_TASK_PRIO,
    SWRB_BUZZER_TEST_TASK_PRIO,
    SWRB_RGB_LED_TEST_TASK_PRIO,
    SWRB_CHARGE_TEST_TASK_PRIO,
    SWRB_TEST_TASK_PRIO_END_BOUND,//22
    SWRB_POWER_STATION_TEST_TASK_PRIO,
    SWRB_SLAM_MONITOR_TASK_PRIO,
    USART_TASK_PRIO,
    RTC_TASK_PRIO,
    LED_TASK_PRIO,
    START_TASK_PRIO,
    TASK_PRIO_BOUND,
};

#define START_STK_SIZE                      128
#define TOUCH_STK_SIZE                      256
#define KEY_STK_SIZE                        128
#define RTC_STK_SIZE                        256
#define EMWINDEMO_STK_SIZE		            1024
#define LED_STK_SIZE				        256
#define SWRB_TEST_CTRL_STK_SIZE             256
#define SWRB_TEST_EXCEPTION_CHECK_STK_SIZE  256
#define SWRB_WHEEL_TEST_STK_SIZE            256
#define SWRB_BRUSH_TEST_STK_SIZE            256
#define SWRB_FAN_TEST_STK_SIZE              256
#define SWRB_IFRD_TEST_STK_SIZE             256
#define SWRB_COLLISION_TEST_STK_SIZE        256
#define SWRB_WHEEL_FLOAT_TEST_STK_SIZE      256
#define SWRB_ASH_TRAY_TEST_STK_SIZE         256
#define SWRB_UNIWHEEL_TEST_STK_SIZE         256
#define SWRB_KEY_TEST_STK_SIZE              256
#define SWRB_IRDA_TEST_STK_SIZE             256
#define SWRB_BUZZER_TEST_STK_SIZE           256
#define SWRB_RGB_LED_TEST_STK_SIZE          256
#define SWRB_CHARGE_TEST_STK_SIZE           256
#define SWRB_POWER_STATION_TEST_STK_SIZE    256
#define SWRB_SLAM_MONITOR_STK_SIZE          256

#define SWRB_TEST_USART_READ_TIMES              3
#define SWRB_TEST_USART_IRDA_READ_TIMES         25
#define SWRB_TEST_USART_READ_WAIT_TIME          3
#define SWRB_TEST_VALID_COMP_TIMES              3
#define SWRB_TEST_TEST_TASK_OSTIMEDLY_TIME_MS   1
#define SWRB_TEST_TEST_TASK_INIT_WAIT_TIME_MS   50
#define SWRB_TEST_DUT_SN_WRITE_WAIT_TIME        50

extern u8 usartRxFlag;
extern int usartRxNum;

extern enum SWRB_TEST_SELECT gSwrbTestSelectFlag;
extern enum SWRB_TEST_MODE gSwrbTestMode;
extern enum SWRB_TEST_SET_STATE gSwrbTestSetState;
extern enum SWRB_TEST_TASK_PRIO gSwrbTestRuningTaskPrio;
extern u32 gSwrbTestStateMap;
extern u32 lastSwrbTestStateMap;
extern int gSwrbTestAcquiredData[];
extern u16 gSwrbTestTaskRunCnt;
extern int gSwrbTestValidTaskCnt;
extern int gSwrbTestValidTaskCntTotal;

void OS_Task_Create(void);
void SWRB_NextTestTaskResumePreAct(u8 taskPrio);
void SWRB_NextTestTaskResumePostAct(u8 taskPrio);

void SWRB_TestDataFileWriteData(char *headstr, int data, u8 CRflag);
void SWRB_TestDataFileWriteString(char *str);
void SWRB_TestDataFileWriteDate(char *headStr, RTC_DateTypeDef *date, RTC_TimeTypeDef *time);

void SweepRobot_StartDlgPCBBtnClickProc(void);
void SweepRobot_StartDlgPowerStationBtnClickPorc(void);
void SweepRobot_StartDlgSLAMBtnClickProc(void);

void SweepRobot_PCBTestStartProc(void);
void SweepRobot_PCBTestLoginProc(void);
void SweepRobot_PCBTestLoginOKProc(void);
void SweepRobot_PCBTestLoginCancelProc(void);
void SweepRobot_PCBTestLoginEditProc(WM_MESSAGE *pMsg);
void SweepRobot_PCBTestNumPadOKProc(void);
void SweepRobot_PCBTestStopProc(void);
void SweepRobot_PCBTestExitProc(void);

void SweepRobot_PowerStationTestStartProc(void);
void SweepRobot_PowerStationTestStopProc(void);
void SweepRobot_PowerStationTestExitProc(void);

void SweepRobot_SLAMStartProc(void);
void SweepRobot_SLAMSetProc(void);
void SweepRobot_SLAMStopProc(void);
void SweepRobot_SLAMExitProc(void);

#endif
