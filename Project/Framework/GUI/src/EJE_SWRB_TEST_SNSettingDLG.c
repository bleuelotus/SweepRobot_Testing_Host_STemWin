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

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/

// USER START (Optionally insert additional defines)
WM_HWIN hWin_SWRB_SNSETTING;
// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

// USER START (Optionally insert additional static data)
static int  lastLwIndex[6];
// USER END

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
//    { FRAMEWIN_CreateIndirect, "SettingDLG", ID_SET_FRAMEWIN, 0, 0, 800, 480, 0, 0x0, 0 },
    { WINDOW_CreateIndirect, "TEST SETTING", ID_SET_WINDOW, 0, 0, 800, 480, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "Set Serial Number", ID_SET_TEXT_0, 20, 10, 680, 50, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Confirm", ID_SET_BUTTON_CONFIRM, 700, 0, 100, 120, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Check", ID_SET_BUTTON_CHECK, 700, 120, 100, 120, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Reset", ID_SET_BUTTON_RESET, 700, 240, 100, 120, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Cancel", ID_SET_BUTTON_CANCEL, 700, 360, 100, 120, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SN Set", ID_SET_BUTTON_SNSET, 20, 420, 100, 60, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Time Set", ID_SET_BUTTON_TIMESET, 120, 420, 100, 60, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Reserve1", ID_SET_BUTTON_RESERVE1, 220, 420, 100, 60, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Reserve2", ID_SET_BUTTON_RESERVE2, 320, 420, 100, 60, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "Reserve3", ID_SET_BUTTON_RESERVE3, 420, 420, 100, 60, 0, 0x0, 0 },
    { LISTWHEEL_CreateIndirect, "lwYear", ID_SET_LISTWHEEL_YEAR, 20, 60, 110, 230, 0, 0x0, 0 },
    { LISTWHEEL_CreateIndirect, "lwMonth", ID_SET_LISTWHEEL_MONTH, 130, 60, 110, 230, 0, 0x0, 0 },
    { LISTWHEEL_CreateIndirect, "lwDay", ID_SET_LISTWHEEL_DAY, 240, 60, 110, 230, 0, 0x0, 0 },
    { LISTWHEEL_CreateIndirect, "lwSN1", ID_SET_LISTWHEEL_SN1, 350, 60, 110, 230, 0, 0x0, 0 },
    { LISTWHEEL_CreateIndirect, "lwSN2", ID_SET_LISTWHEEL_SN2, 460, 60, 110, 230, 0, 0x0, 0 },
    { LISTWHEEL_CreateIndirect, "lwSN3", ID_SET_LISTWHEEL_SN3, 570, 60, 110, 230, 0, 0x0, 0 },
    { EDIT_CreateIndirect, "editComb", ID_SET_EDIT_COMB, 20, 340, 660, 40, 0 ,0x0, 0 },
    { EDIT_CreateIndirect, "editYear", ID_SET_EDIT_YEAR, 20, 300, 110, 40, 0 ,0x0, 0 },
    { EDIT_CreateIndirect, "editMonth", ID_SET_EDIT_MONTH, 130, 300, 110, 40, 0 ,0x0, 0 },
    { EDIT_CreateIndirect, "editDay", ID_SET_EDIT_DAY, 240, 300, 110, 40, 0 ,0x0, 0 },
    { EDIT_CreateIndirect, "editSN1", ID_SET_EDIT_SN1, 350, 300, 110, 40, 0 ,0x0, 0 },
    { EDIT_CreateIndirect, "editSN2", ID_SET_EDIT_SN2, 460, 300, 110, 40, 0 ,0x0, 0 },
    { EDIT_CreateIndirect, "editSN3", ID_SET_EDIT_SN3, 570, 300, 110, 40, 0 ,0x0, 0 },
    // USER START (Optionally insert additional widgets)
    // USER END
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

static void ListWheel_ResetToLastPos(WM_HWIN hWin);
static void ListWheel_ResetToZero(WM_HWIN hWin);
static void ListWheel_TestDataFilePathGet(WM_HWIN hWin, char *dest_str);

// USER START (Optionally insert additional static code)
static void Button_Init(WM_HWIN hItem)
{
    BUTTON_SetFont(hItem, GUI_FONT_24_ASCII);
    BUTTON_SetSkinClassic(hItem);
    BUTTON_SetFocussable(hItem, DISABLE);
    WIDGET_SetEffect(hItem, &WIDGET_Effect_None);
}

