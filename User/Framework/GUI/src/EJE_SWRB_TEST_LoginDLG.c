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

#include "EJE_SWRB_TEST_DLG_Conf.h"

#include "EJE_SWRB_TEST_LoginDLG.h"

#include "sweeprobot_testing.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/

// USER START (Optionally insert additional defines)
// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

// USER START (Optionally insert additional static data)
// USER END

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { FRAMEWIN_CreateIndirect, "fwinLogin", ID_LOGIN_FRAMEWIN_MAIN, 0, 0, 440, 210, 0, 0x64, 0 },
  { BUTTON_CreateIndirect, "btnLoginOK", ID_LOGIN_BUTTON_OK, 260, 40, 120, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btnLoginCancel", ID_LOGIN_BUTTON_CANCEL, 260, 110, 120, 40, 0, 0x0, 0 },
  { EDIT_CreateIndirect, "Edit", ID_LOGIN_EDIT_PASSWORD, 50, 90, 150, 40, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "Text", ID_LOGIN_TEXT_PASSWORD, 30, 40, 200, 40, 0, 0x64, 0 },
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
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;
  int     NCode;
  int     Id;
  // USER START (Optionally insert additional variables)
  // USER END

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
    //
    // Initialization of 'fwinLogin'
    //
    hItem = pMsg->hWin;
    FRAMEWIN_SetText(hItem, "Login");
    //
    // Initialization of 'btnLoginOK'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_LOGIN_BUTTON_OK);
    BUTTON_SetFont(hItem, GUI_FONT_20_ASCII);
    BUTTON_SetText(hItem, "OK");
    //
    // Initialization of 'btnLoginCancel'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_LOGIN_BUTTON_CANCEL);
    BUTTON_SetFont(hItem, GUI_FONT_20_ASCII);
    BUTTON_SetText(hItem, "Cancel");
    //
    // Initialization of 'Edit'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_LOGIN_EDIT_PASSWORD);
    EDIT_SetText(hItem, "******");
    EDIT_SetFont(hItem, GUI_FONT_24_ASCII);
    EDIT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    EDIT_SetBkColor(hItem, EDIT_CI_ENABELD, GUI_WHITE);
    EDIT_SetMaxLen(hItem, 10);
    //
    // Initialization of 'Text'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_LOGIN_TEXT_PASSWORD);
    TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    TEXT_SetFont(hItem, GUI_FONT_20_ASCII);
    TEXT_SetText(hItem, "Please input Password");
    /* Hide Window when create */
    WM_HideWin(pMsg->hWin);
    // USER START (Optionally insert additional code for further widget initialization)
    // USER END
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case ID_LOGIN_BUTTON_OK: // Notifications sent by 'btnLoginOK'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        break;
      case WM_NOTIFICATION_RELEASED:
        SweepRobot_PCBTestLoginOKProc();
        break;
      }
      break;
    case ID_LOGIN_BUTTON_CANCEL: // Notifications sent by 'btnLoginCancel'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        break;
      case WM_NOTIFICATION_RELEASED:
        SweepRobot_PCBTestLoginCancelProc();
        break;
      }
      break;
    case ID_LOGIN_EDIT_PASSWORD: // Notifications sent by 'Edit'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        break;
      case WM_NOTIFICATION_RELEASED:
        SweepRobot_PCBTestLoginEditProc(pMsg);
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
*       Public data
*
**********************************************************************
*/

WM_HWIN hWin_SWRB_LOGIN;

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       CreateLoginDLG
*/
WM_HWIN CreateLoginDLG(void) {
  WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, hWin_SWRB_PCBTEST, 180, 135);
  return hWin;
}

// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/