#ifndef __UART_H__
#define __UART_H__

/*
 * module：uart
 * author：IfanTsai
 * api：
 * void uart_init()
 * void uart_send_ch(uchar ch)     |  uart_write_ch
 * void uart_send_str(uchar *str)  |  uart_write_str  |  uart_write
 * char* uart_read(char *buf)      // 专用的读取接口，必须使用这个接口来读取
 * 注：接收串口数据，约定以'\r'作为结束表示
 */

#include "main.h"

#define USART_REC_LEN     32
static u8 USART_RX_BUF[USART_REC_LEN];   // 接收缓冲区
static u16 USART_CUR = 0;                // 记录接收缓存区的下标
static u8 USART_FLAG = 0;                // 接收完毕则置1

#define uart_write_ch(ch)     uart_send_ch(ch)
#define uart_write_str(str)   uart_send_str(str)
#define uart_write(str)       uart_send_str(str)

void uart_init();
void uart_send_ch(uchar ch);	  //发送一个字符
void uart_send_str(uchar *str);	  //发送字符串
char* uart_read(char *buf);


#endif