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

#include "eje_logo_char.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/

extern GUI_CONST_STORAGE GUI_BITMAP _bmPCBTestCHN;
extern GUI_CONST_STORAGE GUI_BITMAP _bmPSTestCHN;

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

/*********************************************************************
*
*       _aDialogStart
*/
static const GUI_WIDGET_CREATE_INFO _aDialogStart[] = {
    { WINDOW_CreateIndirect, "Window", ID_START_WINDOW_MAIN, 0, 0, 800, 480, 0, 0x0, 0 },
    { IMAGE_CreateIndirect, "Image", ID_START_IMAGE_LOGO, 272, 32, 255, 62, 0, 0, 0 },
    { TEXT_CreateIndirect, "Title", ID_START_TEXT_TITLE, 225, 100, 350, 35, 0, 0x64, 0 },
    { BUTTON_CreateIndirect, "PCB TEST", ID_START_BUTTON_PCB_TEST, 100, 205, 200, 180, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "POWER STATION", ID_START_BUTTON_POWER_STATION, 500, 205, 200, 180, 0, 0x0, 0 },
    { BUTTON_CreateIndirect, "SLAM", ID_START_BUTTON_SLAM, 300, 205, 200, 180, 0, 0x0, 0 },
//    { BUTTON_CreateIndirect, "Decrypto", ID_START_BUTTON_DECRYPTO, 500, 203, 200, 180, 0, 0x0, 0 },
    { TEXT_CreateIndirect, "Text", ID_START_TEXT_VERSION, 600, 430, 200, 50, 0, 0x64, 0 },
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
static const void * _GetImageById(U32 Id, U32 * pSize)
{
    switch (Id) {
        case ID_START_IMAGE_EJE_LOGO:
            *pSize = sizeof(_acImage_eje_logo);
            return (const void *)_acImage_eje_logo;
    }
    return NULL;
}

static void Button_Init(WM_HWIN hItem)
{
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetSkinClassic(hItem);
    WIDGET_SetEffect(hItem, &WIDGET_Effect_Simple);
}

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg)
{
    const void * pData;
    WM_HWIN      hItem;
    U32          FileSize;
    int          NCode;
    int          Id;

    switch (pMsg->MsgId) {
        case WM_INIT_DIALOG:
            //
            // Initialization of 'Image'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_START_IMAGE_LOGO);
            pData = _GetImageById(ID_START_IMAGE_EJE_LOGO, &FileSize);
            IMAGE_SetBMP(hItem, pData, FileSize);
            //
            // Initialization of 'btnPCB TEST'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_START_BUTTON_PCB_TEST);
            BUTTON_SetText(hItem, " ");
            BUTTON_Set_Bitmap_Ex(pMsg->hWin, ID_START_BUTTON_PCB_TEST, &_bmPCBTestCHN, 36, 74);
            Button_Init(hItem);
            //
            // Initialization of 'btnPOWER STATION'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_START_BUTTON_POWER_STATION);
            BUTTON_SetText(hItem, " ");
            BUTTON_Set_Bitmap_Ex(pMsg->hWin, ID_START_BUTTON_POWER_STATION, &_bmPSTestCHN, 20, 74);
            Button_Init(hItem);
            //
            // Initialization of 'btnSLAM'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_START_BUTTON_SLAM);
            BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
            BUTTON_SetText(hItem, "SLAM");
            Button_Init(hItem);
            WM_HideWin(hItem);
            //
            // Initialization of 'DECRYPTO'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_START_BUTTON_DECRYPTO);
            BUTTON_SetText(hItem, "Decrypto");
            Button_Init(hItem);
            //
            // Initialization of 'Title'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_START_TEXT_TITLE);
            TEXT_SetFont(hItem, GUI_FONT_32_ASCII);
            TEXT_SetTextColor(hItem, GUI_BLUE);
            TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
            TEXT_SetText(hItem, "SweepRobot Test System");
            WM_BringToTop(hItem);
            //
            // Initialization of 'Text'
            //
            hItem = WM_GetDialogItem(pMsg->hWin, ID_START_TEXT_VERSION);
            TEXT_SetFont(hItem, GUI_FONT_20_ASCII);
            TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
            TEXT_SetText(hItem, "SWRB Fixture Ver:1.0");
            break;
        case WM_NOTIFY_PARENT:
            Id    = WM_GetId(pMsg->hWinSrc);
            NCode = pMsg->Data.v;
            switch(Id) {
                case ID_START_BUTTON_PCB_TEST: // Notifications sent by 'PCB TEST'
                    switch(NCode) {
                        case WM_NOTIFICATION_CLICKED:
                            break;
                        case WM_NOTIFICATION_RELEASED:
                            SweepRobot_StartDlgPCBBtnClickProc();
                            break;
                    }
                    break;
                case ID_START_BUTTON_POWER_STATION: // Notifications sent by 'POWER STATION'
                    switch(NCode) {
                        case WM_NOTIFICATION_CLICKED:
                            break;
                        case WM_NOTIFICATION_RELEASED:
                            SweepRobot_StartDlgPowerStationBtnClickPorc();
                            break;
                    }
                    break;
                case ID_START_BUTTON_SLAM: // Notifications sent by 'SLAM'
                    switch(NCode) {
                        case WM_NOTIFICATION_CLICKED:
                            break;
                        case WM_NOTIFICATION_RELEASED:
                            SweepRobot_StartDlgSLAMBtnClickProc();
                            break;
                    }
                    break;
                case ID_START_BUTTON_DECRYPTO: // Notifications sent by 'Decrypto'
                    switch(NCode) {
                        case WM_NOTIFICATION_CLICKED:
                            break;
                        case WM_NOTIFICATION_RELEASED:
//                            SweepRobot_StartDlgDecryptoBtnClickPorc();
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

WM_HWIN hWin_SWRB_START;

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
WM_HWIN CreateEJE_SWRB_TEST_StartDLG(void) {
    WM_HWIN hWin;

    hWin = GUI_CreateDialogBox(_aDialogStart, GUI_COUNTOF(_aDialogStart), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

/*************************** End of file ****************************/
