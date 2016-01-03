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

#include "EJE_SWRB_TEST_MainDLG.h"

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

#define IS_PCBTEST_CHECKBOX_ID(id)  ( (id == ID_PCBTEST_CHECKBOX_WHEEL)         ||\
                                      (id == ID_PCBTEST_CHECKBOX_BRUSH)         ||\
                                      (id == ID_PCBTEST_CHECKBOX_FAN)           ||\
                                      (id == ID_PCBTEST_CHECKBOX_IFRD)          ||\
                                      (id == ID_PCBTEST_CHECKBOX_COLLISION)     ||\
                                      (id == ID_PCBTEST_CHECKBOX_WHEEL_FLOAT)   ||\
                                      (id == ID_PCBTEST_CHECKBOX_ASH_TRAY)      ||\
                                      (id == ID_PCBTEST_CHECKBOX_UNIWHEEL)      ||\
                                      (id == ID_PCBTEST_CHECKBOX_KEY)           ||\
                                      (id == ID_PCBTEST_CHECKBOX_IRDA)          ||\
                                      (id == ID_PCBTEST_CHECKBOX_BUZZER)        ||\
                                      (id == ID_PCBTEST_CHECKBOX_RGB_LED)       ||\
                                      (id == ID_PCBTEST_CHECKBOX_CHARGE)\
                                    )

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

