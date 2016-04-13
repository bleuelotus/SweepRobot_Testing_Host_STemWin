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

// USER START (Optionally insert additional includes)
// USER END

#include "sweeprobot_testing.h"

#include "eje_logo_char.h"
#include "sweeprobot_testing_power_station.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
WM_HWIN hWin_SWRB_POWER_STATION;
// USER START (Optionally insert additional defines)
// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/
/*********************************************************************
*
*       _acImage_0, "D:\works\project\SweepRobot_Testing_Project\software\SweepRobot_Testing_Host\Project\Framework\GUI\res\pic\PowerStation157x200.bmp", ID_PS_IMAGE_0_IMAGE_0
*/

// USER START (Optionally insert additional static data)
// USER END

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { WINDOW_CreateIndirect, "Window", ID_PS_WINDOW_MAIN, 0, 0, 800, 480, 0, 0x0, 0 },
  { IMAGE_CreateIndirect, "Image", ID_PS_IMAGE_PS, 305, 44, 150, 200, 0, 0, 0 },
  { BUTTON_CreateIndirect, "btnStart", ID_PS_BUTTON_START, 700, 0, 100, 120, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btnSet", ID_PS_BUTTON_SET, 700, 120, 100, 120, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btnStop", ID_PS_BUTTON_STOP, 700, 240, 100, 120, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btnExit", ID_PS_BUTTON_EXIT, 700, 360, 100, 120, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btnIndicate", ID_PS_BUTTON_INDICATE, 200, 40, 30, 30, 0, 0x0, 0 },
//  { MULTIPAGE_CreateIndirect, "Multipage", ID_PS_MULTIPAGE_MAIN, 0, 0, 800, 480, 0, 0x0, 0 },
  { CHECKBOX_CreateIndirect, "Sig_LL(0x41)", ID_PS_CHECKBOX_LL, 480, 400, 150, 30, 0, 0x0, 0 },
  { CHECKBOX_CreateIndirect, "Sig_LS(0x44)", ID_PS_CHECKBOX_LS, 480, 340, 150, 30, 0, 0x0, 0 },
  { CHECKBOX_CreateIndirect, "Sig_L(0x46)", ID_PS_CHECKBOX_L, 480, 280, 150, 30, 0, 0x0, 0 },
  { CHECKBOX_CreateIndirect, "Sig_M(0x40)", ID_PS_CHECKBOX_M, 340, 280, 120, 30, 0, 0x0, 0 },
  { CHECKBOX_CreateIndirect, "Sig_R(0x45)", ID_PS_CHECKBOX_R, 200, 279, 120, 30, 0, 0x0, 0 },
  { CHECKBOX_CreateIndirect, "Sig_RS(0x42)", ID_PS_CHECKBOX_RS, 200, 340, 150, 30, 0, 0x0, 0 },
  { CHECKBOX_CreateIndirect, "Sig_RL(0x43)", ID_PS_CHECKBOX_RL, 200, 400, 120, 30, 0, 0x0, 0 },
  { CHECKBOX_CreateIndirect, "24V Out", ID_PS_CHECKBOX_24V, 480, 90, 120, 30, 0, 0x0, 0 },
  { CHECKBOX_CreateIndirect, "PowerStation", ID_PS_CHECKBOX_INDICATE, 480, 40, 200, 30, 0, 0x0, 0 },
  { MULTIEDIT_CreateIndirect, "MultiEdit", ID_PS_MULTIEDIT_MAIN, 20, 40, 130, 400, 0, 0x0, 0 },
  // USER START (Optionally insert additional widgets)
  // USER END
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/
/*********************************************************************
*
*       _GetImageById
*/
static const void * _GetImageById(U32 Id, U32 * pSize) {
  switch (Id) {
  case ID_PS_IMAGE_0_IMAGE_0:
    *pSize = sizeof(_acImage_power_station);
    return (const void *)_acImage_power_station;
  }
  return NULL;
}

