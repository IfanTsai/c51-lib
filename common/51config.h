#ifndef __51CONFIG_H__
#define __51CONFIG_H__

/*
 * module: config
 * author: IfanTsai
 *
 */

// PCF8591
#define AddWr 0x90   // 写数据地址
#define AddRd 0x91   // 读数据地址

// I2C
sbit SCL = P0^0;
sbit SDA = P0^1;

// 矩阵键盘
#define KEY P2

// LCD 1062
sbit  LCDE = P2^7;        // 使能信号
sbit  RS   = P2^6;        // 数据/命令选择端  对应  1/0
sbit  RW   = P2^5;        // 读/写选择端      对应  1/0
#define DATA_LINE P0      // 数据总线

/*
 * uart options
 */
#define UART_BLOCK      // 以阻塞方式读取数据

#define CONFIG_EA   1   // 总中断开关
#define CONFIG_ES   1   // 串口中断开关
#define CONFIG_TR1  1   // 定时器1开关

//#define CONFIG_11_0592MHz_BAUDRATE_4800
#define CONFIG_11_0592MHz_BAUDRATE_9600
//#define CONFIG_11_0592MHz_BAUDRATE_57600
//#define CONFIG_12MHz_BAUDRATE_4800

#if defined   (CONFIG_11_0592MHz_BAUDRATE_4800)
#define TMOD_VAL   0x20
#define SCON_VAL   0x50
#define TH1_VAL    0xF4
#define TL1_VAL    0xF4
#define PCON_VAL   0x80
#elif defined (CONFIG_11_0592MHz_BAUDRATE_9600)
#define TMOD_VAL   0x20
#define SCON_VAL   0x50
#define TH1_VAL    0xFD
#define TL1_VAL    0xFD
#define PCON_VAL   0x00
#elif defined (CONFIG_11_0592MHz_BAUDRATE_57600)
#define TMOD_VAL   0x20
#define SCON_VAL   0x50
#define TH1_VAL    0xFF
#define TL1_VAL    0xFF
#define PCON_VAL   0x80
#elif defined (CONFIG_12MHz_BAUDRATE_4800)
#define TMOD_VAL   0x20
#define SCON_VAL   0x50
#define TH1_VAL    0xF3
#define TL1_VAL    0xF3
#define PCON_VAL   0x80
#endif

/*
 * uart end
 */





/*
 * timer options
 */


/*
 * timer end
 */



#endif