/*********************************************************************
*
*       _aPCBTestMainDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aPCBTestMainDialogCreate[] = {
//    { FRAMEWIN_CreateIndirect, "EJE_SweepRobot_test_System", ID_FRAMEWIN_MAIN, 0, 0, 800, 480, 0, 0x0, 0 },
    { WINDOW_CreateIndirect, "EJE_SWRB_TEST_SYSTEM", ID_PCBTEST_WINDOW_MAIN, 0, 0, 800, 480, 0, 0x0, 0 },
//    { MULTIPAGE_CreateIndirect, "Multipage_Main", ID_PCBTEST_MULTIPAGE_0, 0, 0, 800, 460, 0, 0x0, 0 },
    { MULTIEDIT_CreateIndirect, "Msg Multiedit",  ID_PCBTEST_MULTIEDIT_MAIN, 10, 77, 440, 330, 0, 0x0, 0 },
    { PROGBAR_CreateIndirect,   "Progbar",        ID_PCBTEST_PROGBAR_MAIN, 10, 442, 440, 20, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "START", ID_PCBTEST_BUTTON_START, 700, 0, 100, 120, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SET",   ID_PCBTEST_BUTTON_SET,  700, 120, 100, 120, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SET SN",  ID_PCBTEST_BUTTON_SET_SN, 500, 120, 100, 60, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SET TIME",  ID_PCBTEST_BUTTON_SET_TIME, 600, 180, 100, 60, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "STOP",  ID_PCBTEST_BUTTON_STOP, 700, 240, 100, 120, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "EXIT",  ID_PCBTEST_BUTTON_EXIT, 700, 360, 100, 120, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, " ",  ID_PCBTEST_BUTTON_INDICATE, 420, 407, 30, 30, 0, 0x0, 0 },
    { CHECKBOX_CreateIndirect,  "cbxWheel",       ID_PCBTEST_CHECKBOX_WHEEL, 460, 17, 210, 25, 0, 0x0, 0 },
    { CHECKBOX_CreateIndirect,  "cbxBrush",       ID_PCBTEST_CHECKBOX_BRUSH, 460, 52, 210, 25, 0, 0x0, 0 },
    { CHECKBOX_CreateIndirect,  "cbxFan",         ID_PCBTEST_CHECKBOX_FAN, 460, 87, 210, 25, 0, 0x0, 0 },
    { CHECKBOX_CreateIndirect,  "cbxIFRD",        ID_PCBTEST_CHECKBOX_IFRD, 460, 122, 210, 25, 0, 0x0, 0 },
    { CHECKBOX_CreateIndirect,  "cbxCollision",   ID_PCBTEST_CHECKBOX_COLLISION, 460, 157, 210, 25, 0, 0x0, 0 },
    { CHECKBOX_CreateIndirect,  "cbxWheelFloat",  ID_PCBTEST_CHECKBOX_WHEEL_FLOAT, 460, 192, 210, 25, 0, 0x0, 0 },
    { CHECKBOX_CreateIndirect,  "cbxAshTray",     ID_PCBTEST_CHECKBOX_ASH_TRAY, 460, 227, 210, 25, 0, 0x0, 0 },
    { CHECKBOX_CreateIndirect,  "cbxUniWheel",    ID_PCBTEST_CHECKBOX_UNIWHEEL, 460, 262, 210, 25, 0, 0x0, 0 },
    { CHECKBOX_CreateIndirect,  "cbxKey",         ID_PCBTEST_CHECKBOX_KEY, 460, 297, 210, 25, 0, 0x0, 0 },
    { CHECKBOX_CreateIndirect,  "cbxIRDA",        ID_PCBTEST_CHECKBOX_IRDA, 460, 332, 210, 25, 0, 0x0, 0 },
    { CHECKBOX_CreateIndirect,  "cbxBuzzer",      ID_PCBTEST_CHECKBOX_BUZZER, 460, 367, 210, 25, 0, 0x0, 0 },
    { CHECKBOX_CreateIndirect,  "cbxRgbLed",      ID_PCBTEST_CHECKBOX_RGB_LED, 460, 402, 210, 25, 0, 0x0, 0 },
    { CHECKBOX_CreateIndirect,  "cbxCharge",      ID_PCBTEST_CHECKBOX_CHARGE, 460, 437, 210, 25, 0, 0x0, 0 },
//    { GRAPH_CreateIndirect, "Graph", ID_PCBTEST_GRAPH_0, 10, 310, 440, 100, 0, 0x0, 0 },
    { EDIT_CreateIndirect, "EditU1", ID_PCBTEST_EDIT_U1, 10, 17, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditU2", ID_PCBTEST_EDIT_U2, 65, 17, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditU3", ID_PCBTEST_EDIT_U3, 120, 17, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditU4", ID_PCBTEST_EDIT_U4, 175, 17, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditU5", ID_PCBTEST_EDIT_U5, 230, 17, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditU6", ID_PCBTEST_EDIT_U6, 285, 17, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditU7", ID_PCBTEST_EDIT_U7, 340, 17, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditU8", ID_PCBTEST_EDIT_U8, 395, 17, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditD1", ID_PCBTEST_EDIT_D1, 10, 47, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditD2", ID_PCBTEST_EDIT_D2, 65, 47, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditD3", ID_PCBTEST_EDIT_D3, 120, 47, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditD4", ID_PCBTEST_EDIT_D4, 175, 47, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditD5", ID_PCBTEST_EDIT_D5, 230, 47, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditD6", ID_PCBTEST_EDIT_D6, 285, 47, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditD7", ID_PCBTEST_EDIT_D7, 340, 47, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditD8", ID_PCBTEST_EDIT_D8, 395, 47, 55, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditSN", ID_PCBTEST_EDIT_SN, 190, 407, 230, 30, 0, 0x64, 0 },
    { EDIT_CreateIndirect, "EditDate", ID_PCBTEST_EDIT_DATE, 10, 407, 180, 30, 0, 0x64, 0 },
};

static const GUI_WIDGET_CREATE_INFO _aPCBTestWarningDialogCreate[] = {
    { WINDOW_CreateIndirect, "WARNING", ID_PCBTEST_WINDOW_WARNING, 11, 348, 438, 58, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "RETEST", ID_PCBTEST_BUTTON_WARNING_RETEST, 0, 0, 219, 58, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "CONTINUE", ID_PCBTEST_BUTTON_WARNING_SKIP,  219, 0, 219, 58, 0, 0x0, 0 },
};

static const GUI_WIDGET_CREATE_INFO _aRgbLEDTestDialogCreate[] = {
    { FRAMEWIN_CreateIndirect, "RGB LED TEST", ID_PCBTEST_FRAMEWIN_RGB_LED, 0, 0, 440, 210, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "OK", ID_PCBTEST_BUTTON_RGB_LED_OK, 60, 100, 120, 60, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "ERROR", ID_PCBTEST_BUTTON_RGB_LED_ERR,  260, 100, 120, 60, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "RGB LED TEST", ID_PCBTEST_TEXT_RGB_LED, 68, 17, 308, 65, 0, 0x64, 0 },
};

static const GUI_WIDGET_CREATE_INFO _aBuzzerTestDialogCreate[] = {
    { FRAMEWIN_CreateIndirect, "BUZZER TEST", ID_PCBTEST_FRAMEWIN_BUZZER, 0, 0, 440, 210, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "OK", ID_PCBTEST_BUTTON_BUZZER_OK, 60, 100, 120, 60, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "ERROR", ID_PCBTEST_BUTTON_BUZZER_ERR,  260, 100, 120, 60, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "BUZZER TEST", ID_PCBTEST_TEXT_BUZZER, 68, 17, 308, 65, 0, 0x64, 0 },
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
    CHECKBOX_SetState(hItem, 1);
    WM_DisableWindow(hItem);
}

/*********************************************************************
*
*       _cbPCBTestMainDialog
*/
static void _cbPCBTestMainDialog(WM_MESSAGE * pMsg) 
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
            hItem = WM_GetDialogItem(pMsg->hWin, ID_PCBTEST_BUTTON_START);
            Button_Init(hItem);
            BUTTON_SetText(hItem, " ");
            BUTTON_DispStartCHNStr(pMsg->hWin, ID_PCBTEST_BUTTON_START, 18, 43);
            BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, GUI_LIGHTBLUE);
            BUTTON_SetBkColor(hItem, BUTTON_CI_PRESSED, GUI_LIGHTBLUE);
            //
            // Initialization of 'SET'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_PCBTEST_BUTTON_SET);
            Button_Init(hItem);
            BUTTON_SetText(hItem, " ");
            BUTTON_DispSetCHNStr(pMsg->hWin, ID_PCBTEST_BUTTON_SET, 18, 43);
            BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, GUI_LIGHTCYAN);
            //
            // Initialization of 'SET SN'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_PCBTEST_BUTTON_SET_SN);
            Button_Init(hItem);
            BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, GUI_LIGHTCYAN);
            WM_HideWin(hItem);
            //
            // Initialization of 'SET TIME'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_PCBTEST_BUTTON_SET_TIME);
            Button_Init(hItem);
            BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, GUI_LIGHTCYAN);
            BUTTON_SetBkColor(hItem, BUTTON_CI_PRESSED, GUI_LIGHTCYAN);
            WM_HideWin(hItem);
            //
            // Initialization of 'STOP'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_PCBTEST_BUTTON_STOP);
            Button_Init(hItem);
            BUTTON_SetText(hItem, " ");
            BUTTON_DispStopCHNStr(pMsg->hWin, ID_PCBTEST_BUTTON_STOP, 18, 43);
            BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, GUI_LIGHTRED);
            BUTTON_SetBkColor(hItem, BUTTON_CI_PRESSED, GUI_LIGHTRED);
            WM_DisableWindow(hItem);
            //
            // Initialization of 'EXIT'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_PCBTEST_BUTTON_EXIT);
            Button_Init(hItem);
            BUTTON_SetText(hItem, " ");
            BUTTON_DispExitCHNStr(pMsg->hWin, ID_PCBTEST_BUTTON_EXIT, 18, 43);
            BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, GUI_LIGHTGREEN);
            BUTTON_SetBkColor(hItem, BUTTON_CI_PRESSED, GUI_LIGHTGREEN);
            //
            // Initialization of 'Indicate'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_PCBTEST_BUTTON_INDICATE);
            WM_BringToTop(hItem);
            BUTTON_SetSkinClassic(hItem);
            WIDGET_SetEffect(hItem, &WIDGET_Effect_Simple);
            Button_Set_BkColor(hWin_SWRB_PCBTEST,ID_PCBTEST_BUTTON_INDICATE, GUI_LIGHTGRAY);
            Button_Set_Text(hWin_SWRB_PCBTEST, ID_PCBTEST_BUTTON_INDICATE, " ");
            BUTTON_SetFocussable(hItem, 0);
            //
            // Initialization of 'Msg Multiedit'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_PCBTEST_MULTIEDIT_MAIN);
            MULTIEDIT_SetText(hItem, "Waiting for Start");
            MULTIEDIT_SetFont(hItem, GUI_FONT_24_ASCII);
            MULTIEDIT_SetAutoScrollV(hItem,1);
            MULTIEDIT_SetWrapWord(hItem);
            MULTIEDIT_SetBufferSize(hItem, 2048);
            WM_DisableWindow(hItem);
            //
            // Initialization of 'cbxWheel Test'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_PCBTEST_CHECKBOX_WHEEL);
            CHECKBOX_SetText(hItem, "WHEEL");
            CHECKBOX_SetDefaultSkinClassic();
            Checkbox_Init(hItem);
            //
            // Initialization of 'cbxSBrush Test'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_PCBTEST_CHECKBOX_BRUSH);
            CHECKBOX_SetText(hItem, "BRUSH");
            Checkbox_Init(hItem);
            //
            // Initialization of 'cbxFan Test'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_PCBTEST_CHECKBOX_FAN);
            CHECKBOX_SetText(hItem, "FAN");
            Checkbox_Init(hItem);
            //
            // Initialization of 'cbxIFRD Test'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_PCBTEST_CHECKBOX_IFRD);
            CHECKBOX_SetText(hItem, "IFRD");
            Checkbox_Init(hItem);
            //
            // Initialization of 'cbxCollision Test'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_PCBTEST_CHECKBOX_COLLISION);
            CHECKBOX_SetText(hItem, "COLLISION");
            Checkbox_Init(hItem);
            //
            // Initialization of 'cbxWheelFloat Test'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_PCBTEST_CHECKBOX_WHEEL_FLOAT);
            CHECKBOX_SetText(hItem, "WHEEL FLOAT");
            Checkbox_Init(hItem);
            //
            // Initialization of 'cbxAshTray Test'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_PCBTEST_CHECKBOX_ASH_TRAY);
            CHECKBOX_SetText(hItem, "ASH TRAY");
            Checkbox_Init(hItem);
            //
            // Initialization of 'cbxUniWheel Test'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_PCBTEST_CHECKBOX_UNIWHEEL);
            CHECKBOX_SetText(hItem, "UNIWHEEL");
            Checkbox_Init(hItem);
            //
            // Initialization of 'cbxKey Test'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_PCBTEST_CHECKBOX_KEY);
            CHECKBOX_SetText(hItem, "KEY");
            Checkbox_Init(hItem);
            //
            // Initialization of 'cbxIRDA Test'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_PCBTEST_CHECKBOX_IRDA);
            CHECKBOX_SetText(hItem, "IRDA");
            Checkbox_Init(hItem);
            //
            // Initialization of 'cbxBuzzer Test'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_PCBTEST_CHECKBOX_BUZZER);
            CHECKBOX_SetText(hItem, "BUZZER");
            Checkbox_Init(hItem);
            //
            // Initialization of 'cbxRgbLED Test'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_PCBTEST_CHECKBOX_RGB_LED);
            CHECKBOX_SetText(hItem, "RGB LED");
            Checkbox_Init(hItem);
            //
            // Initialization of 'cbxCharge'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_PCBTEST_CHECKBOX_CHARGE);
            CHECKBOX_SetText(hItem, "CHARGE");
            Checkbox_Init(hItem);
            //
            // Initialization of 'Edit'
            //
            for(i=ID_PCBTEST_EDIT_U1;i<=ID_PCBTEST_EDIT_D8;i++){
                hItem = WM_GetDialogItem(pMsg->hWin, i);
                EDIT_SetFont(hItem, &GUI_Font20_ASCII);
                EDIT_SetDecMode(hItem, 0, 0, 65536, 0, GUI_EDIT_SUPPRESS_LEADING_ZEROES);
                EDIT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
            }
            //
            // Initialization of 'EditDate'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_PCBTEST_EDIT_DATE);
            EDIT_SetFont(hItem, &GUI_Font20_ASCII);
            EDIT_SetFocussable(hItem, DISABLE);
            EDIT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
            //
            // Initialization of 'EditSN'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_PCBTEST_EDIT_SN);
            EDIT_SetFont(hItem, &GUI_Font20_ASCII);
            EDIT_SetFocussable(hItem, DISABLE);
            EDIT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
            //
            // Initialization of 'PROGBAR'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_PCBTEST_PROGBAR_MAIN);
            PROGBAR_SetSkinClassic(hItem);
            WIDGET_SetEffect(hItem, &WIDGET_Effect_None);

            WM_HideWin(pMsg->hWin);
            break;
        case WM_NOTIFY_PARENT:
            Id    = WM_GetId(pMsg->hWinSrc);
            NCode = pMsg->Data.v;
            
            if(IS_PCBTEST_CHECKBOX_ID(Id)){
                switch(NCode){
                    case WM_NOTIFICATION_VALUE_CHANGED:
                        SWRB_TestCheckboxStateGet(pMsg->hWin, i);
                        break;
                }
            }else{
                switch(Id) {
                case ID_PCBTEST_BUTTON_START: // Notifications sent by 'START'
                    switch(NCode) {
                        case WM_NOTIFICATION_CLICKED:
                            break;
                        case WM_NOTIFICATION_RELEASED:
                            SweepRobot_PCBTestStartProc();
                            break;
                    }
                    break;
                case ID_PCBTEST_BUTTON_SET: // Notifications sent by 'SET'
                    switch(NCode) {
                        case WM_NOTIFICATION_CLICKED:
                            break;
                        case WM_NOTIFICATION_RELEASED:
                            SweepRobot_PCBTestLoginProc();
                            break;
                    }
                    break;
                case ID_PCBTEST_BUTTON_SET_SN: // Notifications sent by 'SETSN'
                    switch(NCode) {
                        case WM_NOTIFICATION_CLICKED:
                            break;
                        case WM_NOTIFICATION_RELEASED:
                            break;
                    }
                    break;
                case ID_PCBTEST_BUTTON_SET_TIME: // Notifications sent by 'SETTIME'
                    switch(NCode) {
                        case WM_NOTIFICATION_CLICKED:
                            break;
                        case WM_NOTIFICATION_RELEASED:
                            break;
                    }
                    break;
                case ID_PCBTEST_BUTTON_STOP: // Notifications sent by 'STOP'
                    switch(NCode) {
                        case WM_NOTIFICATION_CLICKED:
                            break;
                        case WM_NOTIFICATION_RELEASED:
                            SweepRobot_PCBTestStopProc();
                            break;
                    }
                    break;
                case ID_PCBTEST_BUTTON_EXIT: // Notifications sent by 'EXIT'
                    switch(NCode) {
                        case WM_NOTIFICATION_CLICKED:
                            break;
                        case WM_NOTIFICATION_RELEASED:
                            SweepRobot_PCBTestExitProc();
                            break;
                    }
                    break;
                case ID_PCBTEST_MULTIEDIT_MAIN: // Notifications sent by 'Msg Multiedit'
                    switch(NCode) {
                        case WM_NOTIFICATION_CLICKED:
                            break;
                        case WM_NOTIFICATION_RELEASED:
                            break;
                        case WM_NOTIFICATION_VALUE_CHANGED:
                            break;
                    }
                    break;
                case ID_PCBTEST_EDIT_SN:
                    switch(NCode){
                        case WM_NOTIFICATION_CLICKED:
                            break;
                        case WM_NOTIFICATION_RELEASED:
                            break;
                        case WM_NOTIFICATION_VALUE_CHANGED:
                            break;
                    }
                    break;
                case ID_PCBTEST_PROGBAR_MAIN:
                    switch(NCode) {
                        case WM_NOTIFICATION_VALUE_CHANGED:
                            break;
                    }
                    break;
                }
            }
            break;
        default:
            WM_DefaultProc(pMsg);
            break;
    }
}

