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
#include "EJE_SWRB_TEST_SteerMotorTestDLG.h"
#include "swrbTestDriver.h"

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

static char *aSteerMotorDlgButtonInitText[][1] = {
    {"RETURN"}, 
    {"LIdle"}, 
    {"LFront"}, 
    {"LSide"}, 
    {"MIdle"}, 
    {"MUp"}, 
    {"MDown"}, 
    {"RIdle"}, 
    {"RFront"}, 
    {"RSide"}, 
};

static int gSteerMotorDutyCycleLeft = 0, gSteerMotorDutyCycleMiddle = 0, gSteerMotorDutyCycleRight = 0;

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { WINDOW_CreateIndirect, "winSteerMotor", ID_STEERMOTOR_WINDOW_MAIN, 0, 0, 800, 480, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btnReturn", ID_STEERMOTOR_BUTTON_RETURN, 0, 0, 60, 60, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btnLIdle", ID_STEERMOTOR_BUTTON_LIDLE, 100, 40, 120, 100, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btnLFront", ID_STEERMOTOR_BUTTON_LFRONT, 100, 190, 120, 100, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btnLSide", ID_STEERMOTOR_BUTTON_LSIDE, 100, 340, 120, 100, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btnMIdle", ID_STEERMOTOR_BUTTON_MIDLE, 340, 40, 120, 100, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btnMUp", ID_STEERMOTOR_BUTTON_MUP, 340, 190, 120, 100, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btnMDown", ID_STEERMOTOR_BUTTON_MDOWN, 340, 340, 120, 100, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btnRIdle", ID_STEERMOTOR_BUTTON_RIDLE, 580, 40, 120, 100, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btnRFront", ID_STEERMOTOR_BUTTON_RFRONT, 580, 190, 120, 100, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btnRSide", ID_STEERMOTOR_BUTTON_RSIDE, 580, 340, 120, 100, 0, 0x0, 0 },
  { SLIDER_CreateIndirect, "sliderLeft", ID_STEERMOTOR_SLIDER_LCOLLISION, 30, 125, 40, 250, 8, 0x0, 0 },
  { SLIDER_CreateIndirect, "SliderMiddle", ID_STEERMOTOR_SLIDER_MWHEELFLOAT, 265, 125, 40, 250, 8, 0x0, 0 },
  { SLIDER_CreateIndirect, "SliderRight", ID_STEERMOTOR_SLIDER_RCOLLISION, 500, 125, 40, 250, 8, 0x0, 0 },
  { EDIT_CreateIndirect, "editLeft", ID_STEERMOTOR_EDIT_LCOLLISION, 10, 390, 80, 20, 0, 0x64, 0 },
  { EDIT_CreateIndirect, "editMiddle", ID_STEERMOTOR_EDIT_MWHEELFLOAT, 240, 390, 80, 20, 0, 0x64, 0 },
  { EDIT_CreateIndirect, "editRight", ID_STEERMOTOR_EDIT_RCOLLISION, 480, 390, 80, 20, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "textLeft", ID_STEERMOTOR_TEXT_LCOLLISION, 20, 100, 60, 20, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "textRight", ID_STEERMOTOR_TEXT_MWHEELFLOAT, 480, 100, 80, 20, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "textMiddle", ID_STEERMOTOR_TEXT_RCOLLISION, 245, 100, 80, 20, 0, 0x64, 0 },
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

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
    
    for(Id=ID_STEERMOTOR_BUTTON_RETURN;Id<ID_STEERMOTOR_BUTTON_BOUND;Id++){
        hItem = WM_GetDialogItem(pMsg->hWin, Id);
        BUTTON_SetText(hItem, aSteerMotorDlgButtonInitText[Id-ID_STEERMOTOR_BUTTON_RETURN][0]);
        BUTTON_SetFont(hItem, GUI_FONT_20_ASCII);
        BUTTON_SetSkinClassic(hItem);
        WIDGET_SetEffect(hItem, &WIDGET_Effect_None);
    }

    hItem = WM_GetDialogItem(pMsg->hWin, ID_STEERMOTOR_SLIDER_LCOLLISION);
    SLIDER_SetRange(hItem, 550, 2500);
    SLIDER_SetNumTicks(hItem, 10);
    
    hItem = WM_GetDialogItem(pMsg->hWin, ID_STEERMOTOR_SLIDER_MWHEELFLOAT);
    SLIDER_SetRange(hItem, 270, 1050);
    SLIDER_SetNumTicks(hItem, 10);

    hItem = WM_GetDialogItem(pMsg->hWin, ID_STEERMOTOR_SLIDER_RCOLLISION);
    SLIDER_SetRange(hItem, 550, 2500);
    SLIDER_SetNumTicks(hItem, 10);

    hItem = WM_GetDialogItem(pMsg->hWin, ID_STEERMOTOR_EDIT_LCOLLISION);
    EDIT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    EDIT_SetDecMode(hItem, 0, 0, 10000, 0, GUI_EDIT_SUPPRESS_LEADING_ZEROES);

    hItem = WM_GetDialogItem(pMsg->hWin, ID_STEERMOTOR_EDIT_MWHEELFLOAT);
    EDIT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    EDIT_SetDecMode(hItem, 0, 0, 10000, 0, GUI_EDIT_SUPPRESS_LEADING_ZEROES);

    hItem = WM_GetDialogItem(pMsg->hWin, ID_STEERMOTOR_EDIT_RCOLLISION);
    EDIT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    EDIT_SetDecMode(hItem, 0, 0, 10000, 0, GUI_EDIT_SUPPRESS_LEADING_ZEROES);

    WM_HideWin(pMsg->hWin);
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
        switch(Id) {
            case ID_STEERMOTOR_BUTTON_LIDLE: // Notifications sent by 'btnLIdle'
              switch(NCode) {
              case WM_NOTIFICATION_CLICKED:
                break;
              case WM_NOTIFICATION_RELEASED:
                SweepRobot_CollisionCtrlLeftSteerMotorPosMove(STEER_MOTOR_IDLE_POS);
                break;
              }
              break;
            case ID_STEERMOTOR_BUTTON_LFRONT: // Notifications sent by 'btnLFront'
              switch(NCode) {
              case WM_NOTIFICATION_CLICKED:
                break;
              case WM_NOTIFICATION_RELEASED:
//                    SweepRobot_CollisionCtrlLeftSteerMotorPosMove(STEER_MOTOR_FRONT_POS);
                    SweepRobot_CollisionCtrlLeftSteerMotorPosSet(gSteerMotorDutyCycleLeft);
                  break;
              }
              break;
            case ID_STEERMOTOR_BUTTON_LSIDE: // Notifications sent by 'btnLSide'
              switch(NCode) {
              case WM_NOTIFICATION_CLICKED:
                break;
              case WM_NOTIFICATION_RELEASED:
                SweepRobot_CollisionCtrlLeftSteerMotorPosMove(STEER_MOTOR_SIDE_POS);
                break;
              }
              break;
            case ID_STEERMOTOR_BUTTON_RIDLE: // Notifications sent by 'btnRIdle'
              switch(NCode) {
              case WM_NOTIFICATION_CLICKED:
                break;
              case WM_NOTIFICATION_RELEASED:
                SweepRobot_CollisionCtrlRightSteerMotorPosMove(STEER_MOTOR_IDLE_POS);
                break;
              }
              break;
            case ID_STEERMOTOR_BUTTON_RFRONT: // Notifications sent by 'btnRFront'
              switch(NCode) {
              case WM_NOTIFICATION_CLICKED:
                break;
              case WM_NOTIFICATION_RELEASED:
//                SweepRobot_CollisionCtrlRightSteerMotorPosMove(STEER_MOTOR_FRONT_POS);
                  SweepRobot_CollisionCtrlRightSteerMotorPosSet(gSteerMotorDutyCycleRight);
                break;
              }
              break;
            case ID_STEERMOTOR_BUTTON_RSIDE: // Notifications sent by 'btnRSide'
              switch(NCode) {
              case WM_NOTIFICATION_CLICKED:
                break;
              case WM_NOTIFICATION_RELEASED:
                SweepRobot_CollisionCtrlRightSteerMotorPosMove(STEER_MOTOR_SIDE_POS);
                break;
              }
              break;
            case ID_STEERMOTOR_BUTTON_MIDLE: // Notifications sent by 'btnMIdle'
              switch(NCode) {
              case WM_NOTIFICATION_CLICKED:
                break;
              case WM_NOTIFICATION_RELEASED:
                SweepRobot_WheelFloatCtrlSteerMotorPosMove(STEER_MOTOR_IDLE_POS);
                break;
              }
              break;
            case ID_STEERMOTOR_BUTTON_MUP: // Notifications sent by 'btnMUp'
              switch(NCode) {
              case WM_NOTIFICATION_CLICKED:
                break;
              case WM_NOTIFICATION_RELEASED:
//                SweepRobot_WheelFloatCtrlSteerMotorPosMove(gSteerMotorDutyCycleMiddle);
                SweepRobot_WheelFloatCtrlSteerMotorPosSet(gSteerMotorDutyCycleMiddle);
                break;
              }
              break;
            case ID_STEERMOTOR_BUTTON_MDOWN: // Notifications sent by 'btnMDown'
              switch(NCode) {
              case WM_NOTIFICATION_CLICKED:
                break;
              case WM_NOTIFICATION_RELEASED:
                SweepRobot_WheelFloatCtrlSteerMotorPosMove(STEER_MOTOR_DOWN_POS);
                break;
              }
              break;
            case ID_STEERMOTOR_BUTTON_RETURN: // Notifications sent by 'btnReturn'
              switch(NCode) {
              case WM_NOTIFICATION_CLICKED:
                break;
              case WM_NOTIFICATION_RELEASED:
                WM_HideWin(hWin_SWRB_STEERMOTOR);
                WM_ShowWin(hWin_SWRB_START);
                break;
              }
              break;
            case ID_STEERMOTOR_SLIDER_LCOLLISION:
                switch(NCode) {
                    case WM_NOTIFICATION_CLICKED:
                        break;
                    case WM_NOTIFICATION_RELEASED:
                        break;
                    case WM_NOTIFICATION_VALUE_CHANGED:
                        hItem = WM_GetDialogItem(pMsg->hWin, ID_STEERMOTOR_SLIDER_LCOLLISION);
                        gSteerMotorDutyCycleLeft = SLIDER_GetValue(hItem);
                        Edit_Set_Value(pMsg->hWin, ID_STEERMOTOR_EDIT_LCOLLISION, gSteerMotorDutyCycleLeft);
                        break;
                }
                break;
            case ID_STEERMOTOR_SLIDER_MWHEELFLOAT:
                switch(NCode) {
                    case WM_NOTIFICATION_CLICKED:
                        break;
                    case WM_NOTIFICATION_RELEASED:
                        break;
                    case WM_NOTIFICATION_VALUE_CHANGED:
                        hItem = WM_GetDialogItem(pMsg->hWin, ID_STEERMOTOR_SLIDER_MWHEELFLOAT);
                        gSteerMotorDutyCycleMiddle = SLIDER_GetValue(hItem);
                        Edit_Set_Value(pMsg->hWin, ID_STEERMOTOR_EDIT_MWHEELFLOAT, gSteerMotorDutyCycleMiddle);
                        break;
                }
                break;
            case ID_STEERMOTOR_SLIDER_RCOLLISION:
                switch(NCode) {
                    case WM_NOTIFICATION_CLICKED:
                        break;
                    case WM_NOTIFICATION_RELEASED:
                        break;
                    case WM_NOTIFICATION_VALUE_CHANGED:
                        hItem = WM_GetDialogItem(pMsg->hWin, ID_STEERMOTOR_SLIDER_RCOLLISION);
                        gSteerMotorDutyCycleRight = SLIDER_GetValue(hItem);
                        Edit_Set_Value(pMsg->hWin, ID_STEERMOTOR_EDIT_RCOLLISION, gSteerMotorDutyCycleRight);
                        break;
                }
                break;
            case ID_STEERMOTOR_EDIT_LCOLLISION: // Notifications sent by 'editLeft'
                switch(NCode) {
                    case WM_NOTIFICATION_CLICKED:
                        break;
                    case WM_NOTIFICATION_RELEASED:
                        break;
                    case WM_NOTIFICATION_VALUE_CHANGED:
                        break;
                }
                break;
            case ID_STEERMOTOR_EDIT_MWHEELFLOAT: // Notifications sent by 'editMiddle'
              switch(NCode) {
                  case WM_NOTIFICATION_CLICKED:
                    break;
                  case WM_NOTIFICATION_RELEASED:
                    break;
                  case WM_NOTIFICATION_VALUE_CHANGED:
                    break;
              }
              break;
            case ID_STEERMOTOR_EDIT_RCOLLISION: // Notifications sent by 'editRight'
                switch(NCode) {
                  case WM_NOTIFICATION_CLICKED:
                    break;
                  case WM_NOTIFICATION_RELEASED:
                    break;
                  case WM_NOTIFICATION_VALUE_CHANGED:
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
*       Public code
*
**********************************************************************
*/
WM_HWIN hWin_SWRB_STEERMOTOR;

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       CreatewinSteerMotorDLG
*/
WM_HWIN CreatewinSteerMotorDLG(void)
{
  WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
  return hWin;
}

/*************************** End of file ****************************/
