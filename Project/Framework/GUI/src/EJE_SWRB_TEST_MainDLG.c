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

#include "sweeprobot_testing_rgb_led.h"

#include "usart.h"
#include "led.h"


/*********************************************************************
*
*       Defines
*
**********************************************************************
*/

// USER START (Optionally insert additional defines)
WM_HWIN hWin_SWRB_MAIN;
WM_HWIN hWin_SWRB_RGB_LED;
WM_HWIN hWin_SWRB_BUZZER;

#define ID_IMAGE_0_IMAGE_0 0x00
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
//    { FRAMEWIN_CreateIndirect, "EJE_SweepRobot_test_System", ID_FRAMEWIN_MAIN, 0, 0, 800, 480, 0, 0x0, 0 },

    { WINDOW_CreateIndirect, "EJE_SWRB_TEST_SYSTEM", ID_WINDOW_MAIN, 0, 0, 800, 480, 0, 0x0, 0 },

//    { MULTIPAGE_CreateIndirect, "Multipage_Main", ID_MULTIPAGE_0, 0, 0, 800, 460, 0, 0x0, 0 },
    { MULTIEDIT_CreateIndirect, "Msg Multiedit",  ID_MULTIEDIT_MAIN, 10, 77, 440, 330, 0, 0x0, 0 },
    { PROGBAR_CreateIndirect,   "Progbar",        ID_PROGBAR_MAIN, 10, 442, 440, 20, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "START", ID_BUTTON_START, 700, 0, 100, 120, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SET",   ID_BUTTON_SET,  700, 120, 100, 120, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "STOP",  ID_BUTTON_STOP, 700, 240, 100, 120, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "EXIT",  ID_BUTTON_EXIT, 700, 360, 100, 120, 0, 0x0, 0 },
    { CHECKBOX_CreateIndirect,  "cbxWheel",       ID_CHECKBOX_WHEEL, 460, 17, 210, 25, 0, 0x0, 0 },
    { CHECKBOX_CreateIndirect,  "cbxBrush",       ID_CHECKBOX_BRUSH, 460, 52, 210, 25, 0, 0x0, 0 },
    { CHECKBOX_CreateIndirect,  "cbxFan",         ID_CHECKBOX_FAN, 460, 87, 210, 25, 0, 0x0, 0 },
    { CHECKBOX_CreateIndirect,  "cbxIFRD",        ID_CHECKBOX_IFRD, 460, 122, 210, 25, 0, 0x0, 0 },
    { CHECKBOX_CreateIndirect,  "cbxCollision",   ID_CHECKBOX_COLLISION, 460, 157, 210, 25, 0, 0x0, 0 },
    { CHECKBOX_CreateIndirect,  "cbxWheelFloat",  ID_CHECKBOX_WHEEL_FLOAT, 460, 192, 210, 25, 0, 0x0, 0 },
    { CHECKBOX_CreateIndirect,  "cbxAshTray",     ID_CHECKBOX_ASH_TRAY, 460, 227, 210, 25, 0, 0x0, 0 },
    { CHECKBOX_CreateIndirect,  "cbxUniWheel",    ID_CHECKBOX_UNIWHEEL, 460, 262, 210, 25, 0, 0x0, 0 },
    { CHECKBOX_CreateIndirect,  "cbxKey",         ID_CHECKBOX_KEY, 460, 297, 210, 25, 0, 0x0, 0 },
    { CHECKBOX_CreateIndirect,  "cbxIRDA",        ID_CHECKBOX_IRDA, 460, 332, 210, 25, 0, 0x0, 0 },
    { CHECKBOX_CreateIndirect,  "cbxBuzzer",      ID_CHECKBOX_BUZZER, 460, 367, 210, 25, 0, 0x0, 0 },
    { CHECKBOX_CreateIndirect,  "cbxRgbLed",      ID_CHECKBOX_RGB_LED, 460, 402, 210, 25, 0, 0x0, 0 },
    { CHECKBOX_CreateIndirect,  "cbxCharge",      ID_CHECKBOX_CHARGE, 460, 437, 210, 25, 0, 0x0, 0 },
//    { GRAPH_CreateIndirect, "Graph", ID_GRAPH_0, 10, 310, 440, 100, 0, 0x0, 0 },
    { EDIT_CreateIndirect, "EditU1", ID_EDIT_U1, 10, 17, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditU2", ID_EDIT_U2, 65, 17, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditU3", ID_EDIT_U3, 120, 17, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditU4", ID_EDIT_U4, 175, 17, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditU5", ID_EDIT_U5, 230, 17, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditU6", ID_EDIT_U6, 285, 17, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditU7", ID_EDIT_U7, 340, 17, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditU8", ID_EDIT_U8, 395, 17, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditD1", ID_EDIT_D1, 10, 47, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditD2", ID_EDIT_D2, 65, 47, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditD3", ID_EDIT_D3, 120, 47, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditD4", ID_EDIT_D4, 175, 47, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditD5", ID_EDIT_D5, 230, 47, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditD6", ID_EDIT_D6, 285, 47, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditD7", ID_EDIT_D7, 340, 47, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditD8", ID_EDIT_D8, 395, 47, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditSN", ID_EDIT_SN, 190, 407, 260, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditDate", ID_EDIT_DATE, 10, 407, 180, 30, 0, 0x64, 0 },
    // USER START (Optionally insert additional widgets)
    // USER END
};

static const GUI_WIDGET_CREATE_INFO _RgbLEDTestDialogCreate[] = {
    { FRAMEWIN_CreateIndirect, "RGB LED TEST", ID_FRAMEWIN_RGB_LED, 0, 0, 440, 210, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "OK", ID_BUTTON_RGB_LED_OK, 60, 100, 120, 60, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "ERROR",   ID_BUTTON_RGB_LED_ERR,  260, 100, 120, 60, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "RGB LED TEST", ID_TEXT_RGB_LED, 68, 17, 308, 65, 0, 0x64, 0 },
};

static const GUI_WIDGET_CREATE_INFO _BuzzerTestDialogCreate[] = {
    { FRAMEWIN_CreateIndirect, "BUZZER TEST", ID_FRAMEWIN_BUZZER, 0, 0, 440, 210, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "OK", ID_BUTTON_BUZZER_OK, 60, 100, 120, 60, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "ERROR",   ID_BUTTON_BUZZER_ERR,  260, 100, 120, 60, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "BUZZER TEST", ID_TEXT_BUZZER, 68, 17, 308, 65, 0, 0x64, 0 },
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

// USER START (Optionally insert additional static code)
static void Button_Init(WM_HWIN hItem)
{
    BUTTON_SetFont(hItem, GUI_FONT_24_ASCII);
    BUTTON_SetSkinClassic(hItem);
    BUTTON_SetFocussable(hItem, DISABLE);
    WIDGET_SetEffect(hItem, &WIDGET_Effect_None);
}
// USER END

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) {
    WM_HWIN hItem;
//    MULTIPAGE_Handle hMultipage;
    int     NCode;
    int     Id;
    u32     i;
    // USER START (Optionally insert additional variables)
    // USER END

  switch (pMsg->MsgId) {
    case WM_INIT_DIALOG:
    //
    // Initialization of 'START'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_START);
    Button_Init(hItem);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, GUI_LIGHTBLUE);
//    BUTTON_SetDefaultSkin(BUTTON_SKIN_FLEX);
    //
    // Initialization of 'SET'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SET);
    Button_Init(hItem);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, GUI_LIGHTCYAN);
    //
    // Initialization of 'STOP'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_STOP);
    Button_Init(hItem);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, GUI_LIGHTRED);
    //
    // Initialization of 'EXIT'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_EXIT);
    Button_Init(hItem);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, GUI_LIGHTGREEN);
