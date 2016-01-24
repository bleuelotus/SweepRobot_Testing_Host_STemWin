/*-----------------------------------------------------------------------*/
/* Low level disk I/O module skeleton for FatFs     (C)ChaN, 2013        */
/*-----------------------------------------------------------------------*/
/* If a working storage control module is available, it should be        */
/* attached to the FatFs via a glue function rather than modifying it.   */
/* This is an example of glue functions to attach various exsisting      */
/* storage control module to the FatFs module with a defined API.        */
/*-----------------------------------------------------------------------*/

#include "diskio.h"        /* FatFs lower layer API */
#include "sdio_sdcard.h"
#include "w25qxx.h"
#include "malloc.h"
#include "usbh_usr.h"

#define SD_CARD     0
#define EX_FLASH    1
#define USB_DISK    2

#define FLASH_SECTOR_SIZE       512

u16 FLASH_SECTOR_COUNT = 2048*12;
#define FLASH_BLOCK_SIZE        8

DSTATUS disk_initialize (
    BYTE pdrv                /* Physical drive nmuber (0..) */
)
{
    u8 res=0;
    switch(pdrv)
    {
        case SD_CARD:
            res=SD_Init();
            break;
        case EX_FLASH:
            W25QXX_Init();
            FLASH_SECTOR_COUNT=2048*12;
            break;
        case USB_DISK:
            if(USBH_UDISK_Status())
                return 0;
            else
                return 1;
        default:
            res=1;
    }
    if(res)
        return  STA_NOINIT;
    else
        return 0;
}

//获得磁盘状态
DSTATUS disk_status (
    BYTE pdrv        /* Physical drive nmuber (0..) */
)
{
    return 0;
}

//读扇区
//drv:磁盘编号0~9
//*buff:数据接收缓冲首地址
//sector:扇区地址
//count:需要读取的扇区数
DRESULT disk_read (
    BYTE pdrv,        /* Physical drive nmuber (0..) */
    BYTE *buff,        /* Data buffer to store read data */
    DWORD sector,    /* Sector address (LBA) */
    UINT count        /* Number of sectors to read (1..128) */
)
{
    u8 res=0;
    if (!count)return RES_PARERR;//count不能等于0，否则返回参数错误
    switch(pdrv)
    {
        case SD_CARD://SD卡
            res=SD_ReadDisk(buff,sector,count);
            while(res)//读出错
            {
                SD_Init();    //重新初始化SD卡
                res=SD_ReadDisk(buff,sector,count);
                //printf("sd rd error:%d\r\n",res);
            }
            break;
        case EX_FLASH://外部flash
            for(;count>0;count--)
            {
                W25QXX_Read(buff,sector*FLASH_SECTOR_SIZE,FLASH_SECTOR_SIZE);
                sector++;
                buff+=FLASH_SECTOR_SIZE;
            }
            res=0;
            break;
        case USB_DISK://U盘
            res=USBH_UDISK_Read(buff,sector,count);
            break;
        default:
            res=1;
    }
   //处理返回值，将SPI_SD_driver.c的返回值转成ff.c的返回值
    if(res==0x00)return RES_OK;
    else return RES_ERROR;
}

//写扇区
//drv:磁盘编号0~9
//*buff:发送数据首地址
//sector:扇区地址
//count:需要写入的扇区数
#if _USE_WRITE
DRESULT disk_write (
    BYTE pdrv,            /* Physical drive nmuber (0..) */
    const BYTE *buff,    /* Data to be written */
    DWORD sector,        /* Sector address (LBA) */
    UINT count            /* Number of sectors to write (1..128) */
)
{
    u8 res=0;
    if (!count)return RES_PARERR;//count不能等于0，否则返回参数错误
    switch(pdrv)
    {
        case SD_CARD://SD卡
            res=SD_WriteDisk((u8*)buff,sector,count);
            while(res)//写出错
            {
                SD_Init();    //重新初始化SD卡
                res=SD_WriteDisk((u8*)buff,sector,count);
                //printf("sd wr error:%d\r\n",res);
            }
            break;
        case EX_FLASH://外部flash
            for(;count>0;count--)
            {
                W25QXX_Write((u8*)buff,sector*FLASH_SECTOR_SIZE,FLASH_SECTOR_SIZE);
                sector++;
                buff+=FLASH_SECTOR_SIZE;
            }
            res=0;
            break;
        case USB_DISK://U盘
            res=USBH_UDISK_Write((u8*)buff,sector,count);
            break;
        default:
            res=1;
    }
    //处理返回值，将SPI_SD_driver.c的返回值转成ff.c的返回值
    if(res == 0x00)return RES_OK;
    else return RES_ERROR;
}
#endif


//其他表参数的获得
 //drv:磁盘编号0~9
 //ctrl:控制代码
 //*buff:发送/接收缓冲区指针
#if _USE_IOCTL
DRESULT disk_ioctl (
    BYTE pdrv,        /* Physical drive nmuber (0..) */
    BYTE cmd,        /* Control code */
    void *buff        /* Buffer to send/receive control data */
)
{
    DRESULT res;
    if(pdrv==SD_CARD)//SD卡
    {
        switch(cmd)
        {
            case CTRL_SYNC:
                res = RES_OK;
                break;
            case GET_SECTOR_SIZE:
                *(DWORD*)buff = 512;
                res = RES_OK;
                break;
            case GET_BLOCK_SIZE:
                *(WORD*)buff = SDCardInfo.CardBlockSize;
                res = RES_OK;
                break;
            case GET_SECTOR_COUNT:
                *(DWORD*)buff = SDCardInfo.CardCapacity/512;
                res = RES_OK;
                break;
            default:
                res = RES_PARERR;
                break;
        }
    }else if(pdrv==EX_FLASH)    //外部FLASH
    {
        switch(cmd)
        {
            case CTRL_SYNC:
                res = RES_OK;
                break;
            case GET_SECTOR_SIZE:
                *(WORD*)buff = FLASH_SECTOR_SIZE;
                res = RES_OK;
                break;
            case GET_BLOCK_SIZE:
                *(WORD*)buff = FLASH_BLOCK_SIZE;
                res = RES_OK;
                break;
            case GET_SECTOR_COUNT:
                *(DWORD*)buff = FLASH_SECTOR_COUNT;
                res = RES_OK;
                break;
            default:
                res = RES_PARERR;
                break;
        }
    }else if(pdrv==USB_DISK)    //U盘
    {
        switch(cmd)
        {
            case CTRL_SYNC:
                res = RES_OK;
                break;
            case GET_SECTOR_SIZE:
                *(WORD*)buff=512;
                res = RES_OK;
                break;
            case GET_BLOCK_SIZE:
                *(WORD*)buff=512;
                res = RES_OK;
                break;
            case GET_SECTOR_COUNT:
                *(DWORD*)buff=USBH_MSC_Param.MSCapacity;
                res = RES_OK;
                break;
            default:
                res = RES_PARERR;
                break;
        }
    }else res=RES_ERROR;
    return res;
}
#endif

//User defined function to give a current time to fatfs module      */
//31-25: Year(0-127 org.1980), 24-21: Month(1-12), 20-16: Day(1-31) */
//15-11: Hour(0-23), 10-5: Minute(0-59), 4-0: Second(0-29 *2) */
DWORD get_fattime (void)
{
    return 0;
}

void *ff_memalloc (UINT size)
{
    return (void*)mymalloc(SRAMIN,size);
}

void ff_memfree (void* mf)
{
    myfree(SRAMIN,mf);
}
