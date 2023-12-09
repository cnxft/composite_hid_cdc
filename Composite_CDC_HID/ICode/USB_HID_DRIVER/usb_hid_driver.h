/**
 * @file keybrd_mouse.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-08
 * 
 * αװ�����ͼ���
 * 
 * ע�Ᵽ���HID�ļ����µ�usbd_hid.h��usbd_hid.c
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __USB_KEYBOARD_H_
#define __USB_KEYBOARD_H_


#include "stm32f1xx_hal.h" //HAL���ļ�����
#include "main.h"          //IO�������ʼ��������main.c�ļ��У���������
#include "usbd_customhid.h"
#include "usbd_custom_hid_if.h"
// #include <stdarg.h>

// #define BUFF_KEY_SIZE 9
// #define BUFF_Audio_SIZE 2
// #define BUFF_Mouse_SIZE 5


void Send_USB_Buff(uint8_t *buff, uint8_t size);
void USBinterpret(uint8_t* Buf);
//void send_usbd_a(void);

#endif

// char ReportDescriptorKeybrd[63] = {
//     0x05, 0x01,                    // USAGE_PAGE (Generic Desktop)
//     0x09, 0x06,                    // USAGE (Keyboard)
//     0xa1, 0x01,                    // COLLECTION (Application)
//     0x05, 0x07,                    //   USAGE_PAGE (Keyboard)
//     0x19, 0xe0,                    //   USAGE_MINIMUM (Keyboard LeftControl)
//     0x29, 0xe7,                    //   USAGE_MAXIMUM (Keyboard Right GUI)   hid��;���һ�����
//     0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
//     0x25, 0x01,                    //   LOGICAL_MAXIMUM (1)
//     0x75, 0x01,                    //   REPORT_SIZE (1)  �����С ����8��
//     0x95, 0x08,                    //   REPORT_COUNT (8)
//     0x81, 0x02,                    //   INPUT (Data,Var,Abs)
//     0x95, 0x01,                    //   REPORT_COUNT (1)
//     0x75, 0x08,                    //   REPORT_SIZE (8)
//     0x81, 0x03,                    //   INPUT (Cnst,Var,Abs)
//     0x95, 0x05,                    //   REPORT_COUNT (5)   5��bit
//     0x75, 0x01,                    //   REPORT_SIZE (1)
//     0x05, 0x08,                    //   USAGE_PAGE (LEDs)  �����ϵ�led��
//     0x19, 0x01,                    //   USAGE_MINIMUM (Num Lock)
//     0x29, 0x05,                    //   USAGE_MAXIMUM (Kana)
//     0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)
//     0x95, 0x01,                    //   REPORT_COUNT (1)
//     0x75, 0x03,                    //   REPORT_SIZE (3)
//     0x91, 0x03,                    //   OUTPUT (Cnst,Var,Abs)
//     0x95, 0x06,                    //   REPORT_COUNT (6)
//     0x75, 0x08,                    //   REPORT_SIZE (8)
//     0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
//     0x25, 0x65,                    //   LOGICAL_MAXIMUM (101)
//     0x05, 0x07,                    //   USAGE_PAGE (Keyboard)
//     0x19, 0x00,                    //   USAGE_MINIMUM (Reserved (no event indicated))
//     0x29, 0x65,                    //   USAGE_MAXIMUM (Keyboard Application)
//     0x81, 0x00,                    //   INPUT (Data,Ary,Abs)
//     0xc0                           // END_COLLECTION
// };

// char ReportDescriptorMouse[50] = {
//     0x05, 0x01,                    // USAGE_PAGE (Generic Desktop)
//     0x09, 0x02,                    // USAGE (Mouse)
//     0xa1, 0x01,                    // COLLECTION (Application)
//     0x09, 0x01,                    //   USAGE (Pointer)
//     0xa1, 0x00,                    //   COLLECTION (Physical)
//     0x05, 0x09,                    //     USAGE_PAGE (Button)
//     0x19, 0x01,                    //     USAGE_MINIMUM (Button 1)
//     0x29, 0x03,                    //     USAGE_MAXIMUM (Button 3)
//     0x15, 0x00,                    //     LOGICAL_MINIMUM (0)
//     0x25, 0x01,                    //     LOGICAL_MAXIMUM (1)
//     0x95, 0x03,                    //     REPORT_COUNT (3)  ֻ����3��Сbit
//     0x75, 0x01,                    //     REPORT_SIZE (1)
//     0x81, 0x02,                    //     INPUT (Data,Var,Abs)
//     0x95, 0x01,                    //     REPORT_COUNT (1)
//     0x75, 0x05,                    //     REPORT_SIZE (5)
//     0x81, 0x03,                    //     INPUT (Cnst,Var,Abs)
//     0x05, 0x01,                    //     USAGE_PAGE (Generic Desktop)  ��;ҳ
//     0x09, 0x30,                    //     USAGE (X)  ��ʾ����������ϵķ�iѡ�ĸ�
//     0x09, 0x31,                    //     USAGE (Y)  ������Լ�һ������
//     0x15, 0x81,                    //     LOGICAL_MINIMUM (-127)
//     0x25, 0x7f,                    //     LOGICAL_MAXIMUM (127)
//     0x75, 0x08,                    //     REPORT_SIZE (8)
//     0x95, 0x02,                    //     REPORT_COUNT (2) �ӹ��� �˴��ĳ�3
//     0x81, 0x06,                    //     INPUT (Data,Var,Rel)
//     0xc0,                          //   END_COLLECTION
//     0xc0                           // END_COLLECTION
// };

// char ReportDescriptorKeybrdMouse[117] = {
//     0x05, 0x01,                    // USAGE_PAGE (Generic Desktop)
//     0x09, 0x06,                    // USAGE (Keyboard)
//     0xa1, 0x01,                    // COLLECTION (Application)
//     0x85, 0x01,                    //   REPORT_ID(1)
//     0x05, 0x07,                    //   USAGE_PAGE (Keyboard)
//     0x19, 0xe0,                    //   USAGE_MINIMUM (Keyboard LeftControl)
//     0x29, 0xe7,                    //   USAGE_MAXIMUM (Keyboard Right GUI)   hid��;���һ�����
//     0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
//     0x25, 0x01,                    //   LOGICAL_MAXIMUM (1)
//     0x75, 0x01,                    //   REPORT_SIZE (1)
//     0x95, 0x08,                    //   REPORT_COUNT (8)
//     0x81, 0x02,                    //   INPUT (Data,Var,Abs)
//     0x95, 0x01,                    //   REPORT_COUNT (1)
//     0x75, 0x08,                    //   REPORT_SIZE (8)
//     0x81, 0x03,                    //   INPUT (Cnst,Var,Abs)
//     0x95, 0x05,                    //   REPORT_COUNT (5)   5��bit
//     0x75, 0x01,                    //   REPORT_SIZE (1)
//     0x05, 0x08,                    //   USAGE_PAGE (LEDs)  �����ϵ�led��
//     0x19, 0x01,                    //   USAGE_MINIMUM (Num Lock)
//     0x29, 0x05,                    //   USAGE_MAXIMUM (Kana)
//     0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)
//     0x95, 0x01,                    //   REPORT_COUNT (1)
//     0x75, 0x03,                    //   REPORT_SIZE (3)
//     0x91, 0x03,                    //   OUTPUT (Cnst,Var,Abs)
//     0x95, 0x06,                    //   REPORT_COUNT (6)
//     0x75, 0x08,                    //   REPORT_SIZE (8)
//     0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
//     0x25, 0x65,                    //   LOGICAL_MAXIMUM (101)
//     0x05, 0x07,                    //   USAGE_PAGE (Keyboard)
//     0x19, 0x00,                    //   USAGE_MINIMUM (Reserved (no event indicated))
//     0x29, 0x65,                    //   USAGE_MAXIMUM (Keyboard Application)
//     0x81, 0x00,                    //   INPUT (Data,Ary,Abs)
//     0xc0,                          // END_COLLECTION

//     0x05, 0x01,                    // USAGE_PAGE (Generic Desktop)
//     0x09, 0x02,                    // USAGE (Mouse)
//     0xa1, 0x01,                    // COLLECTION (Application)
//     0x85, 0x01,                    //   REPORT_ID(2)
//     0x09, 0x01,                    //   USAGE (Pointer)
//     0xa1, 0x00,                    //   COLLECTION (Physical)
//     0x05, 0x09,                    //     USAGE_PAGE (Button)
//     0x19, 0x01,                    //     USAGE_MINIMUM (Button 1)
//     0x29, 0x03,                    //     USAGE_MAXIMUM (Button 3)
//     0x15, 0x00,                    //     LOGICAL_MINIMUM (0)
//     0x25, 0x01,                    //     LOGICAL_MAXIMUM (1)
//     0x95, 0x03,                    //     REPORT_COUNT (3)
//     0x75, 0x01,                    //     REPORT_SIZE (1)
//     0x81, 0x02,                    //     INPUT (Data,Var,Abs)
//     0x95, 0x01,                    //     REPORT_COUNT (1)
//     0x75, 0x05,                    //     REPORT_SIZE (5)
//     0x81, 0x03,                    //     INPUT (Cnst,Var,Abs)
//     0x05, 0x01,                    //     USAGE_PAGE (Generic Desktop)
//     0x09, 0x30,                    //     USAGE (X)
//     0x09, 0x31,                    //     USAGE (Y)
//     0x15, 0x81,                    //     LOGICAL_MINIMUM (-127)
//     0x25, 0x7f,                    //     LOGICAL_MAXIMUM (127)
//     0x75, 0x08,                    //     REPORT_SIZE (8)
//     0x95, 0x02,                    //     REPORT_COUNT (2)
//     0x81, 0x06,                    //     INPUT (Data,Var,Rel)
//     0xc0,                          //   END_COLLECTION
//     0xc0                           // END_COLLECTION
// };