//    //
//    // Initialization of "Multipage_Main"
//    //
//    hMultipage = WM_GetDialogItem(pMsg->hWin, ID_MULTIPAGE_MAIN);
//    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_START);
//    MULTIPAGE_AddEmptyPage(hMultipage, hItem, "TEST");
//    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_SET);
//    MULTIPAGE_AttachWindow(hMultipage, 0, hItem);
    //
    // Initialization of 'Msg Multiedit'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_MULTIEDIT_MAIN);
    MULTIEDIT_SetText(hItem, "Waiting for Start");
    MULTIEDIT_SetFont(hItem, GUI_FONT_16_ASCII);
    MULTIEDIT_SetAutoScrollV(hItem,1);
    MULTIEDIT_SetWrapWord(hItem);
    MULTIEDIT_SetBufferSize(hItem, 1024);
    //
    // Initialization of 'cbxWheel Test'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_WHEEL);
    CHECKBOX_SetText(hItem, "WHEEL");
    CHECKBOX_SetFont(hItem, GUI_FONT_20B_ASCII);
    CHECKBOX_SetDefaultSkin(CHECKBOX_SKIN_FLEX);
    //
    // Initialization of 'cbxSBrush Test'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_BRUSH);
    CHECKBOX_SetText(hItem, "BRUSH");
    CHECKBOX_SetFont(hItem, GUI_FONT_20B_ASCII);
    //
    // Initialization of 'cbxFan Test'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_FAN);
    CHECKBOX_SetText(hItem, "FAN");
    CHECKBOX_SetFont(hItem, GUI_FONT_20B_ASCII);
    //
    // Initialization of 'cbxIFRD Test'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_IFRD);
    CHECKBOX_SetText(hItem, "IFRD");
    CHECKBOX_SetFont(hItem, GUI_FONT_20B_ASCII);
    //
    // Initialization of 'cbxCollision Test'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_COLLISION);
    CHECKBOX_SetText(hItem, "COLLISION");
    CHECKBOX_SetFont(hItem, GUI_FONT_20B_ASCII);
    //
    // Initialization of 'cbxWheelFloat Test'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_WHEEL_FLOAT);
    CHECKBOX_SetText(hItem, "WHEEL FLOAT");
    CHECKBOX_SetFont(hItem, GUI_FONT_20B_ASCII);
    //
    // Initialization of 'cbxAshTray Test'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_ASH_TRAY);
    CHECKBOX_SetText(hItem, "ASH TRAY");
    CHECKBOX_SetFont(hItem, GUI_FONT_20B_ASCII);
    //
    // Initialization of 'cbxUniWheel Test'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_UNIWHEEL);
    CHECKBOX_SetText(hItem, "UNIWHEEL");
    CHECKBOX_SetFont(hItem, GUI_FONT_20B_ASCII);
    //
    // Initialization of 'cbxKey Test'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_KEY);
    CHECKBOX_SetText(hItem, "KEY");
    CHECKBOX_SetFont(hItem, GUI_FONT_20B_ASCII);
    //
    // Initialization of 'cbxIRDA Test'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_IRDA);
    CHECKBOX_SetText(hItem, "IRDA");
    CHECKBOX_SetFont(hItem, GUI_FONT_20B_ASCII);
    //
    // Initialization of 'cbxBuzzer Test'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_BUZZER);
    CHECKBOX_SetText(hItem, "BUZZER");
    CHECKBOX_SetFont(hItem, GUI_FONT_20B_ASCII);
    //
    // Initialization of 'cbxRgbLED Test'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_RGB_LED);
    CHECKBOX_SetText(hItem, "RGB LED");
    CHECKBOX_SetFont(hItem, GUI_FONT_20B_ASCII);
    //
    // Initialization of 'cbxCharge'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_CHARGE);
    CHECKBOX_SetText(hItem, "CHARGE");
    CHECKBOX_SetFont(hItem, GUI_FONT_20B_ASCII);
