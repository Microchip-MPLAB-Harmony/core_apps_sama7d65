/*******************************************************************************
  MPLAB Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB application.

  Description:
    This file contains the source code for the MPLAB application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <string.h>
#include "app.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

static APP_DATA appData;

static uint16_t blockNum = 3;
static uint16_t pageNum = 0;
static char *ptrReadId = 0;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/* TODO:  Add any necessary local functions.
*/


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize ( void )
{
    uint32_t i = 0;

    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;

    for (i = 0; i < PAGE_SIZE; i++)
    {
        appData.writeBuffer[i] = i;
    }

}


/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks ( void )
{
    /* Check the application's current state. */
    switch ( appData.state )
    {
        /* Application's initial state. */
        case APP_STATE_INIT:
        {
            if (DRV_NAND_FLASH_Status(DRV_NAND_FLASH_INDEX) == SYS_STATUS_READY)
            {
                appData.state = APP_STATE_OPEN_DRIVER;
            }
            break;
        }
        case APP_STATE_OPEN_DRIVER:
        {
            appData.handle = DRV_NAND_FLASH_Open((SYS_MODULE_INDEX)DRV_NAND_FLASH_INDEX, DRV_IO_INTENT_READWRITE);

            if (appData.handle != DRV_HANDLE_INVALID)
            {
                appData.state = APP_STATE_ID_GET;
            }
            break;
        }
        case APP_STATE_ID_GET:
        {
            if (DRV_NAND_FLASH_IdRead(appData.handle, &appData.readId, NAND_FLASH_ADDR_ONFI_SIGNATURE) != true)
            {
                appData.state = APP_STATE_ERROR;
            }
            else
            {
                ptrReadId = (char *)&appData.readId;
                if (ptrReadId[0] == 'O' && ptrReadId[1] == 'N' && ptrReadId[2] == 'F' && ptrReadId[3] == 'I')
                {
                    appData.state = APP_STATE_GEOMETRY_GET;
                }
            }
            break;
        }
        case APP_STATE_GEOMETRY_GET:
        {
            if (DRV_NAND_FLASH_GeometryGet(appData.handle, &appData.geometry) != true)
            {
                appData.state = APP_STATE_ERROR;
            }
            else
            {
                appData.state = APP_STATE_ERASE_FLASH;
            }
            break;
        }

        case APP_STATE_ERASE_FLASH:
        {
            if (DRV_NAND_FLASH_SkipBlock_BlockErase(appData.handle, blockNum, 0) != true)
            {
                appData.state = APP_STATE_ERROR;
            }
            else
            {
                appData.state = APP_STATE_WRITE_MEMORY;
            }
            break;
        }
        case APP_STATE_WRITE_MEMORY:
        {
            if (DRV_NAND_FLASH_SkipBlock_PageWrite(appData.handle, blockNum, pageNum, appData.writeBuffer, 0, false) != true)
            {
                appData.state = APP_STATE_ERROR;
            }
            else
            {
                appData.state = APP_STATE_READ_MEMORY;
            }
            break;
        }
        case APP_STATE_READ_MEMORY:
        {
            if (DRV_NAND_FLASH_SkipBlock_PageRead(appData.handle, blockNum, pageNum, appData.readBuffer, 0, false) != true)
            {
                appData.state = APP_STATE_ERROR;
            }
            else
            {
                appData.state = APP_STATE_VERIFY_DATA;
            }
            break;
        }
        case APP_STATE_VERIFY_DATA:
        {
            if (!memcmp(appData.writeBuffer, appData.readBuffer, appData.geometry.pageSize))
            {
                appData.state = APP_STATE_SUCCESS;
            }
            else
            {
                appData.state = APP_STATE_ERROR;
            }
            break;
        }

        case APP_STATE_SUCCESS:
        {
            LED_ON();
            break;
        }

        case APP_STATE_ERROR:
        default:
            LED_OFF();
    }
}



/*******************************************************************************
 End of File
 */
