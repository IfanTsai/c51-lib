#include "key.h"

char key_polling()
{
	uchar i = 0, a = 100;

	KEY = 0x0f;
	if (KEY != 0x0f) {
		while (a--);        // 去抖
		if (KEY != 0x0f) {
			switch (KEY) {  // 列扫描
			case 0x07:
				i = 0;
				break;
			case 0x0b:
				i = 1;
				break;
			case 0x0d:
				i = 2;
				break;
			case 0x0e:
				i = 3;
				break;
			default:
				return -1;
			}

			KEY = 0xf0;
			switch (KEY) {   // 行扫描
			case 0x70:
				break;
			case 0xb0:
				i += 4;
				break;
			case 0xd0:
				i += 8;
				break;
			case 0xe0:
				i += 12;
			default:
				return -1;
			}

			while (KEY != 0xf0); // 按键松开检测
		}
	}

	return i;
}

char key_blocking()
{
	KEY = 0x0f;
	while (KEY == 0x0f); // blocking
	
	return key_polling();
}
