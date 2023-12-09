//键盘发送数据
//字节1为ReportID:1，字节2为功能键盘，每一位对应一个按键，
/*  更详细的规定参考文档Device Class Definition for HID的8.3节
					Bit Key
					0 LEFT CTRL
					1 LEFT SHIFT
					2 LEFT ALT
					3 LEFT GUI
					4 RIGHT CTRL
					5 RIGHT SHIFT
					6 RIGHT ALT
					7 RIGHT GUI
*/
//字节3保留，字节4-9表示表示按键键值，
//每个按键对于的值可在HID Usage Tables文档中的第10节查询
//uint8_t buff_Key[9]={0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};


//多媒体发送数组，根据HID报告描述符的定义，第一个字节位ReportID:2,
//第二个字节从高到低，每一位分别对应：
/*	      Bit 功能
					0   音量升高
					1   音量减小
					2   静音
					3   播放/暂停
					4   暂停
					5   下一首
					6   上一首
					7   退出播放
*/
//更多的操作在HID描述符中添加，参考HID Usage Tables的15节Consumer Page
//0x01即表示音量升高
//uint8_t buff_Audio[2]={0x02,0x00};



//鼠标发送数组
//第一个字为ReportID:3，字节2的0000 0xxx后三位分别表示中间单击，右键单击，左键单机
//字节3为x轴移动距离，字节4为y轴移动距离，字节5为滚轮移动值 其范围为-127~127
//uint8_t buff_Mouse[5]={0x03,0x00,0x00,0x00,0x00};

