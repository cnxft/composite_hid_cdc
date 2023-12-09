#include "usb_hid_driver.h"

//extern uint8_t CDC_Transmit_FS(uint8_t* Buf, uint16_t Len);
/*
    键盘
    第二位
    0 LEFT CTRL
    1 LEFT SHIFT
    2 LEFT ALT
    3 LEFT GUI
    4 RIGHT CTRL
    5 RIGHT SHIFT
    6 RIGHT ALT
    7 RIGHT GUI

uint8_t buff_Key[9] = {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

多媒体
uint8_t buff_Audio[2] = {0x02, 0x00};

鼠标
uint8_t buff_Mouse[5] = {0x03, 0x00, 0x00, 0x00, 0x00};
*/

//uint8_t buff_Key1[9] = {0x01, 0x00, 0x00, 0x0A, 0x04, 0x00, 0x00, 0x00, 0x00};
//uint8_t buff_Key2[9] = {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

extern USBD_HandleTypeDef hUsbDeviceFS;
//extern USBD_CUSTOM_HID_HandleTypeDef usbd_custom_hid_handle;
extern uint8_t USBD_CUSTOM_HID_SendReport(USBD_HandleTypeDef *pdev, uint8_t *report, uint16_t len);

// HID
void Send_USB_Buff(uint8_t *buff, uint8_t size)
{
    while(USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, buff, size));
}
/**
 * @brief 
 *
 *
 */
void USBinterpret(uint8_t *p)
{
	uint8_t buff_all[9] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};//hid最终发送的数组
	uint8_t buff_size = 0;//buff的大小键盘9 多媒体2 鼠标5
	uint8_t time_flag = '0';//保存第一位，1：是按下，不抬起
	time_flag = *p;
	
	p++;
	switch (*p)
	{
	case '1':
			/* code */
			{
					buff_all[0] = 0x01; //键盘
					buff_size = 9;
			}
			break;
	case '2':
			/* code */
			{
					buff_all[0] = 0x02; //多媒体
					buff_size = 2;
			}
			break;
	case '3':
			/* code */
			{
					buff_all[0] = 0x03; // 鼠标
					buff_size = 5;
			}
			break;
	default:
			break;
	}
	for (size_t i = 1; i < buff_size; i++)
	{
			/* code */
			p++;
			buff_all[i] += (*p < 0x40) ? (*p % 0x30 * 0x10) : (*p % 0x37 * 0x10);
			p++;
			buff_all[i] += (*p < 0x40) ? (*p % 0x30) : (*p % 0x37);
	}
	Send_USB_Buff(buff_all, buff_size);
	
	if (time_flag == '0')
	{
			/* code */
			for (size_t i = 1; i < buff_size; i++)
			{
					buff_all[i] = 0x00;
			}
			Send_USB_Buff(buff_all, buff_size);
	}
}

//void send_usbd_a(void)
//{
//    USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, buff_Key1, 9);
//    HAL_Delay(100);
//    USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, buff_Key2, 9);
//    HAL_Delay(1000);
//}

/*

*/
