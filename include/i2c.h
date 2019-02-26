#ifndef __I2C_H__
#define __I2C_H__

/*
 * module：I2C
 * author：IfanTsai
 * api：void i2c_init()
 *      void i2c_start()
 *      void i2c_stop()
 *      void i2c_respond()
 *      void i2c_send_byte(uchar dat)
 *      uchar i2c_recv_byte()
 *
 */

#include "main.h"


// 释放时钟、数据线：I2C总线空闲时为高电平
#define i2c_init() do {        \
					SDA = 1;   \
					SCL = 1;   \
					} while(0)
void i2c_start();
void i2c_stop();
void i2c_respond();
void i2c_send_byte(uchar dat);
uchar i2c_recv_byte();

#endif

