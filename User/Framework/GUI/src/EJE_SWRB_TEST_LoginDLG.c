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

#include "EJE_SWRB_TEST_LoginDLG.h"

#include "sweeprobot_testing.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/

#define IS_LOGIN_BUTTON_ID_NUM(ID)        ( ( ID == ID_LOGIN_BUTTON_NUM0 ) ||\
                                            ( ID == ID_LOGIN_BUTTON_NUM1 ) ||\
                                            ( ID == ID_LOGIN_BUTTON_NUM2 ) ||\
                                            ( ID == ID_LOGIN_BUTTON_NUM3 ) ||\
                                            ( ID == ID_LOGIN_BUTTON_NUM4 ) ||\
                                            ( ID == ID_LOGIN_BUTTON_NUM5 ) ||\
                                            ( ID == ID_LOGIN_BUTTON_NUM6 ) ||\
                                            ( ID == ID_LOGIN_BUTTON_NUM7 ) ||\
                                            ( ID == ID_LOGIN_BUTTON_NUM8 ) ||\
                                            ( ID == ID_LOGIN_BUTTON_NUM9 ) )

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

static char* gSetDlgLoginPasswd = "123";
static char* gUdiskInsertCmpSkipPasswd = "456";
#ifdef USE_DECRYPTO
static char* gDecryptDlgLoginPasswd  = "0549832761";
#endif
#ifdef USE_SLAM
static char* gSLAMDlgLoginPasswd = "167238";
#endif
#ifdef USE_STEPMOTOR_CTRL
static char* gStepMotorLoginPasswd = "054983";
#endif
#ifdef USE_STEERMOTOR_CTRL
static char* gSteerMotorLoginPasswd = "832761";
#endif
#ifdef USE_RELAY_CTRL
static char* gRelayCtrlLoginPasswd = "387216";
#endif
static char* gManulTestEnterManulModePasswd = "123456";
static const char * gSetTimeConfirmPasswd = "123876";

static char strPasswd[10] = { 0 };
static u8 strPasswdLen = 0;

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { FRAMEWIN_CreateIndirect, "fwinLogin", ID_LOGIN_FRAMEWIN_MAIN, 0, 0, 600, 300, 0, 0x64, 0 },
  { EDIT_CreateIndirect, "Edit", ID_LOGIN_EDIT_PASSWORD, 20, 20, 380, 60, 0, 0x64, 0 },
