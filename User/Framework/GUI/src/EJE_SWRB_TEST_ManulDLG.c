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
#include "sweeprobot_testing.h"
#include "DIALOG.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/

#define SWRB_MANUL_LISTVIEW_ROW_NUM   17

extern GUI_CONST_STORAGE GUI_BITMAP _bmTestNameCHN;
extern GUI_CONST_STORAGE GUI_BITMAP _bmLeftCHN;
extern GUI_CONST_STORAGE GUI_BITMAP _bmFrontLeftCHN;
extern GUI_CONST_STORAGE GUI_BITMAP _bmMiddleCHN;
extern GUI_CONST_STORAGE GUI_BITMAP _bmFrontRightCHN;
extern GUI_CONST_STORAGE GUI_BITMAP _bmRightCHN;
extern GUI_CONST_STORAGE GUI_BITMAP _bmBottomLeftCHN;
extern GUI_CONST_STORAGE GUI_BITMAP _bmBottomFrontLeftCHN;
extern GUI_CONST_STORAGE GUI_BITMAP _bmBottomFrontRightCHN;
extern GUI_CONST_STORAGE GUI_BITMAP _bmBottomRightCHN;

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

static const char *aButton_InitText[][1] = {
    {"WHEEL"},
    {"BRUSH"},
    {"FAN"},
    {"IFRD"},
    {"BUZZER"},
    {"RGB"},
    {"RELAY"},
};

static const char *aListview_RowInitText[][10] = {
/* item,left,frontLeft,middle,frontRight,right,bottomLeft,bottomFLeft,bottomFRight,bottomRight */
    {"WHEEL","0","","","","0"},
    {"BRUSH","0","","0","","0"},
    {"FAN","","","0","",""},
    {"IFRD","0","0","","0","0","0","0","0","0"},
    {"FRT IFRD","0","0","0","0","","0","0","0","0"},
    {"COLLISION","0","0","","0","0"},
    {"WHL_FLOAT","0","","","","0"},
    {"ASH_TRAY","0","0"},
    {"UNIWHEEL","0"},
    {"KEY","0"},
    {"IRDA","0","0","","0","0","0"},
    {"BUZZER","OFF"},
    {"RGB_LED","R","G","B"},
    {"CHARGE","0","0","0"},
    {"POWER","LL","LS","M","RS","RL","LB","RB","24V"},
    {"INT_VREF","0"},
    {"SNUM","0","0","0","0"},
};

//static u8 aListview_RowFlag[SWRB_MANUL_LISTVIEW_ROW_NUM] = { 0 };

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { WINDOW_CreateIndirect, "winSWRBManulTest", ID_MANUL_WINDOW_MAIN, 0, 0, 800, 480, 0, 0x0, 0 },
  { LISTVIEW_CreateIndirect, "lstviewSWRBTest", ID_MANUL_LISTVIEW_MAIN, 20, 10, 660, 375, 0, 0x0, 0 },
