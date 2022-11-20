/**
 * @file diskio_flash.c
 *  flash driver support
 */

#include "ff.h"
#include "diskio.h"

#include "flash_spi.h"


#define DEV_FLASH           0
#define DISK_SECTOR_SIZE    4096


/*-----------------------------------------------------------------------*/
/* Get Drive Status                                                      */
/*-----------------------------------------------------------------------*/
DSTATUS disk_status(BYTE pdrv)
{
    (void)pdrv;
    return RES_OK;
}

/*-----------------------------------------------------------------------*/
/* Inidialize a Drive                                                    */
/*-----------------------------------------------------------------------*/
DSTATUS disk_initialize(BYTE pdrv)
{
    (void)pdrv;
    return RES_OK;
}

/*-----------------------------------------------------------------------*/
/* Read Sector(s)                                                        */
/*-----------------------------------------------------------------------*/
DRESULT disk_read(BYTE pdrv, BYTE *buff, LBA_t sector, UINT count)
{
    flash_read_block(sector*EXTERNAL_FLASH_SECTOR_SIZE, buff, count*EXTERNAL_FLASH_SECTOR_SIZE);
	return RES_OK;
}

/*-----------------------------------------------------------------------*/
/* Write Sector(s)                                                       */
/*-----------------------------------------------------------------------*/

#if FF_FS_READONLY == 0

DRESULT disk_write(BYTE pdrv, const BYTE *buff, LBA_t sector, UINT count)
{
    flash_write_block(sector*EXTERNAL_FLASH_SECTOR_SIZE, buff, count*EXTERNAL_FLASH_SECTOR_SIZE);
    return RES_OK;
}

#endif


/*-----------------------------------------------------------------------*/
/* Miscellaneous Functions                                               */
/*-----------------------------------------------------------------------*/
DRESULT disk_ioctl(BYTE pdrv, BYTE cmd, void *buff)
{
    return RES_OK;
}