// USER START (Optionally insert additional static code)
static void Button_Init(WM_HWIN hItem)
{
    BUTTON_SetFont(hItem, GUI_FONT_24_ASCII);
    BUTTON_SetSkinClassic(hItem);
    WIDGET_SetEffect(hItem, &WIDGET_Effect_None);
}
// USER END

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) {
  const void * pData;
  WM_HWIN      hItem;
  MULTIPAGE_Handle hMultiPage;
  U32          FileSize;
  int          NCode;
  int          Id;
  // USER START (Optionally insert additional variables)
  int          i;
  // USER END

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
//    //
//    // Initialization of 'Multipage'
//    //
//    hMultiPage = WM_GetDialogItem(pMsg->hWin, ID_PS_MULTIPAGE_MAIN);
//    MULTIPAGE_AddEmptyPage(hMultiPage, 0, "PowerStation");
//    MULTIPAGE_AddEmptyPage(hMultiPage, 1, "ChargeCurve");
//    MULTIPAGE_SetTabHeight(hMultiPage, 40);
    //
    // Initialization of 'Image'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_PS_IMAGE_PS);
    pData = _GetImageById(ID_PS_IMAGE_0_IMAGE_0, &FileSize);
    IMAGE_SetBMP(hItem, pData, FileSize);
    //
    // Initialization of 'btnStart'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_PS_BUTTON_START);
    BUTTON_SetText(hItem, "START");
    Button_Init(hItem);
    //
    // Initialization of 'btnSet'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_PS_BUTTON_SET);
    BUTTON_SetText(hItem, "SET");
    Button_Init(hItem);
    //
    // Initialization of 'btnStop'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_PS_BUTTON_STOP);
    BUTTON_SetText(hItem, "STOP");
    Button_Init(hItem);
    //
    // Initialization of 'btnExit'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_PS_BUTTON_EXIT);
    BUTTON_SetText(hItem, "EXIT");
    Button_Init(hItem);
    //
    // Initialization of 'btnIndicate'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_PS_BUTTON_INDICATE);
    BUTTON_SetText(hItem, " ");
    Button_Init(hItem);
//    WM_DisableWindow(hItem);
    //
    // Initialization of 'Checkbox'
    //
    for(i=ID_PS_CHECKBOX_LL;i<=ID_PS_CHECKBOX_INDICATE;i++){
        hItem = WM_GetDialogItem(pMsg->hWin, i);
        CHECKBOX_SetFont(hItem, GUI_FONT_16B_ASCII);
        WM_DisableWindow(hItem);
        switch(i){
            case ID_PS_CHECKBOX_LL:
                CHECKBOX_SetText(hItem, "Sig_LL(0x41)");
                break;
            case ID_PS_CHECKBOX_LS:
                CHECKBOX_SetText(hItem, "Sig_LS(0x44)");
                break;
            case ID_PS_CHECKBOX_L:
                CHECKBOX_SetText(hItem, "Sig_L(0x46)");
                break;
            case ID_PS_CHECKBOX_M:
                CHECKBOX_SetText(hItem, "Sig_M(0x40)");
                break;
            case ID_PS_CHECKBOX_R:
                CHECKBOX_SetText(hItem, "Sig_R(0x45)");
                break;
            case ID_PS_CHECKBOX_RS:
                CHECKBOX_SetText(hItem, "Sig_RS(0x42)");
                break;
            case ID_PS_CHECKBOX_RL:
                CHECKBOX_SetText(hItem, "Sig_RL(0x43)");
                break;
            case ID_PS_CHECKBOX_24V:
                CHECKBOX_SetText(hItem, "24V OUT");
                break;
            case ID_PS_CHECKBOX_INDICATE:
                CHECKBOX_SetText(hItem, "PowerStation");
                break;
        }
    }
    
    WM_HideWin(pMsg->hWin);
    // USER START (Optionally insert additional code for further widget initialization)
    // USER END
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
        case ID_PS_MULTIPAGE_MAIN: // Notifications sent by 'Multipage'
            switch(NCode) {
                case WM_NOTIFICATION_CLICKED:
                // USER START (Optionally insert code for reacting on notification message)
                // USER END
                break;
                case WM_NOTIFICATION_RELEASED:
                // USER START (Optionally insert code for reacting on notification message)
                // USER END
                break;
                case WM_NOTIFICATION_MOVED_OUT:
                // USER START (Optionally insert code for reacting on notification message)
                // USER END
                break;
                case WM_NOTIFICATION_VALUE_CHANGED:
                // USER START (Optionally insert code for reacting on notification message)
                // USER END
                break;
                // USER START (Optionally insert additional code for further notification handling)
                // USER END
            }
            break;
    case ID_PS_BUTTON_START: // Notifications sent by 'btnStart'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        SweepRobot_PowerStationTestStartProc();
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_PS_BUTTON_SET: // Notifications sent by 'btnSet'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_PS_BUTTON_STOP: // Notifications sent by 'btnStop'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        SweepRobot_PowerStationTestStopProc();
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_PS_BUTTON_EXIT: // Notifications sent by 'btnExit'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        SweepRobot_PowerStationTestExitProc();
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_PS_CHECKBOX_LL: // Notifications sent by 'Checkbox'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_PS_CHECKBOX_LS: // Notifications sent by 'Checkbox'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_PS_CHECKBOX_L: // Notifications sent by 'Checkbox'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_PS_CHECKBOX_M: // Notifications sent by 'Checkbox'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_PS_CHECKBOX_R: // Notifications sent by 'Checkbox'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_PS_CHECKBOX_RS: // Notifications sent by 'Checkbox'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_PS_CHECKBOX_RL: // Notifications sent by 'Checkbox'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    // USER START (Optionally insert additional code for further Ids)
    // USER END
    }
    break;
  // USER START (Optionally insert additional message handling)
  // USER END
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
/*********************************************************************
*
*       CreateWindow
*/
WM_HWIN CreateEJE_SWRB_TEST_PowerStationDLG(void)
{
  WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
  return hWin;
}

// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/