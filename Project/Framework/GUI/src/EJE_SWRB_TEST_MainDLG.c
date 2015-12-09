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

#include "sweeprobot_testing.h"
#include "sweeprobot_testing_rgb_led.h"
#include "sweeprobot_testing_buzzer.h"

#include "usart.h"
#include "led.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/

#define ID_IMAGE_0_IMAGE_0 0x00

extern GUI_CONST_STORAGE GUI_BITMAP _bmStartCHN;
extern GUI_CONST_STORAGE GUI_BITMAP _bmPauseCHN;
extern GUI_CONST_STORAGE GUI_BITMAP _bmResumeCHN;
extern GUI_CONST_STORAGE GUI_BITMAP _bmSetCHN;
extern GUI_CONST_STORAGE GUI_BITMAP _bmStopCHN;
extern GUI_CONST_STORAGE GUI_BITMAP _bmExitCHN;
extern GUI_CONST_STORAGE GUI_BITMAP _bmConfirmCHN;
extern GUI_CONST_STORAGE GUI_BITMAP _bmCheckCHN;
extern GUI_CONST_STORAGE GUI_BITMAP _bmResetCHN;
extern GUI_CONST_STORAGE GUI_BITMAP _bmCancelCHN;
extern GUI_CONST_STORAGE GUI_BITMAP _bmSerialNumCHN;
extern GUI_CONST_STORAGE GUI_BITMAP _bmTimeCHN;

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

WM_HWIN hWin_SWRB_MAIN;
WM_HWIN hWin_SWRB_RGB_LED;
WM_HWIN hWin_SWRB_BUZZER;

static u8 gMainDLGIndicateFlag = 0;

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
//    { FRAMEWIN_CreateIndirect, "EJE_SweepRobot_test_System", ID_FRAMEWIN_MAIN, 0, 0, 800, 480, 0, 0x0, 0 },
    { WINDOW_CreateIndirect, "EJE_SWRB_TEST_SYSTEM", ID_MAIN_WINDOW_MAIN, 0, 0, 800, 480, 0, 0x0, 0 },