//  { TEXT_CreateIndirect, "textTitle", ID_MANUL_TEXT_TITLE, 20, 10, 655, 60, 0, 0x64, 0 },
  { EDIT_CreateIndirect, "editDate", ID_MANUL_EDIT_DATE, 510, 435, 170, 30, 0, 0x64, 0 },
  { BUTTON_CreateIndirect, "btnStart", ID_MANUL_BUTTON_START, 700, 0, 100, 120, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btnSet", ID_MANUL_BUTTON_SET, 700, 120, 100, 120, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btnReset", ID_MANUL_BUTTON_RESET, 700, 240, 100, 120, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btnExit", ID_MANUL_BUTTON_EXIT, 700, 360, 100, 120, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btnIndicate", ID_MANUL_BUTTON_INDICATE, 510, 400, 30, 30, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btnWheel", ID_MANUL_BUTTON_WHEEL, 20, 400, 60, 65, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btnBrush", ID_MANUL_BUTTON_BRUSH, 90, 400, 60, 65, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btnFan", ID_MANUL_BUTTON_FAN, 160, 400, 60, 65, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btnIFRD", ID_MANUL_BUTTON_IFRD, 230, 400, 60, 65, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btnBuzzer", ID_MANUL_BUTTON_BUZZER, 300, 400, 60, 65, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btnRGB", ID_MANUL_BUTTON_RGB_LED, 370, 400, 60, 65, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btnRelay", ID_MANUL_BUTTON_RELAY, 440, 400, 60, 65, 0, 0x0, 0 },
  { EDIT_CreateIndirect, "editVolt", ID_MANUL_EDIT_VOLT, 550, 400, 45, 30, 0, 0x64, 0 },
  { PROGBAR_CreateIndirect, "prgbVolt", ID_MANUL_PROGBAR_VOLT, 620, 400, 55, 30, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "textVolt", ID_MANUL_TEXT_VOLT, 590, 400, 30, 30, 0, 0x64, 0 },
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

static void Button_Init(WM_HWIN hItem)
{
    BUTTON_SetSkinClassic(hItem);
    BUTTON_SetFocussable(hItem, DISABLE);
    WIDGET_SetEffect(hItem, &WIDGET_Effect_None);
}

static void Listview_Init(WM_HWIN hItem)
{
    u8 i;
    HEADER_Handle hHeader;

    LISTVIEW_SetRowHeight(hItem, 20);
    LISTVIEW_SetFont(hItem, GUI_FONT_COMIC18B_ASCII);
    LISTVIEW_SetGridVis(hItem, 1);
    LISTVIEW_SetItemBkColor(hItem, 0, 0, LISTVIEW_CI_UNSEL, 0x00DFCFB3);
    LISTVIEW_SetItemBkColor(hItem, 0, 0, LISTVIEW_CI_UNSEL, 0x00FFFFFF);
    LISTVIEW_SetAutoScrollH(hItem, ENABLE);
    LISTVIEW_SetAutoScrollV(hItem, ENABLE);
    LISTVIEW_SetHeaderHeight(hItem, 30);

    LISTVIEW_AddColumn(hItem, 110, "", GUI_TA_HCENTER | GUI_TA_VCENTER);    //Item
    LISTVIEW_AddColumn(hItem, 45, "", GUI_TA_HCENTER | GUI_TA_VCENTER);     //Left
    LISTVIEW_AddColumn(hItem, 55, "", GUI_TA_HCENTER | GUI_TA_VCENTER);     //FrontLeft
    LISTVIEW_AddColumn(hItem, 60, "", GUI_TA_HCENTER | GUI_TA_VCENTER);     //Middle
    LISTVIEW_AddColumn(hItem, 55, "", GUI_TA_HCENTER | GUI_TA_VCENTER);     //FrontRight
    LISTVIEW_AddColumn(hItem, 45, "", GUI_TA_HCENTER | GUI_TA_VCENTER);     //Right
    LISTVIEW_AddColumn(hItem, 70, "", GUI_TA_HCENTER | GUI_TA_VCENTER);     //BottomLeft
    LISTVIEW_AddColumn(hItem, 70, "", GUI_TA_HCENTER | GUI_TA_VCENTER);     //BottomFrontLeft
    LISTVIEW_AddColumn(hItem, 70, "", GUI_TA_HCENTER | GUI_TA_VCENTER);     //BottomFrontRight
    LISTVIEW_AddColumn(hItem, 70, "", GUI_TA_HCENTER | GUI_TA_VCENTER);     //BottomRight
    for(i=0;i<SWRB_MANUL_LISTVIEW_ROW_NUM;i++){
        LISTVIEW_AddRow(hItem, aListview_RowInitText[i]);
    }

    hHeader = LISTVIEW_GetHeader(hItem);
    HEADER_SetFont(hHeader, GUI_FONT_COMIC18B_ASCII);
//    HEADER_SetSkinClassic(hHeader);
    HEADER_SetBitmapEx(hHeader, 0, &_bmTestNameCHN, 0, 0);
    HEADER_SetBitmapEx(hHeader, 1, &_bmLeftCHN, 0, 0);
    HEADER_SetBitmapEx(hHeader, 2, &_bmFrontLeftCHN, 0, 0);
    HEADER_SetBitmapEx(hHeader, 3, &_bmMiddleCHN, 0, 0);
    HEADER_SetBitmapEx(hHeader, 4, &_bmFrontRightCHN, 0, 0);
    HEADER_SetBitmapEx(hHeader, 5, &_bmRightCHN, 0, 0);
    HEADER_SetBitmapEx(hHeader, 6, &_bmBottomLeftCHN, 0, 0);
    HEADER_SetBitmapEx(hHeader, 7, &_bmBottomFrontLeftCHN, 0, 0);
    HEADER_SetBitmapEx(hHeader, 8, &_bmBottomFrontRightCHN, 0, 0);
    HEADER_SetBitmapEx(hHeader, 9, &_bmBottomRightCHN, 0, 0);
};

static void SWRB_MANUL_PAINT_Proc(void)
{
    GUI_SetColor(GUI_GRAY);
    GUI_DrawRect(669, 410, 675, 420);
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

    hItem = WM_GetDialogItem(pMsg->hWin, ID_MANUL_LISTVIEW_MAIN);
    Listview_Init(hItem);

    hItem = WM_GetDialogItem(pMsg->hWin, ID_MANUL_TEXT_TITLE);
    TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    TEXT_SetTextColor(hItem, 0x00CB8872);
    TEXT_SetText(hItem, "SWRB Manul Test");
    TEXT_SetFont(hItem, GUI_FONT_32B_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin, ID_MANUL_EDIT_DATE);
    EDIT_SetFont(hItem, GUI_FONT_20_ASCII);
    EDIT_SetText(hItem, "");
    EDIT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    EDIT_SetTextColor(hItem, EDIT_CI_ENABLED, GUI_BLUE);
    WIDGET_SetEffect(hItem, &WIDGET_Effect_None);

    hItem = WM_GetDialogItem(pMsg->hWin, ID_MANUL_EDIT_VOLT);
    EDIT_SetFont(hItem, GUI_FONT_20_ASCII);
    EDIT_SetTextAlign(hItem, GUI_TA_RIGHT | GUI_TA_VCENTER);
    EDIT_SetMaxLen(hItem, 5);
    EDIT_SetFloatMode(hItem, 0.0, 0, 20, 2, GUI_EDIT_NORMAL|GUI_EDIT_SUPPRESS_LEADING_ZEROES);
    EDIT_SetFloatValue(hItem, 0);
    WIDGET_SetEffect(hItem, &WIDGET_Effect_None);

    hItem = WM_GetDialogItem(pMsg->hWin, ID_MANUL_TEXT_VOLT);
    TEXT_SetFont(hItem, GUI_FONT_20_ASCII);
    TEXT_SetText(hItem, "V");
    TEXT_SetTextAlign(hItem, GUI_TA_LEFT | GUI_TA_VCENTER);

    hItem = WM_GetDialogItem(pMsg->hWin, ID_MANUL_BUTTON_START);
    Button_Init(hItem);
    BUTTON_DispStartCHNStr(pMsg->hWin, ID_MANUL_BUTTON_START, 18, 43);
    Button_Set_BkColor(pMsg->hWin, ID_MANUL_BUTTON_START, GUI_LIGHTBLUE);

    hItem = WM_GetDialogItem(pMsg->hWin, ID_MANUL_BUTTON_SET);
    Button_Init(hItem);
    if(gSwrbTestManulSubMode == SWRB_TEST_MANUL_SUB_MODE_AUTO)
        BUTTON_DispAutoModeCHNStr(pMsg->hWin, ID_MANUL_BUTTON_SET, 18, 43);
    else{
        BUTTON_DispManulModeCHNStr(pMsg->hWin, ID_MANUL_BUTTON_SET, 18, 43);
    }
    Button_Set_BkColor(pMsg->hWin, ID_MANUL_BUTTON_SET, GUI_LIGHTGREEN);

    hItem = WM_GetDialogItem(pMsg->hWin, ID_MANUL_BUTTON_RESET);
    Button_Init(hItem);
    BUTTON_DispResetCHNStr(pMsg->hWin, ID_MANUL_BUTTON_RESET, 18, 43);
    Button_Set_BkColor(pMsg->hWin, ID_MANUL_BUTTON_RESET, GUI_LIGHTRED);
    WM_DisableWindow(hItem);

    hItem = WM_GetDialogItem(pMsg->hWin, ID_MANUL_BUTTON_EXIT);
    Button_Init(hItem);
    BUTTON_DispExitCHNStr(pMsg->hWin, ID_MANUL_BUTTON_EXIT, 18, 43);
    Button_Set_BkColor(pMsg->hWin, ID_MANUL_BUTTON_EXIT, GUI_LIGHTGREEN);

    hItem = WM_GetDialogItem(pMsg->hWin, ID_MANUL_BUTTON_INDICATE);
    Button_Init(hItem);
    BUTTON_SetText(hItem, "");

    for(Id=ID_MANUL_BUTTON_WHEEL;Id<ID_MANUL_BUTTON_BOUND;Id++){
        hItem = WM_GetDialogItem(pMsg->hWin, Id);
        Button_Init(hItem);
        BUTTON_SetFont(hItem, GUI_FONT_16_ASCII);
        BUTTON_SetText(hItem, aButton_InitText[Id-ID_MANUL_BUTTON_WHEEL][0]);
        WM_DisableWindow(hItem);
    }

    WM_HideWin(pMsg->hWin);
    break;
  case WM_PAINT:
    SWRB_MANUL_PAINT_Proc();
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case ID_MANUL_BUTTON_START: // Notifications sent by 'btnStart'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        break;
      case WM_NOTIFICATION_RELEASED:
        SweepRobot_ManulStartBtnProc();
        break;
      }
      break;
    case ID_MANUL_BUTTON_SET: // Notifications sent by 'btnSet'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        break;
      case WM_NOTIFICATION_RELEASED:
        SweepRobot_ManulSetBtnProc();
        break;
      }
      break;
    case ID_MANUL_BUTTON_RESET: // Notifications sent by 'btnReset'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        break;
      case WM_NOTIFICATION_RELEASED:
        SweepRobot_ManulResetBtnProc();
        break;
      }
      break;
    case ID_MANUL_BUTTON_EXIT: // Notifications sent by 'btnExit'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        break;
      case WM_NOTIFICATION_RELEASED:
        SweepRobot_ManulExitBtnProc();
        break;
      }
      break;
    case ID_MANUL_LISTVIEW_MAIN: // Notifications sent by 'lstviewSWRBTest'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        break;
      case WM_NOTIFICATION_RELEASED:
        break;
      case WM_NOTIFICATION_SEL_CHANGED:
        break;
      }
      break;
    case ID_MANUL_EDIT_DATE: // Notifications sent by 'editDate'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        break;
      case WM_NOTIFICATION_RELEASED:
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        break;
      }
      break;
    case ID_MANUL_BUTTON_INDICATE: // Notifications sent by 'btnIndicate'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        break;
      case WM_NOTIFICATION_RELEASED:
        break;
      }
      break;
    case ID_MANUL_BUTTON_WHEEL: // Notifications sent by 'btnWheel'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        break;
      case WM_NOTIFICATION_RELEASED:
        SweepRobot_ManulWheelBtnProc();
        break;
      }
      break;
    case ID_MANUL_BUTTON_BRUSH: // Notifications sent by 'btnBrush'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        break;
      case WM_NOTIFICATION_RELEASED:
        SweepRobot_ManulBrushBtnProc();
        break;
      }
      break;
    case ID_MANUL_BUTTON_FAN: // Notifications sent by 'btnFan'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        break;
      case WM_NOTIFICATION_RELEASED:
        SweepRobot_ManulFanBtnProc();
        break;
      }
      break;
    case ID_MANUL_BUTTON_IFRD: // Notifications sent by 'btnIFRD'
        switch(NCode) {
          case WM_NOTIFICATION_CLICKED:
            break;
          case WM_NOTIFICATION_RELEASED:
            SweepRobot_ManulIFRDBtnProc();
            break;
        }
        break;
    case ID_MANUL_BUTTON_BUZZER: // Notifications sent by 'btnBuzzer'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        break;
      case WM_NOTIFICATION_RELEASED:
        SweepRobot_ManulBuzzerBtnProc();
        break;
      }
      break;
    case ID_MANUL_BUTTON_RGB_LED: // Notifications sent by 'btnRgbLed'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        break;
      case WM_NOTIFICATION_RELEASED:
        SweepRobot_ManulRGBLEDBtnProc();
        break;
      }
      break;
    case ID_MANUL_BUTTON_RELAY: // Notifications sent by 'btnRelay'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        break;
      case WM_NOTIFICATION_RELEASED:
        SweepRobot_ManulRELAYBtnProc();
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
WM_HWIN hWin_SWRB_MANUL;

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       CreateManulTestDLG
*/
WM_HWIN CreateManulTestDLG(void)
{
  WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
  return hWin;
}

/*************************** End of file ****************************/