static void _cbPCBTestWarningDialog(WM_MESSAGE * pMsg)
{
    WM_HWIN hItem;
    int     NCode;
    int     Id;
    
    switch(pMsg->MsgId){
        case WM_INIT_DIALOG:
            
            hItem = WM_GetDialogItem(pMsg->hWin, ID_PCBTEST_BUTTON_WARNING_RETEST);
            BUTTON_SetSkinClassic(hItem);
            BUTTON_SetFocussable(hItem, DISABLE);
            WIDGET_SetEffect(hItem, &WIDGET_Effect_None);
            BUTTON_SetTextAlign(hItem, GUI_TA_HCENTER|GUI_TA_VCENTER);
            BUTTON_SetText(hItem, "");
            BUTTON_DispReTestCHNStr(pMsg->hWin, ID_PCBTEST_BUTTON_WARNING_RETEST, 94, 14);
            
            hItem = WM_GetDialogItem(pMsg->hWin, ID_PCBTEST_BUTTON_WARNING_SKIP);
            BUTTON_SetSkinClassic(hItem);
            BUTTON_SetFocussable(hItem, DISABLE);
            WIDGET_SetEffect(hItem, &WIDGET_Effect_None);
            BUTTON_SetTextAlign(hItem, GUI_TA_HCENTER|GUI_TA_VCENTER);
            BUTTON_SetText(hItem, "");
            BUTTON_DispSkipCHNStr(pMsg->hWin, ID_PCBTEST_BUTTON_WARNING_SKIP, 94, 14);
            
//            WM_HideWin(pMsg->hWin);
            break;
        case WM_NOTIFY_PARENT:
            Id    = WM_GetId(pMsg->hWinSrc);
            NCode = pMsg->Data.v;
            switch(Id) {
                case ID_PCBTEST_BUTTON_WARNING_RETEST: // Notifications sent by 'RETEST'
                    switch(NCode) {
                        case WM_NOTIFICATION_CLICKED:
                            break;
                        case WM_NOTIFICATION_RELEASED:
                            SWRB_PCBTestWarningDLGReTestProc();
                            break;
                    }
                    break;
                case ID_PCBTEST_BUTTON_WARNING_SKIP: // Notifications sent by 'SKIP'
                    switch(NCode) {
                        case WM_NOTIFICATION_CLICKED:
                            break;
                        case WM_NOTIFICATION_RELEASED:
                            SWRB_PCBTestWarningDLGSkipProc();
                            break;
                    }
                    break;
            }
        default:
            WM_DefaultProc(pMsg);
            break;
    }
}