//    { MULTIPAGE_CreateIndirect, "Multipage_Main", ID_MAIN_MULTIPAGE_0, 0, 0, 800, 460, 0, 0x0, 0 },
    { MULTIEDIT_CreateIndirect, "Msg Multiedit",  ID_MAIN_MULTIEDIT_MAIN, 10, 77, 440, 330, 0, 0x0, 0 },
    { PROGBAR_CreateIndirect,   "Progbar",        ID_MAIN_PROGBAR_MAIN, 10, 442, 440, 20, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "START", ID_MAIN_BUTTON_START, 700, 0, 100, 120, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SET",   ID_MAIN_BUTTON_SET,  700, 120, 100, 120, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SET SN",  ID_MAIN_BUTTON_SET_SN, 500, 120, 100, 60, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SET TIME",  ID_MAIN_BUTTON_SET_TIME, 600, 180, 100, 60, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "STOP",  ID_MAIN_BUTTON_STOP, 700, 240, 100, 120, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "EXIT",  ID_MAIN_BUTTON_EXIT, 700, 360, 100, 120, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, " ",  ID_MAIN_BUTTON_INDICATE, 420, 407, 30, 30, 0, 0x0, 0 },
    { CHECKBOX_CreateIndirect,  "cbxWheel",       ID_MAIN_CHECKBOX_WHEEL, 460, 17, 210, 25, 0, 0x0, 0 },
    { CHECKBOX_CreateIndirect,  "cbxBrush",       ID_MAIN_CHECKBOX_BRUSH, 460, 52, 210, 25, 0, 0x0, 0 },
    { CHECKBOX_CreateIndirect,  "cbxFan",         ID_MAIN_CHECKBOX_FAN, 460, 87, 210, 25, 0, 0x0, 0 },
    { CHECKBOX_CreateIndirect,  "cbxIFRD",        ID_MAIN_CHECKBOX_IFRD, 460, 122, 210, 25, 0, 0x0, 0 },
    { CHECKBOX_CreateIndirect,  "cbxCollision",   ID_MAIN_CHECKBOX_COLLISION, 460, 157, 210, 25, 0, 0x0, 0 },
    { CHECKBOX_CreateIndirect,  "cbxWheelFloat",  ID_MAIN_CHECKBOX_WHEEL_FLOAT, 460, 192, 210, 25, 0, 0x0, 0 },
    { CHECKBOX_CreateIndirect,  "cbxAshTray",     ID_MAIN_CHECKBOX_ASH_TRAY, 460, 227, 210, 25, 0, 0x0, 0 },
    { CHECKBOX_CreateIndirect,  "cbxUniWheel",    ID_MAIN_CHECKBOX_UNIWHEEL, 460, 262, 210, 25, 0, 0x0, 0 },
    { CHECKBOX_CreateIndirect,  "cbxKey",         ID_MAIN_CHECKBOX_KEY, 460, 297, 210, 25, 0, 0x0, 0 },
    { CHECKBOX_CreateIndirect,  "cbxIRDA",        ID_MAIN_CHECKBOX_IRDA, 460, 332, 210, 25, 0, 0x0, 0 },
    { CHECKBOX_CreateIndirect,  "cbxBuzzer",      ID_MAIN_CHECKBOX_BUZZER, 460, 367, 210, 25, 0, 0x0, 0 },
    { CHECKBOX_CreateIndirect,  "cbxRgbLed",      ID_MAIN_CHECKBOX_RGB_LED, 460, 402, 210, 25, 0, 0x0, 0 },
    { CHECKBOX_CreateIndirect,  "cbxCharge",      ID_MAIN_CHECKBOX_CHARGE, 460, 437, 210, 25, 0, 0x0, 0 },
//    { GRAPH_CreateIndirect, "Graph", ID_MAIN_GRAPH_0, 10, 310, 440, 100, 0, 0x0, 0 },
    { EDIT_CreateIndirect, "EditU1", ID_MAIN_EDIT_U1, 10, 17, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditU2", ID_MAIN_EDIT_U2, 65, 17, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditU3", ID_MAIN_EDIT_U3, 120, 17, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditU4", ID_MAIN_EDIT_U4, 175, 17, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditU5", ID_MAIN_EDIT_U5, 230, 17, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditU6", ID_MAIN_EDIT_U6, 285, 17, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditU7", ID_MAIN_EDIT_U7, 340, 17, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditU8", ID_MAIN_EDIT_U8, 395, 17, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditD1", ID_MAIN_EDIT_D1, 10, 47, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditD2", ID_MAIN_EDIT_D2, 65, 47, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditD3", ID_MAIN_EDIT_D3, 120, 47, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditD4", ID_MAIN_EDIT_D4, 175, 47, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditD5", ID_MAIN_EDIT_D5, 230, 47, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditD6", ID_MAIN_EDIT_D6, 285, 47, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditD7", ID_MAIN_EDIT_D7, 340, 47, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditD8", ID_MAIN_EDIT_D8, 395, 47, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditSN", ID_MAIN_EDIT_SN, 190, 407, 230, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditDate", ID_MAIN_EDIT_DATE, 10, 407, 180, 30, 0, 0x64, 0 },
};

static const GUI_WIDGET_CREATE_INFO _RgbLEDTestDialogCreate[] = {
    { FRAMEWIN_CreateIndirect, "RGB LED TEST", ID_MAIN_FRAMEWIN_RGB_LED, 0, 0, 440, 210, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "OK", ID_MAIN_BUTTON_RGB_LED_OK, 60, 100, 120, 60, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "ERROR",   ID_MAIN_BUTTON_RGB_LED_ERR,  260, 100, 120, 60, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "RGB LED TEST", ID_MAIN_TEXT_RGB_LED, 68, 17, 308, 65, 0, 0x64, 0 },
};

static const GUI_WIDGET_CREATE_INFO _BuzzerTestDialogCreate[] = {
    { FRAMEWIN_CreateIndirect, "BUZZER TEST", ID_MAIN_FRAMEWIN_BUZZER, 0, 0, 440, 210, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "OK", ID_MAIN_BUTTON_BUZZER_OK, 60, 100, 120, 60, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "ERROR",   ID_MAIN_BUTTON_BUZZER_ERR,  260, 100, 120, 60, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "BUZZER TEST", ID_MAIN_TEXT_BUZZER, 68, 17, 308, 65, 0, 0x64, 0 },
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

static void Button_Init(WM_HWIN hItem)
{
    BUTTON_SetFont(hItem, GUI_FONT_24_ASCII);
    BUTTON_SetSkinClassic(hItem);
    BUTTON_SetFocussable(hItem, DISABLE);
    WIDGET_SetEffect(hItem, &WIDGET_Effect_None);
}

static void Checkbox_Init(WM_HWIN hItem)
{
    CHECKBOX_SetFont(hItem, GUI_FONT_20B_ASCII);
    WIDGET_SetEffect(hItem, &WIDGET_Effect_Simple);
}

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) 
{
    WM_HWIN hItem;
    int     NCode;
    int     Id;
    u32     i;

    switch (pMsg->MsgId) {
        case WM_INIT_DIALOG:
            //
            // Initialization of 'START'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_MAIN_BUTTON_START);
            Button_Init(hItem);
            BUTTON_SetText(hItem, " ");
            BUTTON_Set_Bitmap_Ex(pMsg->hWin, ID_MAIN_BUTTON_START, &_bmStartCHN, 18, 43);
            BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, GUI_LIGHTBLUE);
            BUTTON_SetBkColor(hItem, BUTTON_CI_PRESSED, GUI_LIGHTBLUE);
            //
            // Initialization of 'SET'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_MAIN_BUTTON_SET);
            Button_Init(hItem);
            BUTTON_SetText(hItem, " ");
            BUTTON_Set_Bitmap_Ex(pMsg->hWin, ID_MAIN_BUTTON_SET, &_bmSetCHN, 18, 43);
            BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, GUI_LIGHTCYAN);
            //
            // Initialization of 'SET SN'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_MAIN_BUTTON_SET_SN);
            Button_Init(hItem);
            BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, GUI_LIGHTCYAN);
            WM_HideWin(hItem);
            //
            // Initialization of 'SET TIME'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_MAIN_BUTTON_SET_TIME);
            Button_Init(hItem);
            BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, GUI_LIGHTCYAN);
            BUTTON_SetBkColor(hItem, BUTTON_CI_PRESSED, GUI_LIGHTCYAN);
            WM_HideWin(hItem);
            //
            // Initialization of 'STOP'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_MAIN_BUTTON_STOP);
            Button_Init(hItem);
            BUTTON_SetText(hItem, " ");
            BUTTON_Set_Bitmap_Ex(pMsg->hWin, ID_MAIN_BUTTON_STOP, &_bmStopCHN, 18, 43);
            BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, GUI_LIGHTRED);
            BUTTON_SetBkColor(hItem, BUTTON_CI_PRESSED, GUI_LIGHTRED);
            //
            // Initialization of 'EXIT'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_MAIN_BUTTON_EXIT);
            Button_Init(hItem);
            BUTTON_SetText(hItem, " ");
            BUTTON_Set_Bitmap_Ex(pMsg->hWin, ID_MAIN_BUTTON_EXIT, &_bmExitCHN, 18, 43);
            BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, GUI_LIGHTGREEN);
            BUTTON_SetBkColor(hItem, BUTTON_CI_PRESSED, GUI_LIGHTGREEN);
            //
            // Initialization of 'Indicate'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_MAIN_BUTTON_INDICATE);
            WM_BringToTop(hItem);
            BUTTON_SetSkinClassic(hItem);
            WIDGET_SetEffect(hItem, &WIDGET_Effect_Simple);
            Button_Set_unPressedBkColor(hWin_SWRB_MAIN,ID_MAIN_BUTTON_INDICATE, GUI_LIGHTGRAY);
            Button_Set_Text(hWin_SWRB_MAIN, ID_MAIN_BUTTON_INDICATE, " ");
            BUTTON_SetFocussable(hItem, 0);
            //
            // Initialization of 'Msg Multiedit'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_MAIN_MULTIEDIT_MAIN);
            MULTIEDIT_SetText(hItem, "Waiting for Start");
            MULTIEDIT_SetFont(hItem, GUI_FONT_16_ASCII);
            MULTIEDIT_SetAutoScrollV(hItem,1);
            MULTIEDIT_SetWrapWord(hItem);
            MULTIEDIT_SetBufferSize(hItem, 2048);
            WM_DisableWindow(hItem);
            //
            // Initialization of 'cbxWheel Test'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_MAIN_CHECKBOX_WHEEL);
            CHECKBOX_SetText(hItem, "WHEEL");
            CHECKBOX_SetDefaultSkinClassic();
            Checkbox_Init(hItem);
            //
            // Initialization of 'cbxSBrush Test'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_MAIN_CHECKBOX_BRUSH);
            CHECKBOX_SetText(hItem, "BRUSH");
            Checkbox_Init(hItem);
            //
            // Initialization of 'cbxFan Test'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_MAIN_CHECKBOX_FAN);
            CHECKBOX_SetText(hItem, "FAN");
            Checkbox_Init(hItem);
            //
            // Initialization of 'cbxIFRD Test'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_MAIN_CHECKBOX_IFRD);
            CHECKBOX_SetText(hItem, "IFRD");
            Checkbox_Init(hItem);
            //
            // Initialization of 'cbxCollision Test'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_MAIN_CHECKBOX_COLLISION);
            CHECKBOX_SetText(hItem, "COLLISION");
            Checkbox_Init(hItem);
            //
            // Initialization of 'cbxWheelFloat Test'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_MAIN_CHECKBOX_WHEEL_FLOAT);
            CHECKBOX_SetText(hItem, "WHEEL FLOAT");
            Checkbox_Init(hItem);
            //
            // Initialization of 'cbxAshTray Test'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_MAIN_CHECKBOX_ASH_TRAY);
            CHECKBOX_SetText(hItem, "ASH TRAY");
            Checkbox_Init(hItem);
            //
            // Initialization of 'cbxUniWheel Test'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_MAIN_CHECKBOX_UNIWHEEL);
            CHECKBOX_SetText(hItem, "UNIWHEEL");
            Checkbox_Init(hItem);
            //
            // Initialization of 'cbxKey Test'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_MAIN_CHECKBOX_KEY);
            CHECKBOX_SetText(hItem, "KEY");
            Checkbox_Init(hItem);
            //
            // Initialization of 'cbxIRDA Test'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_MAIN_CHECKBOX_IRDA);
            CHECKBOX_SetText(hItem, "IRDA");
            Checkbox_Init(hItem);
            //
            // Initialization of 'cbxBuzzer Test'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_MAIN_CHECKBOX_BUZZER);
            CHECKBOX_SetText(hItem, "BUZZER");
            Checkbox_Init(hItem);
            //
            // Initialization of 'cbxRgbLED Test'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_MAIN_CHECKBOX_RGB_LED);
            CHECKBOX_SetText(hItem, "RGB LED");
            Checkbox_Init(hItem);
            //
            // Initialization of 'cbxCharge'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_MAIN_CHECKBOX_CHARGE);
            CHECKBOX_SetText(hItem, "CHARGE");
            Checkbox_Init(hItem);
            //
            // Initialization of 'Edit'
            //
            for(i=ID_MAIN_EDIT_U1;i<=ID_MAIN_EDIT_D8;i++){
                hItem = WM_GetDialogItem(pMsg->hWin, i);
                EDIT_SetFont(hItem, &GUI_Font20_ASCII);
                EDIT_SetDecMode(hItem, 0, 0, 65536, 0, GUI_EDIT_SUPPRESS_LEADING_ZEROES);
                EDIT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
            }
            //
            // Initialization of 'EditDate'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_MAIN_EDIT_DATE);
            EDIT_SetFont(hItem, &GUI_Font20_ASCII);
            EDIT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
            //
            // Initialization of 'EditSN'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_MAIN_EDIT_SN);
            EDIT_SetFont(hItem, &GUI_Font20_ASCII);
            EDIT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
            //
            // Initialization of 'PROGBAR'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_MAIN_PROGBAR_MAIN);
            PROGBAR_SetSkinClassic(hItem);
            WIDGET_SetEffect(hItem, &WIDGET_Effect_None);

            WM_HideWin(pMsg->hWin);
            break;
        case WM_NOTIFY_PARENT:
            Id    = WM_GetId(pMsg->hWinSrc);
            NCode = pMsg->Data.v;
            switch(Id) {
            case ID_MAIN_BUTTON_START: // Notifications sent by 'START'
                switch(NCode) {
                    case WM_NOTIFICATION_CLICKED:
                        break;
                    case WM_NOTIFICATION_RELEASED:
                        SweepRobot_PCBTestStartProc();
                        break;
                }
                break;
            case ID_MAIN_BUTTON_SET: // Notifications sent by 'SET'
                switch(NCode) {
                    case WM_NOTIFICATION_CLICKED:
                        break;
                    case WM_NOTIFICATION_RELEASED:
                        SweepRobot_PCBTestSetProc();
                        break;
                }
                break;
            case ID_MAIN_BUTTON_SET_SN:
                switch(NCode) {
                    case WM_NOTIFICATION_CLICKED:
                        break;
                    case WM_NOTIFICATION_RELEASED:
//                        SweepRobot_PCBTestSetProc();
                        break;
                }
                break;
            case ID_MAIN_BUTTON_STOP: // Notifications sent by 'STOP'
                switch(NCode) {
                    case WM_NOTIFICATION_CLICKED:
                        break;
                    case WM_NOTIFICATION_RELEASED:
                        SweepRobot_PCBTestStopProc();
                        break;
                }
                break;
            case ID_MAIN_BUTTON_EXIT: // Notifications sent by 'EXIT'
                switch(NCode) {
                    case WM_NOTIFICATION_CLICKED:
                        break;
                    case WM_NOTIFICATION_RELEASED:
                        SweepRobot_PCBTestExitProc();
                        break;
                }
                break;
            case ID_MAIN_MULTIEDIT_MAIN: // Notifications sent by 'Msg Multiedit'
                switch(NCode) {
                    case WM_NOTIFICATION_CLICKED:
                        break;
                    case WM_NOTIFICATION_RELEASED:
                        break;
                    case WM_NOTIFICATION_VALUE_CHANGED:
                        break;
                }
                break;
            case ID_MAIN_CHECKBOX_WHEEL: // Notifications sent by 'cbxWheel Test'
                switch(NCode) {
                    case WM_NOTIFICATION_CLICKED:
                        break;
                    case WM_NOTIFICATION_RELEASED:
                        break;
                    case WM_NOTIFICATION_VALUE_CHANGED:
                        SWRB_TestCheckboxStateGet(pMsg->hWin, ID_MAIN_CHECKBOX_WHEEL, SWRB_WHEEL_TEST_TASK_PRIO);
                        break;
                }
                break;
            case ID_MAIN_CHECKBOX_BRUSH: // Notifications sent by 'cbxBrush Test'
                switch(NCode) {
                    case WM_NOTIFICATION_CLICKED:
                        break;
                    case WM_NOTIFICATION_RELEASED:
                        break;
                    case WM_NOTIFICATION_VALUE_CHANGED:
                        SWRB_TestCheckboxStateGet(pMsg->hWin, ID_MAIN_CHECKBOX_BRUSH, SWRB_BRUSH_TEST_TASK_PRIO);
                        break;
                }
                break;
            case ID_MAIN_CHECKBOX_FAN: // Notifications sent by 'cbxFan Test'
                switch(NCode) {
                    case WM_NOTIFICATION_CLICKED:
                        break;
                    case WM_NOTIFICATION_RELEASED:
                        break;
                    case WM_NOTIFICATION_VALUE_CHANGED:
                        SWRB_TestCheckboxStateGet(pMsg->hWin, ID_MAIN_CHECKBOX_FAN, SWRB_FAN_TEST_TASK_PRIO);
                        break;
                }
                break;
            case ID_MAIN_CHECKBOX_IFRD: // Notifications sent by 'cbxIFRD Test'
                switch(NCode) {
                    case WM_NOTIFICATION_CLICKED:
                        break;
                    case WM_NOTIFICATION_RELEASED:
                        break;
                    case WM_NOTIFICATION_VALUE_CHANGED:
                        SWRB_TestCheckboxStateGet(pMsg->hWin, ID_MAIN_CHECKBOX_IFRD, SWRB_IFRD_TEST_TASK_PRIO);
                        break;
                }
                break;
            case ID_MAIN_CHECKBOX_COLLISION: // Notifications sent by 'cbxCollision Test'
                switch(NCode) {
                    case WM_NOTIFICATION_CLICKED:
                        break;
                    case WM_NOTIFICATION_RELEASED:
                        break;
                    case WM_NOTIFICATION_VALUE_CHANGED:
                        SWRB_TestCheckboxStateGet(pMsg->hWin, ID_MAIN_CHECKBOX_COLLISION, SWRB_COLLISION_TEST_TASK_PRIO);
                        break;
                }
                break;
            case ID_MAIN_CHECKBOX_WHEEL_FLOAT: // Notifications sent by 'cbxWheelFloat Test'
                switch(NCode) {
                    case WM_NOTIFICATION_CLICKED:
                        break;
                    case WM_NOTIFICATION_RELEASED:
                            break;
                    case WM_NOTIFICATION_VALUE_CHANGED:
                        SWRB_TestCheckboxStateGet(pMsg->hWin, ID_MAIN_CHECKBOX_WHEEL_FLOAT, SWRB_WHEEL_FLOAT_TEST_TASK_PRIO);
                        break;
                }
                break;
            case ID_MAIN_CHECKBOX_ASH_TRAY: // Notifications sent by 'cbxAshTray Test'
                switch(NCode) {
                    case WM_NOTIFICATION_CLICKED:
                        break;
                    case WM_NOTIFICATION_RELEASED:
                        break;
                    case WM_NOTIFICATION_VALUE_CHANGED:
                        SWRB_TestCheckboxStateGet(pMsg->hWin, ID_MAIN_CHECKBOX_ASH_TRAY, SWRB_ASH_TRAY_TEST_TASK_PRIO);
                        break;
                }
                break;
            case ID_MAIN_CHECKBOX_UNIWHEEL: // Notifications sent by 'cbxUniWheel Test'
                switch(NCode) {
                    case WM_NOTIFICATION_CLICKED:
                        break;
                    case WM_NOTIFICATION_RELEASED:
                        break;
                    case WM_NOTIFICATION_VALUE_CHANGED:
                        SWRB_TestCheckboxStateGet(pMsg->hWin, ID_MAIN_CHECKBOX_UNIWHEEL, SWRB_UNIWHEEL_TEST_TASK_PRIO);
                        break;
                }
                break;
            case ID_MAIN_CHECKBOX_KEY: // Notifications sent by 'cbxKey Test'
                switch(NCode) {
                    case WM_NOTIFICATION_CLICKED:
                        break;
                    case WM_NOTIFICATION_RELEASED:
                        break;
                    case WM_NOTIFICATION_VALUE_CHANGED:
                        SWRB_TestCheckboxStateGet(pMsg->hWin, ID_MAIN_CHECKBOX_KEY, SWRB_KEY_TEST_TASK_PRIO);
                        break;
                }
                break;
            case ID_MAIN_CHECKBOX_IRDA: // Notifications sent by 'cbxIRDA Test'
                switch(NCode) {
                    case WM_NOTIFICATION_CLICKED:
                        break;
                    case WM_NOTIFICATION_RELEASED:
                        break;
                    case WM_NOTIFICATION_VALUE_CHANGED:
                        SWRB_TestCheckboxStateGet(pMsg->hWin, ID_MAIN_CHECKBOX_IRDA, SWRB_IRDA_TEST_TASK_PRIO);
                        break;
                }
                break;
            case ID_MAIN_CHECKBOX_BUZZER: // Notifications sent by 'cbxBuzzer Test'
                switch(NCode) {
                    case WM_NOTIFICATION_CLICKED:
                        break;
                    case WM_NOTIFICATION_RELEASED:
                        break;
                    case WM_NOTIFICATION_VALUE_CHANGED:
                        SWRB_TestCheckboxStateGet(pMsg->hWin, ID_MAIN_CHECKBOX_BUZZER, SWRB_BUZZER_TEST_TASK_PRIO);
                        break;
                }
                break;
            case ID_MAIN_CHECKBOX_RGB_LED: // Notifications sent by 'cbxRgbLed Test'
                switch(NCode) {
                    case WM_NOTIFICATION_CLICKED:
                        break;
                    case WM_NOTIFICATION_RELEASED:
                        break;
                    case WM_NOTIFICATION_VALUE_CHANGED:
                        SWRB_TestCheckboxStateGet(pMsg->hWin, ID_MAIN_CHECKBOX_RGB_LED, SWRB_RGB_LED_TEST_TASK_PRIO);
                        break;
                }
                break;
            case ID_MAIN_CHECKBOX_CHARGE: // Notifications sent by 'cbxCharge Test'
                switch(NCode) {
                    case WM_NOTIFICATION_CLICKED:
                        break;
                    case WM_NOTIFICATION_RELEASED:
                        break;
                    case WM_NOTIFICATION_VALUE_CHANGED:
                        SWRB_TestCheckboxStateGet(pMsg->hWin, ID_MAIN_CHECKBOX_CHARGE, SWRB_CHARGE_TEST_TASK_PRIO);
                        break;
                }
                break;
            case ID_MAIN_EDIT_SN:
                switch(NCode){
                    case WM_NOTIFICATION_CLICKED:
                        break;
                    case WM_NOTIFICATION_RELEASED:
                        break;
                    case WM_NOTIFICATION_VALUE_CHANGED:
                        break;
                }
                break;
            case ID_MAIN_PROGBAR_MAIN:
                switch(NCode) {
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

static void _cbRgbLedDialog(WM_MESSAGE * pMsg){
    WM_HWIN hItem;
    int     NCode;
    int     Id;
    u8      state;
    
    switch(pMsg->MsgId){
        case WM_INIT_DIALOG:
            
            hItem = WM_GetDialogItem(pMsg->hWin, ID_MAIN_BUTTON_RGB_LED_OK);
            BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);

            hItem = WM_GetDialogItem(pMsg->hWin, ID_MAIN_BUTTON_RGB_LED_ERR);
            BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
        
            hItem = WM_GetDialogItem(pMsg->hWin, ID_MAIN_TEXT_RGB_LED);
            TEXT_SetFont(hItem, GUI_FONT_32_ASCII);
            TEXT_SetText(hItem, "RGB LED TEST");
            TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
            TEXT_SetTextColor(hItem, GUI_RED);
            
            break;
        case WM_NOTIFY_PARENT:
            Id    = WM_GetId(pMsg->hWinSrc);
            NCode = pMsg->Data.v;
            switch(Id) {
                case ID_MAIN_BUTTON_RGB_LED_OK: // Notifications sent by 'RGB LED OK'
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
                case ID_MAIN_BUTTON_RGB_LED_ERR: // Notifications sent by 'RGB LED ERR'
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

            hItem = WM_GetDialogItem(pMsg->hWin,ID_MAIN_FRAMEWIN_BUZZER);
            WM_AttachWindowAt(hItem, hWin_SWRB_MAIN, 10, 77);
        
            hItem = WM_GetDialogItem(pMsg->hWin, ID_MAIN_BUTTON_BUZZER_OK);
            BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);

            hItem = WM_GetDialogItem(pMsg->hWin, ID_MAIN_BUTTON_BUZZER_ERR);
            BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
        
            hItem = WM_GetDialogItem(pMsg->hWin, ID_MAIN_TEXT_BUZZER);
            TEXT_SetFont(hItem, GUI_FONT_32_ASCII);
            TEXT_SetText(hItem, "BUZZER TEST");
            TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
            TEXT_SetTextColor(hItem, GUI_BLACK);
        
            break;
        case WM_NOTIFY_PARENT:
            Id    = WM_GetId(pMsg->hWinSrc);
            NCode = pMsg->Data.v;
            switch(Id) {
                case ID_MAIN_BUTTON_BUZZER_OK: // Notifications sent by 'BUZZER OK'
                    switch(NCode) {
                        case WM_NOTIFICATION_CLICKED:

                            break;
                        case WM_NOTIFICATION_RELEASED:
                            BUZZER_TestStateSet(1);
                            BUZZER_TestValidFlagSet(1);
                            WM_HideWin(hWin_SWRB_BUZZER);
                            break;
                    }
                    break;
                case ID_MAIN_BUTTON_BUZZER_ERR: // Notifications sent by 'BUZZER ERROR'
                    switch(NCode) {
                        case WM_NOTIFICATION_CLICKED:

                            break;
                        case WM_NOTIFICATION_RELEASED:
                            BUZZER_TestStateSet(0);
                            BUZZER_TestValidFlagSet(1);
                            WM_HideWin(hWin_SWRB_BUZZER);
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
*       CreateEJE_SWRB_TEST_MainDLG
*/
WM_HWIN CreateEJE_SWRB_TEST_MainDLG(void)
{
    WM_HWIN hWin;

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

WM_HWIN CreateRGB_LED_TestDLG(void)
{
    WM_HWIN hWin;

    hWin = GUI_CreateDialogBox(_RgbLEDTestDialogCreate, GUI_COUNTOF(_RgbLEDTestDialogCreate), _cbRgbLedDialog, hWin_SWRB_MAIN, 180, 135);
    return hWin;
}

WM_HWIN CreateBUZZER_TestDLG(void)
{
    WM_HWIN hWin;

    hWin = GUI_CreateDialogBox(_BuzzerTestDialogCreate, GUI_COUNTOF(_BuzzerTestDialogCreate), _cbBuzzerDialog, hWin_SWRB_MAIN, 180, 135);
    return hWin;
}


void Button_Set_Text(WM_HWIN hWin, int buttonId, char *str)
{
    WM_HWIN hItem;
    hItem = WM_GetDialogItem(hWin, buttonId);
    BUTTON_SetText(hItem, str);
}

void Button_Set_unPressedBkColor(WM_HWIN hWin, int buttonId, GUI_COLOR color)
{
    WM_HWIN hItem;
    hItem = WM_GetDialogItem(hWin, buttonId);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, color);
}

void Button_SetEnable(WM_HWIN hWin, int buttonId)
{
    WM_HWIN hItem;
    hItem = WM_GetDialogItem(hWin, buttonId);
    WM_EnableWindow(hItem);
}

void Button_SetDisable(WM_HWIN hWin, int buttonId)
{
    WM_HWIN hItem;
    hItem = WM_GetDialogItem(hWin, buttonId);
    WM_DisableWindow(hItem);
}

void BUTTON_Set_Bitmap_Ex(WM_HWIN hWin, int buttonId, const GUI_BITMAP *pBitmap, int x, int y)
{
    WM_HWIN hItem;
    hItem = WM_GetDialogItem(hWin, buttonId);
    BUTTON_SetText(hItem, " ");
    BUTTON_SetBitmapEx(hItem, BUTTON_CI_DISABLED, pBitmap, x, y);
    BUTTON_SetBitmapEx(hItem, BUTTON_CI_PRESSED, pBitmap, x, y);
    BUTTON_SetBitmapEx(hItem, BUTTON_CI_UNPRESSED, pBitmap, x, y);
}

void BUTTON_Disp_Start_CHNStr(WM_HWIN hWin, int buttonId, int x, int y)
{
    BUTTON_Set_Bitmap_Ex(hWin, buttonId, &_bmStartCHN, x, y);
}

void BUTTON_Disp_Pause_CHNStr(WM_HWIN hWin, int buttonId, int x, int y)
{
    BUTTON_Set_Bitmap_Ex(hWin, buttonId, &_bmPauseCHN, x, y);
}

void BUTTON_Disp_Resume_CHNStr(WM_HWIN hWin, int buttonId, int x, int y)
{
    BUTTON_Set_Bitmap_Ex(hWin, buttonId, &_bmResumeCHN, x, y);
}

void BUTTON_Disp_Set_CHNStr(WM_HWIN hWin, int buttonId, int x, int y)
{
    BUTTON_Set_Bitmap_Ex(hWin, buttonId, &_bmSetCHN, x, y);
}

void BUTTON_Disp_Stop_CHNStr(WM_HWIN hWin, int buttonId, int x, int y)
{
    BUTTON_Set_Bitmap_Ex(hWin, buttonId, &_bmStopCHN, x, y);
}

void BUTTON_Disp_Confirm_CHNStr(WM_HWIN hWin, int buttonId, int x, int y)
{
    BUTTON_Set_Bitmap_Ex(hWin, buttonId, &_bmConfirmCHN, x, y);
}

void BUTTON_Disp_Check_CHNStr(WM_HWIN hWin, int buttonId, int x, int y)
{
    BUTTON_Set_Bitmap_Ex(hWin, buttonId, &_bmCheckCHN, x, y);
}

void BUTTON_Disp_Reset_CHNStr(WM_HWIN hWin, int buttonId, int x, int y)
{
    BUTTON_Set_Bitmap_Ex(hWin, buttonId, &_bmResetCHN, x, y);
}

void BUTTON_Disp_Cancel_CHNStr(WM_HWIN hWin, int buttonId, int x, int y)
{
    BUTTON_Set_Bitmap_Ex(hWin, buttonId, &_bmCancelCHN, x, y);
}

void BUTTON_Disp_Exit_CHNStr(WM_HWIN hWin, int buttonId, int x, int y)
{
    BUTTON_Set_Bitmap_Ex(hWin, buttonId, &_bmExitCHN, x, y);
}

void BUTTON_Disp_SerialNum_CHNStr(WM_HWIN hWin, int buttonId, int x, int y)
{
    BUTTON_Set_Bitmap_Ex(hWin, buttonId, &_bmSerialNumCHN, x, y);
}

void BUTTON_Disp_Time_CHNStr(WM_HWIN hWin, int buttonId, int x, int y)
{
    BUTTON_Set_Bitmap_Ex(hWin, buttonId, &_bmTimeCHN, x, y);
}

void Progbar_Set_Value(int progbarValue)
{
	WM_HWIN hItem;
	hItem = WM_GetDialogItem(hWin_SWRB_MAIN, ID_MAIN_PROGBAR_0);
	PROGBAR_SetValue(hItem, progbarValue);
}

void Progbar_Set_Percent(void)
{
    Progbar_Set_Value( (float)(gSwrbTestValidTaskCntTotal-gSwrbTestValidTaskCnt) / (float)(gSwrbTestValidTaskCntTotal)*100 );
}

void Edit_Set_Value(WM_HWIN hWin, int editId, long editValue)
{
    WM_HWIN hItem;
    hItem = WM_GetDialogItem(hWin, editId);
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
    
    for(i=ID_MAIN_EDIT_1;i<ID_MAIN_EDIT_SN;i++){
        Edit_Set_Value(hWin_SWRB_MAIN , i, 0);
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

void Checkbox_Set_Text(WM_HWIN hWin, int checkboxId, char *string)
{
    WM_HWIN hItem;
    hItem = WM_GetDialogItem(hWin, checkboxId);
    CHECKBOX_SetText(hItem, string);
}

int Checkbox_Get_State(int checkboxId)
{
    WM_HWIN hItem;
    hItem = WM_GetDialogItem(hWin_SWRB_MAIN, checkboxId);
    return(CHECKBOX_GetState(hItem));
}

void Checkbox_Set_State(WM_HWIN hWin, int checkboxId, unsigned int checkboxState)
{
    WM_HWIN hItem;
    hItem = WM_GetDialogItem(hWin, checkboxId);
    CHECKBOX_SetState(hItem, checkboxState);
}

void SWRB_TestCheckboxStateSet(u8 stateNum)
{
    int i;
    WM_HWIN hItem;
    
    for(i=ID_MAIN_CHECKBOX_WHEEL;i<ID_MAIN_CHECKBOX_BOUND;i++){
        hItem = WM_GetDialogItem(hWin_SWRB_MAIN, i);
        CHECKBOX_SetState(hItem, stateNum);
    }
}

void SWRB_TestCheckboxEnable(void)
{
    int i;
    WM_HWIN hItem;
    
    for(i=ID_MAIN_CHECKBOX_WHEEL;i<ID_MAIN_CHECKBOX_BOUND;i++){
        hItem = WM_GetDialogItem(hWin_SWRB_MAIN, i);
        WM_EnableWindow(hItem);
    }
}

void SWRB_TestCheckboxDisable(void)
{
    int i;
    WM_HWIN hItem;
    
    for(i=ID_MAIN_CHECKBOX_WHEEL;i<ID_MAIN_CHECKBOX_BOUND;i++){
        hItem = WM_GetDialogItem(hWin_SWRB_MAIN, i);
        WM_DisableWindow(hItem);
    }
}

void SWRB_TestCheckboxStateGet(WM_HWIN hWin, int id, int taskPrio){
    WM_HWIN hItem;
    hItem = WM_GetDialogItem(hWin, id);
    if(gSwrbTestMode == SWRB_TEST_MODE_IDLE){
        if(CHECKBOX_GetState(hItem)){
            gSwrbTestValidTaskCnt++;
            gSwrbTestValidTaskCntTotal++;
        }else{
            gSwrbTestValidTaskCnt--;
            gSwrbTestValidTaskCntTotal--;
        }
    }
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

void Checkbox_Set_Box_Back_Color(WM_HWIN hWin, int checkboxId, GUI_COLOR boxBkColor, int Index)
{
    WM_HWIN hItem;
    hItem = WM_GetDialogItem(hWin, checkboxId);
    CHECKBOX_SetBoxBkColor(hItem, boxBkColor, Index);
}

void MULTIEDIT_Set_Buffer_Size(int size)
{
    WM_HWIN hItem;
    
    hItem = WM_GetDialogItem(hWin_SWRB_MAIN, ID_MAIN_MULTIEDIT_MAIN);
    MULTIEDIT_SetBufferSize(hItem, size);
}

void MultiEdit_Set_Text(WM_HWIN hWin, int multiEditId, char *s)
{
	WM_HWIN hItem;
    
	hItem = WM_GetDialogItem(hWin, multiEditId);
	MULTIEDIT_SetText(hItem, s);
}

void MultiEdit_Add_Text(WM_HWIN hWin, int multiEditId, char *s)
{
    WM_HWIN hItem;
    
    hItem = WM_GetDialogItem(hWin, multiEditId);
    MULTIEDIT_AddText(hItem, s);
}

void MultiEdit_Set_Text_Color(GUI_COLOR multieditTextColor)
{
    WM_HWIN hItem;
    hItem = WM_GetDialogItem(hWin_SWRB_MAIN, ID_MAIN_MULTIEDIT_0);
    MULTIEDIT_SetTextColor(hItem, MULTIEDIT_CI_EDIT, multieditTextColor);
}

GRAPH_DATA_Handle Graph_Data_YT_Create(GUI_COLOR color, u32 maxNumItems, int16_t *pData, u32 numItems)
{
    GRAPH_DATA_Handle hGraphData;
    hGraphData = GRAPH_DATA_YT_Create(color, maxNumItems, pData, numItems);
    return hGraphData;
}

void SweepRobot_MainTestIndicateBtnToggle(void)
{
    if(++gMainDLGIndicateFlag%2){
        Button_Set_unPressedBkColor(hWin_SWRB_MAIN, ID_MAIN_BUTTON_INDICATE, GUI_DARKRED);
    }else{
        Button_Set_unPressedBkColor(hWin_SWRB_MAIN, ID_MAIN_BUTTON_INDICATE, GUI_LIGHTGRAY);
    }
}

void SWRB_WM_EnableWindow(WM_HWIN hWin, int id)
{
    WM_HWIN hItem;
    
    hItem = WM_GetDialogItem(hWin, id);
    WM_EnableWindow(hItem);
}

void SWRB_WM_DisableWindow(WM_HWIN hWin, int id)
{
    WM_HWIN hItem;
    
    hItem = WM_GetDialogItem(hWin, id);
    WM_DisableWindow(hItem);
}

/*************************** End of file ****************************/