//    //
//    // Initialization of 'Graph'
//    //
//    hItem = WM_GetDialogItem(pMsg->hWin, ID_GRAPH_0);
//    GRAPH_SetBorder(hItem, 20, 5, 5, 5);
    //
    // Initialization of 'Edit'
    //
    for(i=ID_EDIT_U1;i<=ID_EDIT_D8;i++){
        hItem = WM_GetDialogItem(pMsg->hWin, i);
        EDIT_SetFont(hItem, &GUI_Font20_ASCII);
        EDIT_SetDecMode(hItem, 0, 0, 65536, 0, GUI_EDIT_NORMAL);
        EDIT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    }
    //
    // Initialization of 'EditDate'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_DATE);
    EDIT_SetFont(hItem, &GUI_Font20_ASCII);
    EDIT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    //
    // Initialization of 'EditSN'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_SN);
    EDIT_SetFont(hItem, &GUI_Font20_ASCII);
    EDIT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    //
    // Initialization of 'PROGBAR'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_PROGBAR_MAIN);
    PROGBAR_SetSkinClassic(hItem);
    WIDGET_SetEffect(hItem, &WIDGET_Effect_None);
//    PROGBAR_SetDefaultSkin(PROGBAR_SKIN_FLEX);

    // USER START (Optionally insert additional code for further widget initialization)
    // USER END
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case ID_BUTTON_START: // Notifications sent by 'START'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        SweepRobot_TestStartProc();
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_SET: // Notifications sent by 'SET'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        SweepRobot_TestSetProc();
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      
      // USER END
      }
      break;
    case ID_BUTTON_STOP: // Notifications sent by 'STOP'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        SweepRobot_TestStopProc();
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_EXIT: // Notifications sent by 'EXIT'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        SweepRobot_TestExitProc();
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_MULTIEDIT_MAIN: // Notifications sent by 'Msg Multiedit'
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
    case ID_CHECKBOX_WHEEL: // Notifications sent by 'cbxWheel Test'
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
        SWRB_TestCheckboxStateGet(pMsg->hWin, ID_CHECKBOX_WHEEL, SWRB_WHEEL_TEST_TASK_PRIO);
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_CHECKBOX_BRUSH: // Notifications sent by 'cbxBrush Test'
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
        SWRB_TestCheckboxStateGet(pMsg->hWin, ID_CHECKBOX_BRUSH, SWRB_BRUSH_TEST_TASK_PRIO);
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_CHECKBOX_FAN: // Notifications sent by 'cbxFan Test'
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
        SWRB_TestCheckboxStateGet(pMsg->hWin, ID_CHECKBOX_FAN, SWRB_FAN_TEST_TASK_PRIO);
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_CHECKBOX_IFRD: // Notifications sent by 'cbxIFRD Test'
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
        SWRB_TestCheckboxStateGet(pMsg->hWin, ID_CHECKBOX_IFRD, SWRB_IFRD_TEST_TASK_PRIO);
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_CHECKBOX_COLLISION: // Notifications sent by 'cbxCollision Test'
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
        SWRB_TestCheckboxStateGet(pMsg->hWin, ID_CHECKBOX_COLLISION, SWRB_COLLISION_TEST_TASK_PRIO);
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_CHECKBOX_WHEEL_FLOAT: // Notifications sent by 'cbxWheelFloat Test'
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
        SWRB_TestCheckboxStateGet(pMsg->hWin, ID_CHECKBOX_WHEEL_FLOAT, SWRB_WHEEL_FLOAT_TEST_TASK_PRIO);
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_CHECKBOX_ASH_TRAY: // Notifications sent by 'cbxAshTray Test'
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
        SWRB_TestCheckboxStateGet(pMsg->hWin, ID_CHECKBOX_ASH_TRAY, SWRB_ASH_TRAY_TEST_TASK_PRIO);
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_CHECKBOX_UNIWHEEL: // Notifications sent by 'cbxUniWheel Test'
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
        SWRB_TestCheckboxStateGet(pMsg->hWin, ID_CHECKBOX_UNIWHEEL, SWRB_UNIWHEEL_TEST_TASK_PRIO);
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_CHECKBOX_KEY: // Notifications sent by 'cbxKey Test'
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
        SWRB_TestCheckboxStateGet(pMsg->hWin, ID_CHECKBOX_KEY, SWRB_KEY_TEST_TASK_PRIO);
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_CHECKBOX_IRDA: // Notifications sent by 'cbxIRDA Test'
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
        SWRB_TestCheckboxStateGet(pMsg->hWin, ID_CHECKBOX_IRDA, SWRB_IRDA_TEST_TASK_PRIO);
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_CHECKBOX_BUZZER: // Notifications sent by 'cbxBuzzer Test'
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
        SWRB_TestCheckboxStateGet(pMsg->hWin, ID_CHECKBOX_BUZZER, SWRB_BUZZER_TEST_TASK_PRIO);
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_CHECKBOX_RGB_LED: // Notifications sent by 'cbxRgbLed Test'
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
        SWRB_TestCheckboxStateGet(pMsg->hWin, ID_CHECKBOX_RGB_LED, SWRB_RGB_LED_TEST_TASK_PRIO);
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_CHECKBOX_CHARGE: // Notifications sent by 'cbxCharge Test'
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
        SWRB_TestCheckboxStateGet(pMsg->hWin, ID_CHECKBOX_CHARGE, SWRB_CHARGE_TEST_TASK_PRIO);
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_EDIT_SN:
        switch(NCode){
            case WM_NOTIFICATION_CLICKED:
                break;
            case WM_NOTIFICATION_RELEASED:
                break;
            case WM_NOTIFICATION_VALUE_CHANGED:
                break;
        }
        break;
    case ID_PROGBAR_MAIN:
        switch(NCode) {
            case WM_NOTIFICATION_VALUE_CHANGED:

                break;
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

static void _cbRgbLedDialog(WM_MESSAGE * pMsg){
    WM_HWIN hItem;
    int     NCode;
    int     Id;
    u8      state;
    
    switch(pMsg->MsgId){
        case WM_INIT_DIALOG:
            
            hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_RGB_LED_OK);
            BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);

            hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_RGB_LED_ERR);
            BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
        
            hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_RGB_LED);
            TEXT_SetFont(hItem, GUI_FONT_32_ASCII);
            TEXT_SetText(hItem, "RGB LED TEST");
            TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
            TEXT_SetTextColor(hItem, 0x000000FF);
            
            break;
        case WM_NOTIFY_PARENT:
            Id    = WM_GetId(pMsg->hWinSrc);
            NCode = pMsg->Data.v;
            switch(Id) {
                case ID_BUTTON_RGB_LED_OK: // Notifications sent by 'RGB LED OK'
                    switch(NCode) {
                        case WM_NOTIFICATION_CLICKED:
                            
                            break;
                        case WM_NOTIFICATION_RELEASED:
                            state = RGB_LED_TestValidCntGet();
                            RGB_LED_TestRgbStateSet(state, 1);
                            if(state == 3)
                                WM_HideWin(pMsg->hWin);
                            OSTaskResume(gSwrbTestRuningTaskPrio);
                            break;
                    }
                    break;
                case ID_BUTTON_RGB_LED_ERR: // Notifications sent by 'RGB LED ERR'
                    switch(NCode) {
                        case WM_NOTIFICATION_CLICKED:
                            
                            break;
                        case WM_NOTIFICATION_RELEASED:
                            state = RGB_LED_TestValidCntGet();
                            RGB_LED_TestRgbStateSet(state, 0);
                            if(state == 3)
                                WM_HideWin(pMsg->hWin);
                            OSTaskResume(gSwrbTestRuningTaskPrio);
                            break;
                    }
                    break;
            }
        default:
            WM_DefaultProc(pMsg);
            break;
    }
}