static void Button_ConfirmProc(WM_HWIN hWin)
{
    char *str;
    
    ListWheel_TestDataFilePathGet(hWin,str);
    gSwrbTestMode = SWRB_TEST_MODE_IDLE;
    WM_HideWin(hWin);
    WM_ShowWin(hWin_SWRB_MAIN);
}

static void Button_CheckProc(WM_HWIN hWin)
{
    char *str;
    
    ListWheel_TestDataFilePathGet(hWin, str);
}

static void Button_ResetProc(WM_HWIN hWin)
{
    ListWheel_ResetToZero(hWin);
}

static void Button_CancelProc(WM_HWIN hWin)
{
    ListWheel_ResetToLastPos(hWin);
    WM_HideWin(hWin);
    WM_ShowWin(hWin_SWRB_MAIN);
    gSwrbTestMode = SWRB_TEST_MODE_IDLE;
}

static void Edit_Update(WM_HWIN hWin, int editStartId, int editStopId, int lwId)
{
    int i,j;
    int lwItemIndex;
    char *str;
    LISTWHEEL_Handle hListWheel;
    WM_HWIN hItem;
    
    for(i=editStartId,j=lwId;i<=editStopId;i++,j++){
            hListWheel = WM_GetDialogItem(hWin, j);
            lwItemIndex = LISTWHEEL_GetPos(hListWheel);
            str = mymalloc(SRAMIN, sizeof(char)*10);
            if(str != NULL){
                *str = 0;
                LISTWHEEL_GetItemText(hListWheel, lwItemIndex, str, 10);
                hItem = WM_GetDialogItem(hWin, i);
                EDIT_SetText(hItem, str);
                myfree(SRAMIN, str);
            }
        }
}

static void ListWheel_Init(WM_HWIN hItem)
{
    LISTWHEEL_SetFont(hItem, GUI_FONT_32_ASCII);
    LISTWHEEL_SetDeceleration(hItem, 10);
    LISTWHEEL_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    LISTWHEEL_SetSnapPosition(hItem, 115);
    LISTWHEEL_SetBkColor(hItem, LISTWHEEL_CI_SEL, GUI_LIGHTRED);
    LISTWHEEL_SetBkColor(hItem, LISTWHEEL_CI_UNSEL, GUI_BLACK);
    LISTWHEEL_SetTextColor(hItem, LISTWHEEL_CI_SEL, GUI_WHITE);
    LISTWHEEL_SetTextColor(hItem, LISTWHEEL_CI_UNSEL, GUI_GRAY);
}

static void ListWheel_SelChangeProc(WM_HWIN hWin, int lwId, int editId)
{
    int  lwItemIndex;
    char *lwBuf;
    WM_HWIN hItem;
    
    hItem = WM_GetDialogItem(hWin, lwId);
    lwItemIndex = LISTWHEEL_GetPos(hItem);
    LISTWHEEL_SetSel(hItem, lwItemIndex);
    lwBuf = mymalloc(SRAMIN, sizeof(char)*10);
    LISTWHEEL_GetItemText(hItem, lwItemIndex, lwBuf, 10);
    hItem = WM_GetDialogItem(hWin, editId);
    EDIT_SetText(hItem, lwBuf);
    myfree(SRAMIN, lwBuf);
}

static void ListWheel_GetText(WM_HWIN *hWin,int id, char *str)
{
    WM_HWIN hItem;
    int     lwItemIndex;
    char    *lwBuf;
   
    hItem = WM_GetDialogItem(*hWin, id);
    lwItemIndex = LISTWHEEL_GetPos(hItem);
    lwBuf = mymalloc(SRAMIN, sizeof(char)*10);
    LISTWHEEL_GetItemText(hItem, lwItemIndex, lwBuf, 10);
    mymemcpy(str,lwBuf,1);
    myfree(SRAMIN, lwBuf);
}

static void ListWheel_ResetToLastPos(WM_HWIN hWin)
{
    WM_HWIN hItem;
    int i;
    u8 j;
    
    for(i=ID_SET_LISTWHEEL_YEAR,j=0;i<=ID_SET_LISTWHEEL_SN3;i++,j++){
        hItem = WM_GetDialogItem(hWin, i);
        LISTWHEEL_SetPos(hItem, lastLwIndex[j]);
    }
}

