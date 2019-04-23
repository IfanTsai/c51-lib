#include "at24c02.h"

static void delay100ms()
{
    unsigned char a,b,c;
    for (c = 7; c > 0; c--)
        for (b = 74; b > 0 ; b--)
            for (a = 95; a > 0; a--);
}


void at24c02_write(u8 addr, u8 dat)
{
	i2c_start();
	i2c_send_byte(0xa0);  // 发送器件地址 （最低位为0表示写）
	i2c_send_byte(addr);  // 发送要写入内存地址
	i2c_send_byte(dat);   // 发送要写入的数据
    i2c_stop();
    delay100ms();
}

u8 at24c02_read(u8 addr)
{
	u8 num;
	i2c_start();
	i2c_send_byte(0xa0);    // 发送写器件地址
	i2c_send_byte(addr);    // 发送要读取的地址
	i2c_start();
	i2c_send_byte(0xa1);    // 发送器件地址 （最低位为1表示读）
	num = i2c_recv_byte();  // 读取数据
	i2c_stop();
	delay100ms();
	return num;
}