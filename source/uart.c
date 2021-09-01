#include "uart.h"
#include "string.h"
#include <stdlib.h>

void uart_init()
{
	TMOD = TMOD_VAL;
	SCON = SCON_VAL;
	TH1  = TH1_VAL;
	TL1  = TL1_VAL;
	PCON = PCON_VAL;
	EA   = CONFIG_EA;
	ES   = CONFIG_ES;
	TR1  = CONFIG_TR1;
#if 0
	// 波特率9600
	SCON = 0x50;   	// 串口工作在模式1（8位串口）、允许接收
	//PCON = 0x00;	// 波特率不加倍

	// 通信波特率相关的设置
	TMOD = 0x20;	// 设置T1为模式2
	TH1 = 0xfd;
	TL1 = 0xfd;	   	// 8位自动重装，意思就是TH1用完了之后下一个周期TL1会
					// 自动重装到TH1去

	TR1 = 1;		// 开启T1让它开始工作
	ES = 1;
	EA = 1;
#endif
}

void uart_send_str(uchar *str)	    // 发送字符串
{
	while (*str) {
		SBUF = *(str++);
		while (TI == 0);
		TI = 0;
	}
}

void uart_send_ch(uchar ch)        // 发送一个字符
{
	TI = 0;
	SBUF = ch;
	while (TI == 0);
	TI = 0;
}

// 非阻塞： 将USART_RX_BUF中的数据读走后USART_FLAG清0，才可以在中断中接收下一次数据
// 阻塞： 等待USART_FLAG置1才返回
char* uart_read(char *buf)
{
#ifdef UART_BLOCK
	while (!USART_FLAG);
#else
	if (!USART_FLAG) {
		return buf;
	}
#endif
	memset(buf, 0, sizeof(buf));
	strcpy(buf, USART_RX_BUF);
	USART_FLAG = 0;

	return buf;
}

void uart_receive() interrupt 4 using 1
{
	uchar res = SBUF;

	if (RI && !USART_FLAG) {
		if (res == '\r') {
			USART_RX_BUF[USART_CUR] = '\0';
			USART_CUR = 0;
			USART_FLAG = 1;
		} else if (res != '\n') {
			USART_RX_BUF[USART_CUR] = res;
			USART_CUR++;
		}
	}

	RI = 0;
}