static void ListWheel_ResetToZero(WM_HWIN hWin)
{
    WM_HWIN hItem;
    int i;
    
    for(i=ID_SET_LISTWHEEL_0;i<=ID_SET_LISTWHEEL_5;i++){
        hItem = WM_GetDialogItem(hWin, i);
        LISTWHEEL_MoveToPos(hItem, 0);
    }
}

static void SerialNum_Comb(WM_HWIN hWin, int id, char *dest_SNumStr)
{
    WM_HWIN hItem;
    int     lwItemIndex;
    char    *lwBuf;
    
    hItem = WM_GetDialogItem(hWin, id);
    lwItemIndex = LISTWHEEL_GetPos(hItem);
    lwBuf = mymalloc(SRAMIN, sizeof(char)*10);
    LISTWHEEL_GetItemText(hItem, lwItemIndex, lwBuf, 10);
    dest_SNumStr = strcat(dest_SNumStr, lwBuf);
    myfree(SRAMIN, lwBuf);
}

static void ListWheel_TestDataFilePathGet(WM_HWIN hWin, char *dest_str)
{
    WM_HWIN hItem;
    FRESULT flErr;
    char    *lwBuf;
    char *swrbTestDataFilePath;

    flErr = flErr;
    
    swrbTestDataFilePath = mymalloc(SRAMIN, sizeof(char)*40);
    *swrbTestDataFilePath = 0;

    lwBuf = "0:/";
    swrbTestDataFilePath = strcat(swrbTestDataFilePath, lwBuf);

    SerialNum_Comb(hWin, ID_SET_LISTWHEEL_YEAR, swrbTestDataFilePath);
    SerialNum_Comb(hWin, ID_SET_LISTWHEEL_MONTH, swrbTestDataFilePath);
    SerialNum_Comb(hWin, ID_SET_LISTWHEEL_DAY, swrbTestDataFilePath);
    
    flErr = f_mkdir(swrbTestDataFilePath);
    
    *swrbTestDataFilePath = 0;
    
    lwBuf = "0:/";
    swrbTestDataFilePath = strcat(swrbTestDataFilePath, lwBuf);
    
    SerialNum_Comb(hWin, ID_SET_LISTWHEEL_YEAR, swrbTestDataFilePath);
    SerialNum_Comb(hWin, ID_SET_LISTWHEEL_MONTH, swrbTestDataFilePath);
    SerialNum_Comb(hWin, ID_SET_LISTWHEEL_DAY, swrbTestDataFilePath);
    
    lwBuf = "/";
    swrbTestDataFilePath = strcat(swrbTestDataFilePath, lwBuf);
    
    SerialNum_Comb(hWin, ID_SET_LISTWHEEL_SN1, swrbTestDataFilePath);
    SerialNum_Comb(hWin, ID_SET_LISTWHEEL_SN2, swrbTestDataFilePath);
    SerialNum_Comb(hWin, ID_SET_LISTWHEEL_SN3, swrbTestDataFilePath);

    lwBuf = ".txt";
    swrbTestDataFilePath = strcat(swrbTestDataFilePath, lwBuf);

    hItem = WM_GetDialogItem(hWin, ID_SET_EDIT_COMB);
    EDIT_SetText(hItem, swrbTestDataFilePath);
    
    hItem = WM_GetDialogItem(hWin_SWRB_MAIN, ID_MAIN_EDIT_SN);
    EDIT_SetText(hItem, swrbTestDataFilePath);
    
    sprintf(dest_str, "%s", swrbTestDataFilePath);
    
    myfree(SRAMIN, swrbTestDataFilePath);
}
// USER END

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) {
    WM_HWIN hItem;
    int     NCode;
    int     Id;
    // USER START (Optionally insert additional variables)
    int     i;
    // USER END

    switch (pMsg->MsgId) {
        case WM_INIT_DIALOG:
            //
            // Initialization of 'SettingDLG'
            //
            hItem = pMsg->hWin;
            FRAMEWIN_SetTextColor(hItem, 0x00000000);
            //
            // Initialization of 'TEXT'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_SET_TEXT_0);
            TEXT_SetFont(hItem, &GUI_Font32_ASCII);
            TEXT_SetTextColor(hItem, GUI_WHITE);
            //
            // Initialization of 'button'
            //
            for(i=ID_SET_BUTTON_CONFIRM;i<=ID_SET_BUTTON_RESERVE3;i++){
                hItem = WM_GetDialogItem(pMsg->hWin, i);
                Button_Init(hItem);
                if(i%2){
                    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, GUI_LIGHTGRAY);
                }else{
                    
                }
            }
            //
            // Initialization of 'lwYear'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_SET_LISTWHEEL_YEAR);
            ListWheel_Init(hItem);
            LISTWHEEL_AddString(hItem, "2015");
            LISTWHEEL_AddString(hItem, "2016");
            LISTWHEEL_AddString(hItem, "2017");
            LISTWHEEL_AddString(hItem, "2018");
            LISTWHEEL_AddString(hItem, "2019");
            LISTWHEEL_AddString(hItem, "2020");
            LISTWHEEL_AddString(hItem, "2021");
            LISTWHEEL_AddString(hItem, "2022");
            LISTWHEEL_AddString(hItem, "2023");
            LISTWHEEL_AddString(hItem, "2024");
            LISTWHEEL_AddString(hItem, "2025");
            //
            // Initialization of 'lwMonth'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_SET_LISTWHEEL_MONTH);
            ListWheel_Init(hItem);
            LISTWHEEL_AddString(hItem, "01");
            LISTWHEEL_AddString(hItem, "02");
            LISTWHEEL_AddString(hItem, "03");
            LISTWHEEL_AddString(hItem, "04");
            LISTWHEEL_AddString(hItem, "05");
            LISTWHEEL_AddString(hItem, "06");
            LISTWHEEL_AddString(hItem, "07");
            LISTWHEEL_AddString(hItem, "08");
            LISTWHEEL_AddString(hItem, "09");
            LISTWHEEL_AddString(hItem, "10");
            LISTWHEEL_AddString(hItem, "11");
            LISTWHEEL_AddString(hItem, "12");
            //
            // Initialization of 'lwDay'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_SET_LISTWHEEL_DAY);
            ListWheel_Init(hItem);
            LISTWHEEL_AddString(hItem, "01");
            LISTWHEEL_AddString(hItem, "02");
            LISTWHEEL_AddString(hItem, "03");
            LISTWHEEL_AddString(hItem, "04");
            LISTWHEEL_AddString(hItem, "05");
            LISTWHEEL_AddString(hItem, "06");
            LISTWHEEL_AddString(hItem, "07");
            LISTWHEEL_AddString(hItem, "08");
            LISTWHEEL_AddString(hItem, "09");
            LISTWHEEL_AddString(hItem, "10");
            LISTWHEEL_AddString(hItem, "11");
            LISTWHEEL_AddString(hItem, "12");
            LISTWHEEL_AddString(hItem, "13");
            LISTWHEEL_AddString(hItem, "14");
            LISTWHEEL_AddString(hItem, "15");
            LISTWHEEL_AddString(hItem, "16");
            LISTWHEEL_AddString(hItem, "17");
            LISTWHEEL_AddString(hItem, "18");
            LISTWHEEL_AddString(hItem, "19");
            LISTWHEEL_AddString(hItem, "20");
            LISTWHEEL_AddString(hItem, "21");
            LISTWHEEL_AddString(hItem, "22");
            LISTWHEEL_AddString(hItem, "23");
            LISTWHEEL_AddString(hItem, "24");
            LISTWHEEL_AddString(hItem, "25");
            LISTWHEEL_AddString(hItem, "26");
            LISTWHEEL_AddString(hItem, "27");
            LISTWHEEL_AddString(hItem, "28");
            LISTWHEEL_AddString(hItem, "29");
            LISTWHEEL_AddString(hItem, "30");
            LISTWHEEL_AddString(hItem, "31");
            //
            // Initialization of 'lwSN1,2,3'
            //
            for(i=ID_SET_LISTWHEEL_SN1;i<=ID_SET_LISTWHEEL_SN3;i++){
                hItem = WM_GetDialogItem(pMsg->hWin, i);
                ListWheel_Init(hItem);
                LISTWHEEL_AddString(hItem, "0");
                LISTWHEEL_AddString(hItem, "1");
                LISTWHEEL_AddString(hItem, "2");
                LISTWHEEL_AddString(hItem, "3");
                LISTWHEEL_AddString(hItem, "4");
                LISTWHEEL_AddString(hItem, "5");
                LISTWHEEL_AddString(hItem, "6");
                LISTWHEEL_AddString(hItem, "7");
                LISTWHEEL_AddString(hItem, "8");
                LISTWHEEL_AddString(hItem, "9");
            }
            //
            // Initialization of 'edit'
            //
            
            for(i=ID_SET_EDIT_COMB;i<=ID_SET_EDIT_SN3;i++){
                hItem = WM_GetDialogItem(pMsg->hWin, i);
                EDIT_SetFont(hItem, GUI_FONT_24_ASCII);
                EDIT_SetTextMode(hItem);
                EDIT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
            }
            hItem = WM_GetDialogItem(pMsg->hWin, ID_SET_EDIT_COMB);
            EDIT_SetMaxLen(hItem, 50);
            // USER START (Optionally insert additional code for further widget initialization)
            WM_HideWin(pMsg->hWin);
            // USER END
            break;
        case WM_NOTIFY_PARENT:
            Id    = WM_GetId(pMsg->hWinSrc);
            NCode = pMsg->Data.v;
            switch(Id) {
                case ID_SET_BUTTON_CONFIRM: // Notifications sent by 'Confirm'
                    switch(NCode) {
                        case WM_NOTIFICATION_CLICKED:
                            // USER START (Optionally insert code for reacting on notification message)
                            // USER END
                            break;
                        case WM_NOTIFICATION_RELEASED:
                            // USER START (Optionally insert code for reacting on notification message)
                            Button_ConfirmProc(pMsg->hWin);
                            // USER END
                            break;
                        // USER START (Optionally insert additional code for further notification handling)
                        // USER END
                    }
                    break;
                case ID_SET_BUTTON_CHECK: // Notifications sent by 'Check'
                    switch(NCode) {
                        case WM_NOTIFICATION_CLICKED:
                            // USER START (Optionally insert code for reacting on notification message)
                            // USER END
                            break;
                        case WM_NOTIFICATION_RELEASED:
                            // USER START (Optionally insert code for reacting on notification message)
                            Button_CheckProc(pMsg->hWin);
                            // USER END
                            break;
                        // USER START (Optionally insert additional code for further notification handling)
                        // USER END
                    }
                    break;
                case ID_SET_BUTTON_RESET: // Notifications sent by 'Reset'
                    switch(NCode) {
                        case WM_NOTIFICATION_CLICKED:
                            // USER START (Optionally insert code for reacting on notification message)
                            // USER END
                            break;
                        case WM_NOTIFICATION_RELEASED:
                            // USER START (Optionally insert code for reacting on notification message)
                            Button_ResetProc(pMsg->hWin);
                            // USER END
                            break;
                        // USER START (Optionally insert additional code for further notification handling)
                        // USER END
                    }
                    break;
                case ID_SET_BUTTON_CANCEL: // Notifications sent by 'Cancel'
                    switch(NCode) {
                        case WM_NOTIFICATION_CLICKED:
                            // USER START (Optionally insert code for reacting on notification message)
                            // USER END
                            break;
                        case WM_NOTIFICATION_RELEASED:
                            // USER START (Optionally insert code for reacting on notification message)
                            Button_CancelProc(pMsg->hWin);
                            // USER END
                            break;
                        // USER START (Optionally insert additional code for further notification handling)
                        // USER END
                    }
                    break;
                case ID_SET_BUTTON_SNSET: // Notifications sent by 'SnSET'
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
                case ID_SET_BUTTON_TIMESET: // Notifications sent by 'TimeSET'
                    switch(NCode) {
                        case WM_NOTIFICATION_CLICKED:
                            // USER START (Optionally insert code for reacting on notification message)
                            // USER END
                            break;
                        case WM_NOTIFICATION_RELEASED:
                            // USER START (Optionally insert code for reacting on notification message)
                            hItem = WM_GetDialogItem(hWin_SWRB_TIMESETTING, ID_TIMESET_BUTTON_TIMESET);
                            BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, GUI_BLACK);
                            BUTTON_SetBkColor(hItem, BUTTON_CI_PRESSED, GUI_BLACK);
                            BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, GUI_WHITE);
                            gSwrbTestSetState = SWRB_TEST_SET_STATE_TIME;
                            WM_HideWin(pMsg->hWin);
                            WM_ShowWin(hWin_SWRB_TIMESETTING);
//                            for(i=0;i<700;i++){
//                                WM_SetWindowPos(hItem, i, 420, 100, 60);
//                            }
                            // USER END
                            break;
                        // USER START (Optionally insert additional code for further notification handling)
                        // USER END
                    }
                    break;
                case ID_SET_LISTWHEEL_YEAR: // Notifications sent by 'lwYear'
                    switch(NCode) {
                        case WM_NOTIFICATION_CLICKED:
                            // USER START (Optionally insert code for reacting on notification message)
                            // USER END
                            break;
                        case WM_NOTIFICATION_RELEASED:
                            // USER START (Optionally insert code for reacting on notification message)

                            // USER END
                            break;
                        case WM_NOTIFICATION_SEL_CHANGED:
                            // USER START (Optionally insert code for reacting on notification message)
                            ListWheel_SelChangeProc(pMsg->hWin, ID_SET_LISTWHEEL_YEAR, ID_SET_EDIT_YEAR);
                            // USER END
                            break;
                        // USER START (Optionally insert additional code for further notification handling)
                        // USER END
                    }
                    break;
                case ID_SET_LISTWHEEL_MONTH: // Notifications sent by 'lwMonth'
                    switch(NCode) {
                        case WM_NOTIFICATION_CLICKED:
                            // USER START (Optionally insert code for reacting on notification message)
                            // USER END
                            break;
                        case WM_NOTIFICATION_RELEASED:
                            // USER START (Optionally insert code for reacting on notification message)
                            // USER END
                            break;
                        case WM_NOTIFICATION_SEL_CHANGED:
                            // USER START (Optionally insert code for reacting on notification message)
                            ListWheel_SelChangeProc(pMsg->hWin, ID_SET_LISTWHEEL_MONTH, ID_SET_EDIT_MONTH);
                            // USER END
                            break;
                        // USER START (Optionally insert additional code for further notification handling)
                        // USER END
                    }
                    break;
                case ID_SET_LISTWHEEL_DAY: // Notifications sent by 'lwDay'
                    switch(NCode) {
                        case WM_NOTIFICATION_CLICKED:
                            // USER START (Optionally insert code for reacting on notification message)
                            // USER END
                            break;
                        case WM_NOTIFICATION_RELEASED:
                            // USER START (Optionally insert code for reacting on notification message)
                            // USER END
                            break;
                        case WM_NOTIFICATION_SEL_CHANGED:
                            // USER START (Optionally insert code for reacting on notification message)
                            ListWheel_SelChangeProc(pMsg->hWin, ID_SET_LISTWHEEL_DAY, ID_SET_EDIT_DAY);
                            // USER END
                            break;
                        // USER START (Optionally insert additional code for further notification handling)
                        // USER END
                    }
                    break;
                case ID_SET_LISTWHEEL_SN1: // Notifications sent by 'lwSN1'
                    switch(NCode) {
                        case WM_NOTIFICATION_CLICKED:
                            // USER START (Optionally insert code for reacting on notification message)
                            // USER END
                            break;
                        case WM_NOTIFICATION_RELEASED:
                            // USER START (Optionally insert code for reacting on notification message)
                            // USER END
                            break;
                        case WM_NOTIFICATION_SEL_CHANGED:
                            // USER START (Optionally insert code for reacting on notification message)
                            ListWheel_SelChangeProc(pMsg->hWin, ID_SET_LISTWHEEL_SN1, ID_SET_EDIT_SN1);
                            // USER END
                            break;
                        // USER START (Optionally insert additional code for further Ids)
                        // USER END
                    }
                    break;
                case ID_SET_LISTWHEEL_SN2: // Notifications sent by 'lwSN2'
                    switch(NCode) {
                        case WM_NOTIFICATION_CLICKED:
                            // USER START (Optionally insert code for reacting on notification message)
                            // USER END
                            break;
                        case WM_NOTIFICATION_RELEASED:
                            // USER START (Optionally insert code for reacting on notification message)
                            // USER END
                            break;
                        case WM_NOTIFICATION_SEL_CHANGED:
                            // USER START (Optionally insert code for reacting on notification message)
                            ListWheel_SelChangeProc(pMsg->hWin, ID_SET_LISTWHEEL_SN2, ID_SET_EDIT_SN2);
                            // USER END
                            break;
                        // USER START (Optionally insert additional code for further Ids)
                        // USER END
                    }
                    break;
                case ID_SET_LISTWHEEL_SN3: // Notifications sent by 'lwSN3'
                    switch(NCode) {
                        case WM_NOTIFICATION_CLICKED:
                            // USER START (Optionally insert code for reacting on notification message)
                            // USER END
                            break;
                        case WM_NOTIFICATION_RELEASED:
                            // USER START (Optionally insert code for reacting on notification message)
                            // USER END
                            break;
                        case WM_NOTIFICATION_SEL_CHANGED:
                            // USER START (Optionally insert code for reacting on notification message)
                            ListWheel_SelChangeProc(pMsg->hWin, ID_SET_LISTWHEEL_SN3, ID_SET_EDIT_SN3);
                            // USER END
                            break;
                        // USER START (Optionally insert additional code for further Ids)
                        // USER END
                    }
                    break;
                }
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
*       CreateSNSettingDLG
*/
WM_HWIN CreateSNSettingDLG(void) {
    WM_HWIN hWin;

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

// USER START (Optionally insert additional public code)
void SWRB_ListWheelLastItemPosGet(WM_HWIN hWin)
{
    WM_HWIN hItem;
    int i;
    u8 j;
    
    for(i=ID_SET_LISTWHEEL_YEAR,j=0;i<=ID_SET_LISTWHEEL_SN3;i++,j++){
        hItem = WM_GetDialogItem(hWin, i);
        lastLwIndex[j] = LISTWHEEL_GetPos(hItem);
    }
}

void SWRB_ListWheelSNInc(WM_HWIN *hWin)
{
    WM_HWIN hItem;
    int     lwItemIndex;
    char    *strSN1,*strSN2,*strSN3;
    char *str;
    
    strSN3 = mymalloc(SRAMIN, sizeof(char)*3);
    strSN2 = mymalloc(SRAMIN, sizeof(char)*3);
    strSN1 = mymalloc(SRAMIN, sizeof(char)*3);
    
    ListWheel_GetText(hWin, ID_SET_LISTWHEEL_SN3, strSN3);
    if(*strSN3 != '9'){
        hItem = WM_GetDialogItem(*hWin, ID_SET_LISTWHEEL_SN3);
        lwItemIndex = LISTWHEEL_GetPos(hItem);
        LISTWHEEL_SetPos(hItem, lwItemIndex+1);
        LISTWHEEL_SetSel(hItem, lwItemIndex+1);
    }else{
        hItem = WM_GetDialogItem(*hWin, ID_SET_LISTWHEEL_SN3);
        LISTWHEEL_SetPos(hItem, 0);
        LISTWHEEL_SetSel(hItem, 0);
        
        ListWheel_GetText(hWin, ID_SET_LISTWHEEL_SN2, strSN2);
        if(*strSN2 != '9'){
            hItem = WM_GetDialogItem(*hWin, ID_SET_LISTWHEEL_SN2);
            lwItemIndex = LISTWHEEL_GetPos(hItem);
            LISTWHEEL_SetPos(hItem, lwItemIndex+1);
            LISTWHEEL_SetSel(hItem, lwItemIndex+1);
        }else{
            hItem = WM_GetDialogItem(*hWin, ID_SET_LISTWHEEL_SN2);
            LISTWHEEL_SetPos(hItem, 0);
            LISTWHEEL_SetSel(hItem, 0);
            
            ListWheel_GetText(hWin, ID_SET_LISTWHEEL_SN1, strSN1);
            if(*strSN1 != '9'){
                hItem = WM_GetDialogItem(*hWin, ID_SET_LISTWHEEL_SN1);
                lwItemIndex = LISTWHEEL_GetPos(hItem);
                LISTWHEEL_SetPos(hItem, lwItemIndex+1);
                LISTWHEEL_SetSel(hItem, lwItemIndex+1);
            }else{
                str = "SerialNumber is larger than 999, return to 0\r\n";
                SWRB_TestDataFileWriteString(str);
                MultiEdit_Add_Text(hWin_SWRB_MAIN, ID_MAIN_MULTIEDIT_MAIN, str);
                hItem = WM_GetDialogItem(*hWin, ID_SET_LISTWHEEL_SN1);
                LISTWHEEL_SetPos(hItem, 0);
                LISTWHEEL_SetSel(hItem, 0);
            }
        }
    }
    
    myfree(SRAMIN, strSN1);
    myfree(SRAMIN, strSN2);
    myfree(SRAMIN, strSN3);
}

FRESULT SWRB_TestDataFileOpen(u8 fileOpenMode)
{
    FRESULT flErr;
    char *pathStr;
    
    pathStr = mymalloc(SRAMIN, sizeof(char)*40);
    *pathStr = 0;
    
    ListWheel_TestDataFilePathGet(hWin_SWRB_SNSETTING, pathStr);
    flErr = f_open(file, pathStr, fileOpenMode);
    myfree(SRAMIN, pathStr);
    f_lseek(file, file->fsize);
    
    return flErr;
}

void SWRB_TestDataSaveToFile(void dataSaveProc(void))
{
    SWRB_TestDataFileOpen(FA_WRITE|FA_OPEN_ALWAYS);
    dataSaveProc();
    f_close(file);
}

void SWRB_TestDataFileWriteSN(WM_HWIN hWin)
{
    char *gSwrbTestSerialNum;
    char *cBuf;
    
    SWRB_TestDataFileOpen(FA_WRITE|FA_OPEN_ALWAYS);

    gSwrbTestSerialNum = mymalloc(SRAMIN, sizeof(char)*50);
    mymemset(gSwrbTestSerialNum, 0, sizeof(char)*50);
    
    *gSwrbTestSerialNum = 0;
    
    cBuf = "\nSerialNumber:";
    
    gSwrbTestSerialNum = strcat(gSwrbTestSerialNum, cBuf);

    SerialNum_Comb(hWin, ID_SET_LISTWHEEL_YEAR, gSwrbTestSerialNum);
    SerialNum_Comb(hWin, ID_SET_LISTWHEEL_MONTH, gSwrbTestSerialNum);
    SerialNum_Comb(hWin, ID_SET_LISTWHEEL_DAY, gSwrbTestSerialNum);
    SerialNum_Comb(hWin, ID_SET_LISTWHEEL_SN1, gSwrbTestSerialNum);
    SerialNum_Comb(hWin, ID_SET_LISTWHEEL_SN2, gSwrbTestSerialNum);
    SerialNum_Comb(hWin, ID_SET_LISTWHEEL_SN3, gSwrbTestSerialNum);

    f_printf(file, "%s\r\n", gSwrbTestSerialNum);
//    f_puts(gSwrbTestSerialNum, file);
//    f_puts("\r\n", file);
    
    f_close(file);
    
    myfree(SRAMIN, gSwrbTestSerialNum);
}

void SWRB_SET_ListwheelSnapPosUpdate(void)
{
    int i,j;
    WM_HWIN hItem;
    
    if(gSwrbTestSetState == SWRB_TEST_SET_STATE_SN){
        for(i=ID_SET_LISTWHEEL_YEAR;i<=ID_SET_LISTWHEEL_SN3;i++){
            hItem = WM_GetDialogItem(hWin_SWRB_SNSETTING, i);
            j = LISTWHEEL_GetPos(hItem);
            LISTWHEEL_SetSel(hItem, j);
        }
    }else if(gSwrbTestSetState == SWRB_TEST_SET_STATE_TIME){
        for(i=ID_TIMESET_LISTWHEEL_YEAR;i<=ID_TIMESET_LISTWHEEL_SEC;i++){
            hItem = WM_GetDialogItem(hWin_SWRB_TIMESETTING, i);
            j = LISTWHEEL_GetPos(hItem);
            LISTWHEEL_SetSel(hItem, j);
        }
    }else{
        
    }
}

void SWRB_SET_EditTextUpdate(void)
{
    if(gSwrbTestSetState == SWRB_TEST_SET_STATE_SN){
        Edit_Update(hWin_SWRB_SNSETTING, ID_SET_EDIT_YEAR, ID_SET_EDIT_SN3, ID_SET_LISTWHEEL_YEAR);
    }else if(gSwrbTestSetState == SWRB_TEST_SET_STATE_TIME){
        Edit_Update(hWin_SWRB_TIMESETTING, ID_TIMESET_EDIT_YEAR, ID_TIMESET_EDIT_SEC, ID_TIMESET_LISTWHEEL_YEAR);
    }
}

// USER END

/*************************** End of file ****************************/