static void _cbRgbLedDialog(WM_MESSAGE * pMsg)
{
    WM_HWIN hItem;
    int     NCode;
    int     Id;
    u8      state;
    
    switch(pMsg->MsgId){
        case WM_INIT_DIALOG:
            
            hItem = WM_GetDialogItem(pMsg->hWin, ID_PCBTEST_BUTTON_RGB_LED_OK);
//            BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
            Button_Set_Text(pMsg->hWin, ID_PCBTEST_BUTTON_RGB_LED_OK, "");
            BUTTON_DispOKCHNStr(pMsg->hWin, ID_PCBTEST_BUTTON_RGB_LED_OK, 28, 14);

            hItem = WM_GetDialogItem(pMsg->hWin, ID_PCBTEST_BUTTON_RGB_LED_ERR);
//            BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
            Button_Set_Text(pMsg->hWin, ID_PCBTEST_BUTTON_RGB_LED_ERR, "");
            BUTTON_DispErrorCHNStr(pMsg->hWin, ID_PCBTEST_BUTTON_RGB_LED_ERR, 28, 14);
        
            hItem = WM_GetDialogItem(pMsg->hWin, ID_PCBTEST_TEXT_RGB_LED);
            TEXT_SetFont(hItem, GUI_FONT_32_ASCII);
            TEXT_SetText(hItem, "RGB LED TEST");
            TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
            TEXT_SetTextColor(hItem, GUI_RED);
            
            break;
        case WM_NOTIFY_PARENT:
            Id    = WM_GetId(pMsg->hWinSrc);
            NCode = pMsg->Data.v;
            switch(Id) {
                case ID_PCBTEST_BUTTON_RGB_LED_OK: // Notifications sent by 'RGB LED OK'
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
                case ID_PCBTEST_BUTTON_RGB_LED_ERR: // Notifications sent by 'RGB LED ERR'
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

static void _cbBuzzerDialog(WM_MESSAGE * pMsg)
{
    WM_HWIN hItem;
    int     NCode;
    int     Id;
    
    switch(pMsg->MsgId){
        case WM_INIT_DIALOG:

            hItem = WM_GetDialogItem(pMsg->hWin,ID_PCBTEST_FRAMEWIN_BUZZER);
            WM_AttachWindowAt(hItem, hWin_SWRB_PCBTEST, 10, 77);
        
            hItem = WM_GetDialogItem(pMsg->hWin, ID_PCBTEST_BUTTON_BUZZER_OK);
//            BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
            Button_Set_Text(pMsg->hWin, ID_PCBTEST_BUTTON_RGB_LED_OK, "");
            BUTTON_DispOKCHNStr(pMsg->hWin, ID_PCBTEST_BUTTON_BUZZER_OK, 28, 14);

            hItem = WM_GetDialogItem(pMsg->hWin, ID_PCBTEST_BUTTON_BUZZER_ERR);
//            BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
            Button_Set_Text(pMsg->hWin, ID_PCBTEST_BUTTON_BUZZER_ERR, "");
            BUTTON_DispErrorCHNStr(pMsg->hWin, ID_PCBTEST_BUTTON_BUZZER_ERR, 28, 14);
        
            hItem = WM_GetDialogItem(pMsg->hWin, ID_PCBTEST_TEXT_BUZZER);
            TEXT_SetFont(hItem, GUI_FONT_32_ASCII);
            TEXT_SetText(hItem, "BUZZER TEST");
            TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
            TEXT_SetTextColor(hItem, GUI_BLACK);
        
            break;
        case WM_NOTIFY_PARENT:
            Id    = WM_GetId(pMsg->hWinSrc);
            NCode = pMsg->Data.v;
            switch(Id) {
                case ID_PCBTEST_BUTTON_BUZZER_OK: // Notifications sent by 'BUZZER OK'
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
                case ID_PCBTEST_BUTTON_BUZZER_ERR: // Notifications sent by 'BUZZER ERROR'
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
*       Public data
*
**********************************************************************
*/

WM_HWIN hWin_SWRB_PCBTEST;
WM_HWIN hWin_SWRB_WARNING;
WM_HWIN hWin_SWRB_RGB_LED;
WM_HWIN hWin_SWRB_BUZZER;

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/

/*********************************************************************
*
*       CreateEJE_SWRB_TEST_PCBTestDLG
*/
WM_HWIN CreateEJE_SWRB_TEST_PCBTestDLG(void)
{
    WM_HWIN hWin;

    hWin = GUI_CreateDialogBox(_aPCBTestMainDialogCreate, GUI_COUNTOF(_aPCBTestMainDialogCreate), _cbPCBTestMainDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

WM_HWIN CreateWarningDLG(void)
{
    WM_HWIN hWin;

    hWin = GUI_CreateDialogBox(_aPCBTestWarningDialogCreate, GUI_COUNTOF(_aPCBTestWarningDialogCreate), _cbPCBTestWarningDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

WM_HWIN CreateRGB_LED_TestDLG(void)
{
    WM_HWIN hWin;

    hWin = GUI_CreateDialogBox(_aRgbLEDTestDialogCreate, GUI_COUNTOF(_aRgbLEDTestDialogCreate), _cbRgbLedDialog, hWin_SWRB_PCBTEST, 180, 135);
    return hWin;
}

WM_HWIN CreateBUZZER_TestDLG(void)
{
    WM_HWIN hWin;

    hWin = GUI_CreateDialogBox(_aBuzzerTestDialogCreate, GUI_COUNTOF(_aBuzzerTestDialogCreate), _cbBuzzerDialog, hWin_SWRB_PCBTEST, 180, 135);
    return hWin;
}

/*************************** End of file ****************************/
