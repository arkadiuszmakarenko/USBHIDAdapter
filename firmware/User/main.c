#include <usb_gamepad.h>
#include <usb_mouse.h>
#include "usb_host_config.h"
#include "utils.h"
#include "tim.h"
#include "mouse.h"
#include "gpio.h"
#include "gamepad.h"

int main( void )
{
    Delay_Init( );
    TIM3_Init( 9, SystemCoreClock / 10000 - 1 );

#if DEF_USBFS_PORT_EN
    USBFS_RCC_Init( );
    USBFS_Host_Init( ENABLE );
    memset( &RootHubDev.bStatus, 0, sizeof( ROOT_HUB_DEVICE ) );
    memset( &HostCtl[ DEF_USBFS_PORT_INDEX * DEF_ONE_USB_SUP_DEV_TOTAL ].InterfaceNum, 0, DEF_ONE_USB_SUP_DEV_TOTAL * sizeof( HOST_CTL ) );
#endif

    TIM2_Init();
    TIM4_Init();
    GPIO_Config();
    InitMouse();

	while (1) {
		USBH_MainDeal();

		//Handle HID Device
		if (RootHubDev.bType == USB_DEV_CLASS_HID) {

			for (int itf = 0; itf < DEF_INTERFACE_NUM_MAX; itf++) {
				//Handle mouse
				if (HostCtl[0].Interface[itf].HIDRptDesc.type
						== REPORT_TYPE_MOUSE) {
					HID_MOUSE_Info_TypeDef *mousemap = USBH_GetMouseInfo(
							&HostCtl[0].Interface[itf]);
					ProcessMouse(mousemap);
				}

				//Handle gamepad
				if (HostCtl[0].Interface[itf].HIDRptDesc.type
						== REPORT_TYPE_JOYSTICK) {

		HID_gamepad_Info_TypeDef *gamepad = GetGamepadInfo(
							&HostCtl[0].Interface[itf]);
						ProcessGamepad(gamepad);
				}
			}
		}
	}
}