static void _cbBuzzerDialog(WM_MESSAGE * pMsg){
    WM_HWIN hItem;
    int     NCode;
    int     Id;
    
    switch(pMsg->MsgId){
        case WM_INIT_DIALOG:

            //
            // Initialization of 'BUZZER FRAMEWIN'
            //
            hItem = WM_GetDialogItem(pMsg->hWin,ID_FRAMEWIN_BUZZER);
            WM_AttachWindowAt(hItem, hWin_SWRB_MAIN, 10, 77);
        
            break;
        case WM_NOTIFY_PARENT:
            Id    = WM_GetId(pMsg->hWinSrc);
            NCode = pMsg->Data.v;
            switch(Id) {
                case ID_BUTTON_RGB_LED_OK: // Notifications sent by 'RGB LED OK'
                    switch(NCode) {
                        case WM_NOTIFICATION_CLICKED:

                            break;
                        case WM_NOTIFICATION_RELEASED:

                            break;
                    }
                    break;
            }
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
*       CreateEJE_SweepRobot_test_System
*/
WM_HWIN CreateEJE_SweepRobot_test_System(void)
{
    WM_HWIN hWin;

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

WM_HWIN CreateRGB_LED_TestDLG(void)
{
    WM_HWIN hWin;

    hWin = GUI_CreateDialogBox(_RgbLEDTestDialogCreate, GUI_COUNTOF(_RgbLEDTestDialogCreate), _cbRgbLedDialog, WM_HBKWIN, 180, 135);
    return hWin;
}

WM_HWIN CreateBUZZER_TestDLG(void)
{
    WM_HWIN hWin;

    hWin = GUI_CreateDialogBox(_BuzzerTestDialogCreate, GUI_COUNTOF(_BuzzerTestDialogCreate), _cbBuzzerDialog, WM_HBKWIN, 180, 135);
    return hWin;
}

// USER START (Optionally insert additional public code)
void Button_Set_Text(int buttonId, char *str)
{
    WM_HWIN hItem;
    hItem = WM_GetDialogItem(hWin_SWRB_MAIN, buttonId);
    BUTTON_SetText(hItem, str);
}

void Button_Set_unPressedBkColor(WM_HWIN hWin, int buttonId, GUI_COLOR color)
{
    WM_HWIN hItem;
    hItem = WM_GetDialogItem(hWin, buttonId);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, color);
}

void Progbar_Set_Value(int progbarValue)
{
	WM_HWIN hItem;
	hItem = WM_GetDialogItem(hWin_SWRB_MAIN, ID_PROGBAR_0);
	PROGBAR_SetValue(hItem, progbarValue);
}

void Progbar_Set_Percent(u8 teststate)
{
    Progbar_Set_Value( (u8)( (float)(teststate) / (float)(SWRB_TEST_STATE_BOUND-2)*100) );
}

void Edit_Set_Value(int editId, long editValue)
{
    WM_HWIN hItem;
    hItem = WM_GetDialogItem(hWin_SWRB_MAIN, editId);
    EDIT_SetValue(hItem, editValue);
}

void Edit_Set_Text(WM_HWIN hWin, int editId, char *str)
{
    WM_HWIN hItem;
    hItem = WM_GetDialogItem(hWin, editId);
    EDIT_SetText(hItem, str);
}

void Edit_Clear(void)
{
    int i;
    
    for(i=ID_EDIT_1;i<ID_EDIT_SN;i++){
        Edit_Set_Value(i, 0);
    }
}

void Text_Set_Text(WM_HWIN hWin, int textId, char *str)
{
    WM_HWIN hItem;
    hItem = WM_GetDialogItem(hWin, textId);
    TEXT_SetText(hItem, str);
}
void Text_Set_Color(WM_HWIN hWin, int textId, GUI_COLOR color)
{
    WM_HWIN hItem;
    hItem = WM_GetDialogItem(hWin, textId);
    TEXT_SetTextColor(hItem, color);
}

void Checkbox_Set_Text(int checkboxId, char *string)
{
    WM_HWIN hItem;
    hItem = WM_GetDialogItem(hWin_SWRB_MAIN, checkboxId);
    CHECKBOX_SetText(hItem, string);
}

int Checkbox_Get_State(int checkboxId)
{
    WM_HWIN hItem;
    hItem = WM_GetDialogItem(hWin_SWRB_MAIN, checkboxId);
    return(CHECKBOX_GetState(hItem));
}

void SWRB_TestCheckboxStateGet(WM_HWIN hWin, int id, int taskPrio){
    WM_HWIN hItem;
    hItem = WM_GetDialogItem(hWin, id);
    if(gSwrbTestMode == SWRB_TEST_MODE_IDLE){
        if(CHECKBOX_GetState(hItem)){
            gSwrbTestValidTaskCnt++;
        }else{
            gSwrbTestValidTaskCnt--;
        }
    }
}

void Checkbox_Set_State(int checkboxId, unsigned int checkboxState)
{
    WM_HWIN hItem;
    hItem = WM_GetDialogItem(hWin_SWRB_MAIN, checkboxId);
    CHECKBOX_SetState(hItem, checkboxState);
}

void Checkbox_Set_Text_Color(int checkboxId, GUI_COLOR checkboxtextcolor)
{
    WM_HWIN hItem;
    hItem = WM_GetDialogItem(hWin_SWRB_MAIN, checkboxId);
    CHECKBOX_SetTextColor(hItem, checkboxtextcolor);
}

void Checkbox_Set_TextAlign(int checkboxId, int align)
{
    WM_HWIN hItem;
    hItem = WM_GetDialogItem(hWin_SWRB_MAIN, checkboxId);
    CHECKBOX_SetTextAlign(hItem, align);
}

void Checkbox_Set_Back_Color(int checkboxId, GUI_COLOR checkboxbkcolor)
{
    WM_HWIN hItem;
    hItem = WM_GetDialogItem(hWin_SWRB_MAIN, checkboxId);
    CHECKBOX_SetBkColor(hItem, checkboxbkcolor);
}

void Checkbox_Set_Box_Back_Color(int checkboxId, GUI_COLOR boxBkColor, int Index)
{
    WM_HWIN hItem;
    hItem = WM_GetDialogItem(hWin_SWRB_MAIN, checkboxId);
    CHECKBOX_SetBoxBkColor(hItem, boxBkColor, Index);
}

void MULTIEDIT_Set_Buffer_Size(int size)
{
    WM_HWIN hItem;
    
    hItem = WM_GetDialogItem(hWin_SWRB_MAIN, ID_MULTIEDIT_MAIN);
    MULTIEDIT_SetBufferSize(hItem, size);
}

void MultiEdit_Set_Text(char *s)
{
	WM_HWIN hItem;
	hItem = WM_GetDialogItem(hWin_SWRB_MAIN, ID_MULTIEDIT_0);
	MULTIEDIT_SetText(hItem, s);
}

void MultiEdit_Add_Text(char *s)
{
    WM_HWIN hItem;
    hItem = WM_GetDialogItem(hWin_SWRB_MAIN, ID_MULTIEDIT_0);
    MULTIEDIT_AddText(hItem, s);
}

void MultiEdit_Set_Text_Color(GUI_COLOR multieditTextColor)
{
    WM_HWIN hItem;
    hItem = WM_GetDialogItem(hWin_SWRB_MAIN, ID_MULTIEDIT_0);
    MULTIEDIT_SetTextColor(hItem, MULTIEDIT_CI_EDIT, multieditTextColor);
}

GRAPH_DATA_Handle Graph_Data_YT_Create(GUI_COLOR color, u32 maxNumItems, int16_t *pData, u32 numItems)
{
    GRAPH_DATA_Handle hGraphData;
    hGraphData = GRAPH_DATA_YT_Create(color, maxNumItems, pData, numItems);
    return hGraphData;
}


// USER END

/*************************** End of file ****************************/