//  { TEXT_CreateIndirect, "Text", ID_LOGIN_TEXT_PASSWORD, 30, 40, 200, 40, 0, 0x64, 0 },
  { BUTTON_CreateIndirect, "btnLoginOK", ID_LOGIN_BUTTON_OK, 440, 20, 120, 60, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btnDelete", ID_LOGIN_BUTTON_DELETE, 440, 110, 120, 60, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btnLoginCancel", ID_LOGIN_BUTTON_CANCEL, 440, 200, 120, 60, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btn1", ID_LOGIN_BUTTON_NUM1, 20, 110, 60, 60, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btn2", ID_LOGIN_BUTTON_NUM2, 100, 110, 60, 60, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btn3", ID_LOGIN_BUTTON_NUM3, 180, 110, 60, 60, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btn4", ID_LOGIN_BUTTON_NUM4, 260, 110, 60, 60, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btn5", ID_LOGIN_BUTTON_NUM5, 340, 110, 60, 60, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btn6", ID_LOGIN_BUTTON_NUM6, 20, 200, 60, 60, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btn7", ID_LOGIN_BUTTON_NUM7, 100, 200, 60, 60, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btn8", ID_LOGIN_BUTTON_NUM8, 180, 200, 60, 60, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btn9", ID_LOGIN_BUTTON_NUM9, 260, 200, 60, 60, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "btn0", ID_LOGIN_BUTTON_NUM0, 340, 200, 60, 60, 0, 0x0, 0 },
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

static void Button_Init(WM_HWIN hItem)
{
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
}

static void Login_PasswdClearProc(void)
{
    WM_HWIN hItem;

    hItem = WM_GetDialogItem(hWin_SWRB_LOGIN, ID_LOGIN_EDIT_PASSWORD);
    do{
        EDIT_AddKey(hItem, '\b');
        strPasswdLen--;
        strPasswd[strPasswdLen] = 0;
    }while(strPasswdLen);
}

static void Button_OKProc(void)
{
    if(gSwrbDialogSelectFlag == SWRB_DIALOG_SELECT_MANUL){
        if(!(strcmp(strPasswd,gManulTestEnterManulModePasswd))){
            SweepRobot_ManulSetBtnEnterManulModeProc();

            FRAMEWIN_SetClientColor(hWin_SWRB_LOGIN, GUI_LIGHTGRAY);

            WM_HideWin(hWin_SWRB_LOGIN);
            WM_ShowWin(hWin_SWRB_MANUL);
        }else{
            FRAMEWIN_SetClientColor(hWin_SWRB_LOGIN, GUI_LIGHTRED);
        }
    }else if (gSwrbDialogSelectFlag == SWRB_DIALOG_SELECT_NONE){
        if(!(strcmp(strPasswd,gSetDlgLoginPasswd))){

            gSwrbDialogSelectFlag = SWRB_DIALOG_SELECT_SET;

            gSwrbTestSetSelectFlag = SWRB_TEST_SET_SELECT_TESTSEL;

            FRAMEWIN_SetClientColor(hWin_SWRB_LOGIN, GUI_LIGHTGRAY);

//            Button_Set_BkColor(hWin_SWRB_SNSET, ID_SNSET_BUTTON_SNSET, GUI_LIGHTRED);
            Button_Set_BkColor(hWin_SWRB_TESTSEL, ID_TESTSEL_BUTTON_TESTSEL, GUI_LIGHTRED);

            SWRB_ListWheelLastItemPosGet();
            SWRB_TestTaskCheckBoxLastStateSave();

            WM_HideWin(hWin_SWRB_LOGIN);
            WM_HideWin(hWin_SWRB_START);
            WM_ShowWin(hWin_SWRB_TESTSEL);
#ifdef USE_DECRYPTO
        }else if(!(strcmp(strPasswd,gDecryptDlgLoginPasswd))){
            WM_HideWin(hWin_SWRB_LOGIN);
            WM_HideWin(hWin_SWRB_START);
            WM_ShowWin(hWin_SWRB_DECRYPTO);
#endif
#ifdef USE_SLAM
        }else if(!(strcmp(strPasswd,gSLAMDlgLoginPasswd))){
            WM_HideWin(hWin_SWRB_LOGIN);
            WM_HideWin(hWin_SWRB_START);
            WM_ShowWin(hWin_SWRB_SLAM);
#endif
#ifdef USE_STEPMOTOR_CTRL
        }else if(!(strcmp(strPasswd,gStepMotorLoginPasswd))){
            STEP_MOTOR_ISR_CB_REG(StepMotorTest_PosStepCntDisp);
            WM_HideWin(hWin_SWRB_LOGIN);
            WM_HideWin(hWin_SWRB_START);
            WM_ShowWin(hWin_SWRB_STEPMOTOR);
#endif
#ifdef USE_STEERMOTOR_CTRL
        }else if(!(strcmp(strPasswd,gSteerMotorLoginPasswd))){
            WM_HideWin(hWin_SWRB_LOGIN);
            WM_HideWin(hWin_SWRB_START);
            WM_ShowWin(hWin_SWRB_STEERMOTOR);
#endif
#ifdef USE_RELAY_CTRL
        }else if(!(strcmp(strPasswd,gRelayCtrlLoginPasswd))){
            WM_HideWin(hWin_SWRB_LOGIN);
            WM_HideWin(hWin_SWRB_START);
            WM_ShowWin(hWin_SWRB_RELAY);
#endif
        }else if(!(strcmp(strPasswd,gUdiskInsertCmpSkipPasswd))){
            if(gSwrbTestUDiskInsertCmpSkipFlag){
                gSwrbTestUDiskInsertCmpSkipFlag = DISABLE;
            }else{
                gSwrbTestUDiskInsertCmpSkipFlag = ENABLE;
            }
            WM_HideWin(hWin_SWRB_LOGIN);
        }else{
            FRAMEWIN_SetClientColor(hWin_SWRB_LOGIN, GUI_LIGHTRED);
        }

        Login_PasswdClearProc();
    }else if ( (gSwrbDialogSelectFlag == SWRB_DIALOG_SELECT_SET) && (gSwrbTestSetSelectFlag == SWRB_TEST_SET_SELECT_TIME) ){
        if(!(strcmp(strPasswd,gSetTimeConfirmPasswd))){
            SWRB_TimeSettingsChangeConfirmProc();

            WM_HideWin(hWin_SWRB_LOGIN);
            WM_HideWin(hWin_SWRB_TIMESET);
            WM_ShowWin(hWin_SWRB_START);
        }else{
            FRAMEWIN_SetClientColor(hWin_SWRB_LOGIN, GUI_LIGHTRED);
        }
    }
}

static void Button_CancelProc(void)
{
    if(gSwrbDialogSelectFlag == SWRB_DIALOG_SELECT_MANUL){

        SWRB_WM_EnableWindow(hWin_SWRB_MANUL, ID_MANUL_BUTTON_START);
        SWRB_WM_EnableWindow(hWin_SWRB_MANUL, ID_MANUL_BUTTON_SET);
        SWRB_WM_EnableWindow(hWin_SWRB_MANUL, ID_MANUL_BUTTON_EXIT);

        WM_HideWin(hWin_SWRB_LOGIN);
        WM_ShowWin(hWin_SWRB_MANUL);
        WM_BringToTop(hWin_SWRB_MANUL);
    }else if (gSwrbDialogSelectFlag == SWRB_DIALOG_SELECT_NONE){
        gSwrbDialogSelectFlag = SWRB_DIALOG_SELECT_NONE;

        WM_HideWin(hWin_SWRB_LOGIN);
        WM_ShowWin(hWin_SWRB_START);
        WM_BringToTop(hWin_SWRB_START);
    }else if ( (gSwrbDialogSelectFlag == SWRB_DIALOG_SELECT_SET) && (gSwrbTestSetSelectFlag == SWRB_TEST_SET_SELECT_TIME) ){
        WM_HideWin(hWin_SWRB_LOGIN);
        WM_ShowWin(hWin_SWRB_TIMESET);
        WM_BringToTop(hWin_SWRB_TIMESET);
    }
}

static void Button_DeleteProc(void)
{
    WM_HWIN hItem;

    hItem = WM_GetDialogItem(hWin_SWRB_LOGIN, ID_LOGIN_EDIT_PASSWORD);
    EDIT_AddKey(hItem, '\b');
    if(strPasswdLen){
        strPasswdLen--;
        strPasswd[strPasswdLen] = 0;
    }
}

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;
  int     NCode;
  int     Id;
  int     i;
  char    *str;

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
    //
    // Initialization of 'fwinLogin'
    //
    hItem = pMsg->hWin;
    FRAMEWIN_SetFont(hItem, GUI_FONT_16_ASCII);
    FRAMEWIN_SetText(hItem, "Login");
    //
    // Initialization of 'btnLoginOK'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_LOGIN_BUTTON_OK);
//    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
//    BUTTON_SetText(hItem, "OK");
    BUTTON_DispConfirmCHNStr(pMsg->hWin, ID_LOGIN_BUTTON_OK, 28, 13);
    //
    // Initialization of 'btnLoginCancel'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_LOGIN_BUTTON_CANCEL);
//    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
//    BUTTON_SetText(hItem, "CANCEL");
    BUTTON_DispCancelCHNStr(pMsg->hWin, ID_LOGIN_BUTTON_CANCEL, 28 ,13);

    hItem = WM_GetDialogItem(pMsg->hWin, ID_LOGIN_BUTTON_DELETE);
//    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
//    BUTTON_SetText(hItem, "DEL");
    BUTTON_DispDeleteCHNStr(pMsg->hWin, ID_LOGIN_BUTTON_DELETE, 28 ,13);

    str = mymalloc(SRAMIN, sizeof(char)*5);
    for(i=ID_LOGIN_BUTTON_NUM0;i<=ID_LOGIN_BUTTON_NUM9;i++){
        hItem = WM_GetDialogItem(pMsg->hWin, i);
        Button_Init(hItem);
        *str = 0;
        sprintf(str, "%d", i-ID_LOGIN_BUTTON_NUM0);
        BUTTON_SetText(hItem, str);
    }
    myfree(SRAMIN, str);
    //
    // Initialization of 'Edit'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_LOGIN_EDIT_PASSWORD);
    EDIT_SetText(hItem, "");
    EDIT_SetFont(hItem, GUI_FONT_32_ASCII);
    EDIT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    EDIT_SetBkColor(hItem, EDIT_CI_ENABELD, GUI_WHITE);
    EDIT_SetMaxLen(hItem, 10);
//    //
//    // Initialization of 'Text'
//    //
//    hItem = WM_GetDialogItem(pMsg->hWin, ID_LOGIN_TEXT_PASSWORD);
//    TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
//    TEXT_SetFont(hItem, GUI_FONT_20_ASCII);
//    TEXT_SetText(hItem, "Please input Password");
    /* Hide Window when create */
    WM_HideWin(pMsg->hWin);
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;

    if(IS_LOGIN_BUTTON_ID_NUM(Id)){
        switch(NCode) {
            case WM_NOTIFICATION_CLICKED:
                break;
            case WM_NOTIFICATION_RELEASED:
                hItem = WM_GetDialogItem(pMsg->hWin, ID_LOGIN_EDIT_PASSWORD);
//                EDIT_AddKey(hItem, '0' + (Id-ID_LOGIN_BUTTON_NUM0) );
                EDIT_AddKey(hItem, '*');
                if(strPasswdLen<10){
                    strPasswd[strPasswdLen] = '0'+(Id-ID_LOGIN_BUTTON_NUM0);
                    strPasswdLen++;
                }
                break;
        }
        break;
    }else{
        switch(Id) {
        case ID_LOGIN_BUTTON_OK: // Notifications sent by 'btnLoginOK'
          switch(NCode) {
          case WM_NOTIFICATION_CLICKED:
            break;
          case WM_NOTIFICATION_RELEASED:
            Button_OKProc();
            break;
          }
          break;
        case ID_LOGIN_BUTTON_CANCEL: // Notifications sent by 'btnLoginCancel'
          switch(NCode) {
          case WM_NOTIFICATION_CLICKED:
            break;
          case WM_NOTIFICATION_RELEASED:
            Button_CancelProc();
            break;
          }
          break;
        case ID_LOGIN_BUTTON_DELETE: // Notifications sent by 'btnLoginDelete'
          switch(NCode) {
          case WM_NOTIFICATION_CLICKED:
            break;
          case WM_NOTIFICATION_RELEASED:
            Button_DeleteProc();
            break;
          }
          break;
        case ID_LOGIN_EDIT_PASSWORD: // Notifications sent by 'Edit'
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

    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, hWin_SWRB_PCBTEST, 100, 90);
    return hWin;
}

void SweepRobotTest_LoginEditClear(void)
{
    Login_PasswdClearProc();
}

/*************************** End of file ****************************/
