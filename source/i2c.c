#include "i2c.h"

// 10us的延迟
static void delay()
{
    unsigned char a, b;
    for (b = 1; b > 0; b--)
        for (a = 1; a > 0; a--);
}

// 起始
void i2c_start()
{
	SDA = 1;
	delay();
	SCL = 1;
	delay();
	SDA = 0;
	delay();
	SCL = 0;
	delay();
}

// 终止
void i2c_stop()
{
	SDA = 0;
	delay();
	SCL = 1;
	delay();
	SDA = 1;
	delay();
}

// 应答
void i2c_respond()
{
	u8 i = 200;
	delay();
	while (SDA && i--);   // 拉低SDA表示应答信号，若无应答，等待一段时间后默认应答
	if (i == 0)	          // i为0表示已等待一段时间
	{
		SDA = 0;          // 默认应答
	}
	SCL = 1;
	delay();
	SCL = 0;
	delay();
}

// 发送一个字节
void i2c_send_byte(uchar dat)
{
	uchar i;
	for (i = 0; i < 8; i++)
	{
		SDA = dat >> 7;
		dat <<= 1;
		delay();
		SCL = 1;
		delay();
		SCL = 0;
		delay();
	}
	SDA = 1;
	delay();
	i2c_respond();
}

// 接收一个字节
uchar i2c_recv_byte()
{
	uchar dat;
	uchar i;
	SCL = 0;
	delay();
	SDA = 1;
	delay();
	for (i = 0; i < 8; i++)
	{
		dat <<= 1;
		dat |= SDA;
		delay();
		SCL = 1;
		delay();
		SCL = 0;
		delay();
	}
	return dat;
	//i2c_respond();
}