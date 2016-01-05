/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.28                          *
*        Compiled Jan 30 2015, 16:41:06                              *
*        (c) 2015 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

#include "EJE_SWRB_TEST_DLG_Conf.h"
#include "EJE_SWRB_TEST_STEPMOTORTESTDLG.h"
#include "sweeprobot_testing.h"

#include "swrbTestStepMotorDriver.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

static int stepmotorSpeed = 5;
static int stepmotorSteps = 1600;

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { WINDOW_CreateIndirect, "winStepMotorTest", ID_STEPMOTOR_WINDOW_MAIN, 0, 0, 800, 480, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btnRun", ID_STEPMOTOR_BUTTON_RUN, 650, 0, 150, 160, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btnStop", ID_STEPMOTOR_BUTTON_STOP, 650, 160, 150, 160, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btnForward", ID_STEPMOTOR_BUTTON_FORWARD, 60, 70, 150, 150, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btnBackward", ID_STEPMOTOR_BUTTON_BACKWARD, 60, 230, 150, 150, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btnEnable", ID_STEPMOTOR_BUTTON_ENABLE, 220, 70, 150, 150, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btnDisable", ID_STEPMOTOR_BUTTON_DISABLE, 220, 230, 150, 150, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btnExit", ID_STEPMOTOR_BUTTON_EXIT, 650, 320, 150, 160, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "textSpeed", ID_STEPMOTOR_TEXT_SPEED, 420, 30, 80, 40, 0, 0x64, 0 },
  { SLIDER_CreateIndirect, "sliderSpeed", ID_STEPMOTOR_SLIDER_SPEED, 430, 140, 60, 240, 8, 0x0, 0 },
  { EDIT_CreateIndirect, "editSpeed", ID_STEPMOTOR_EDIT_SPEED, 420, 70, 80, 40, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "textSteps", ID_STEPMOTOR_TEXT_STEPS, 530, 30, 80, 40, 0, 0x64, 0 },
  { SLIDER_CreateIndirect, "sliderSteps", ID_STEPMOTOR_SLIDER_STEPS, 540, 140, 60, 240, 8, 0x0, 0 },
  { EDIT_CreateIndirect, "editSteps", ID_STEPMOTOR_EDIT_STEPS, 530, 70, 80, 40, 0, 0x64, 0 },
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

static void Button_RunProc(void)
{
//    SweepRobotTest_StepMotorModeSet(STEP_MOTOR_MODE_RUN);
    SweepRobotTest_StepMotorMoveSteps(stepmotorSpeed, stepmotorSteps);
//    OSTaskResume(SWRB_STEPMOTOR_TASK_PRIO);
}

static void Button_StopProc(void)
{
    SweepRobotTest_StepMotorModeSet(STEP_MOTOR_MODE_STOP);
}

static void Button_ForwardProc(void)
{
    SweepRobotTest_StepMotorDirSet(STEP_MOTOR_DIR_FORWARD);
}

static void Button_BackwardProc(void)
{
    SweepRobotTest_StepMotorDirSet(STEP_MOTOR_DIR_BACKWARD);
}

static void Button_EnableProc(void)
{
    SweepRobotTest_StepMotorEnStateSet(ENABLE);
}

static void Button_DisableProc(void)
{
    SweepRobotTest_StepMotorEnStateSet(DISABLE);
}

static void Button_ExitProc(void)
{
    gSwrbTestSelectFlag = SWRB_TEST_SELECT_NONE;
    
    SweepRobotTest_StepMotorEnStateSet(ENABLE);
    
    WM_HideWin(hWin_SWRB_STEPMOTOR);
    WM_ShowWin(hWin_SWRB_START);
}

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;
  int     NCode;
  int     Id;

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
    //
    // Initialization of 'winStepMotorTest'
    //
    hItem = pMsg->hWin;
    WINDOW_SetBkColor(hItem, 0x00E0D3C5);
    //
    // Initialization of 'btnRun'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_STEPMOTOR_BUTTON_RUN);
    BUTTON_SetText(hItem, "RUN");
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    //
    // Initialization of 'btnStop'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_STEPMOTOR_BUTTON_STOP);
    BUTTON_SetText(hItem, "STOP");
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
  
    hItem = WM_GetDialogItem(pMsg->hWin, ID_STEPMOTOR_BUTTON_EXIT);
    BUTTON_SetText(hItem, "EXIT");
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
  
    hItem = WM_GetDialogItem(pMsg->hWin, ID_STEPMOTOR_BUTTON_FORWARD);
    BUTTON_SetText(hItem, "FORWARD");
    BUTTON_SetFont(hItem, GUI_FONT_24_ASCII);
    
    hItem = WM_GetDialogItem(pMsg->hWin, ID_STEPMOTOR_BUTTON_BACKWARD);
    BUTTON_SetText(hItem, "BACKWARD");
    BUTTON_SetFont(hItem, GUI_FONT_24_ASCII);
    
    hItem = WM_GetDialogItem(pMsg->hWin, ID_STEPMOTOR_BUTTON_ENABLE);
    BUTTON_SetText(hItem, "ENABLE");
    BUTTON_SetFont(hItem, GUI_FONT_24_ASCII);
    
    hItem = WM_GetDialogItem(pMsg->hWin, ID_STEPMOTOR_BUTTON_DISABLE);
    BUTTON_SetText(hItem, "DISABLE");
    BUTTON_SetFont(hItem, GUI_FONT_24_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin, ID_STEPMOTOR_EDIT_SPEED);
    EDIT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    EDIT_SetFont(hItem, GUI_FONT_20_ASCII);
    EDIT_SetDecMode(hItem, 0, 0, 100, 0, GUI_EDIT_SUPPRESS_LEADING_ZEROES);
    EDIT_SetValue(hItem, 0);
    
    hItem = WM_GetDialogItem(pMsg->hWin, ID_STEPMOTOR_EDIT_STEPS);
    EDIT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    EDIT_SetFont(hItem, GUI_FONT_20_ASCII);
    EDIT_SetDecMode(hItem, 0, 0, 16000, 0, GUI_EDIT_SUPPRESS_LEADING_ZEROES);
    EDIT_SetValue(hItem, 0);
    
    hItem = WM_GetDialogItem(pMsg->hWin, ID_STEPMOTOR_SLIDER_SPEED);
    SLIDER_SetRange(hItem, 1, 50);
    SLIDER_SetNumTicks(hItem, 10);
    
    hItem = WM_GetDialogItem(pMsg->hWin, ID_STEPMOTOR_SLIDER_STEPS);
    SLIDER_SetRange(hItem, 100, 16000);
    SLIDER_SetNumTicks(hItem, 16);
    
    hItem = WM_GetDialogItem(pMsg->hWin, ID_STEPMOTOR_TEXT_SPEED);
    TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    TEXT_SetFont(hItem, GUI_FONT_20_ASCII);
    TEXT_SetText(hItem, "Speed");
    
    hItem = WM_GetDialogItem(pMsg->hWin, ID_STEPMOTOR_TEXT_STEPS);
    TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    TEXT_SetFont(hItem, GUI_FONT_20_ASCII);
    TEXT_SetText(hItem, "Steps");
    
    WM_HideWin(pMsg->hWin);
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
        case ID_STEPMOTOR_BUTTON_RUN: // Notifications sent by 'btnRun'
            switch(NCode) {
                case WM_NOTIFICATION_CLICKED:
                    break;
                case WM_NOTIFICATION_RELEASED:
                    Button_RunProc();
                    break;
            }
            break;
        case ID_STEPMOTOR_BUTTON_STOP: // Notifications sent by 'btnStop'
            switch(NCode) {
                case WM_NOTIFICATION_CLICKED:
                    break;
                case WM_NOTIFICATION_RELEASED:
                    Button_StopProc();
                    break;
            }
        break;
        case ID_STEPMOTOR_BUTTON_FORWARD: // Notifications sent by 'btnForward'
            switch(NCode) {
                case WM_NOTIFICATION_CLICKED:
                    break;
                case WM_NOTIFICATION_RELEASED:
                    Button_ForwardProc();
                    break;
            }
            break;
        case ID_STEPMOTOR_BUTTON_BACKWARD: // Notifications sent by 'btnBackward'
            switch(NCode) {
                case WM_NOTIFICATION_CLICKED:
                    break;
                case WM_NOTIFICATION_RELEASED:
                    Button_BackwardProc();
                    break;
            }
            break;
        case ID_STEPMOTOR_BUTTON_ENABLE: // Notifications sent by 'btnEnable'
            switch(NCode) {
                case WM_NOTIFICATION_CLICKED:
                    break;
                case WM_NOTIFICATION_RELEASED:
                    Button_EnableProc();
                    break;
            }
            break;
        case ID_STEPMOTOR_BUTTON_DISABLE: // Notifications sent by 'btnDisable'
            switch(NCode) {
                case WM_NOTIFICATION_CLICKED:
                    break;
                case WM_NOTIFICATION_RELEASED:
                    Button_DisableProc();
                    break;
            }
            break;
        case ID_STEPMOTOR_BUTTON_EXIT: // Notifications sent by 'btnExit'
            switch(NCode) {
                case WM_NOTIFICATION_CLICKED:
                    break;
                case WM_NOTIFICATION_RELEASED:
                    Button_ExitProc();
                    break;
            }
            break;
        case ID_STEPMOTOR_SLIDER_SPEED: // Notifications sent by 'sliderSpeed'
            switch(NCode) {
                case WM_NOTIFICATION_CLICKED:
                    break;
                case WM_NOTIFICATION_RELEASED:
                    break;
                case WM_NOTIFICATION_VALUE_CHANGED:
                    hItem = WM_GetDialogItem(pMsg->hWin, ID_STEPMOTOR_SLIDER_SPEED);
                    stepmotorSpeed = SLIDER_GetValue(hItem);
                    Edit_Set_Value(pMsg->hWin, ID_STEPMOTOR_EDIT_SPEED, stepmotorSpeed);
                    break;
            }
            break;
        case ID_STEPMOTOR_SLIDER_STEPS: // Notifications sent by 'sliderSteps'
            switch(NCode) {
                case WM_NOTIFICATION_CLICKED:
                    break;
                case WM_NOTIFICATION_RELEASED:
                    break;
                case WM_NOTIFICATION_VALUE_CHANGED:
                    hItem = WM_GetDialogItem(pMsg->hWin, ID_STEPMOTOR_SLIDER_STEPS);
                    stepmotorSteps = SLIDER_GetValue(hItem);
                    Edit_Set_Value(pMsg->hWin, ID_STEPMOTOR_EDIT_STEPS, stepmotorSteps);
                    break;
            }
            break;
    }
    break;
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

/*********************************************************************
*
*       Public data
*
**********************************************************************
*/
WM_HWIN hWin_SWRB_STEPMOTOR;

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       CreatewinStepMotor
*/
WM_HWIN CreatewinStepMotor(void) {
  WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
  return hWin;
}

/*************************** End of file ****************************/
