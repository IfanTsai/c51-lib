#include "lcd.h"

static uchar LCD_POS = 0;     // 指向接下去显示的位置

static void delay()
{
	uchar i = 30, j = 20;
	while (i--)
		while (j--);
}

void lcd_init()
{
	Write_Cmd(0x38);         // 设置显示模式：16x2显示，5x7点阵，8位数据接口
	Write_Cmd(0x0c);         // 设置开显示，不显示光标
	Write_Cmd(0x06);         // 设置读或写一个字符后地址指针加一
	Write_Cmd(0x01);         // 清屏
	Write_Cmd(0x80);         // 刚初始化完，指针指向首位置
	LCD_POS = 0;
	delay();
}

void Write_Cmd(uchar cmd)
{
	RS = 0;
	RW = 0;
	DATA_LINE = cmd;
	delay();
	LCDE = 1;
	delay();
	LCDE = 0;
	delay();
}

void Write_Dat(uchar dat)
{
	RS = 1;
	RW = 0;
	DATA_LINE = dat;
	delay();
	LCDE = 1;
	delay();
	LCDE = 0;
}

void lcd_write_ch(uchar pos, uchar ch)
{
	(pos < 16) ? Write_Cmd(0x80 + pos) : Write_Cmd(0xc0 + pos - 16);
	Write_Dat(ch);
	LCD_POS++;
}

void lcd_write_str(uchar pos, uchar str[])
{
	uchar str_len = strlen(str);
	uchar cnt = 0, current_pos = pos;
	(pos < 16) ? Write_Cmd(0x80 + pos) : Write_Cmd(0xc0 + pos - 16);
	for (cnt = 0; cnt < str_len; cnt++, current_pos++)
	{
		if (current_pos == 16)
		{
			Write_Cmd(0xc0);         // 换行
		}
		Write_Dat(str[cnt]);
		LCD_POS++;
	}
}

void lcd_write_str_auto(uchar str[])
{
	uchar str_len = strlen(str);
	uchar cnt = 0;
	for (cnt = 0; cnt < str_len; cnt++)
	{
		Write_Dat(str[cnt]);
		LCD_POS++;
	}
}

void lcd_set_space(uchar pos)
{
	(pos < 16) ? Write_Cmd(0x80 + pos) : Write_Cmd(0xc0 + pos - 16);
	lcd_write_ch_auto(' ');
	(pos < 16) ? Write_Cmd(0x80 + pos) : Write_Cmd(0xc0 + pos - 16);
	LCD_POS = LCD_POS;      // 这是一条无聊的代码
}

void lcd_back_space()
{
	( (LCD_POS - 1) < 16) ? Write_Cmd(0x80 + LCD_POS - 1) : Write_Cmd(0xc0 + LCD_POS - 16 - 1);
	lcd_write_ch_auto(' ');
	( (LCD_POS - 1) < 16) ? Write_Cmd(0x80 + LCD_POS - 1) : Write_Cmd(0xc0 + LCD_POS - 16 - 1);
	LCD_POS = LCD_POS;     // 没错,这同样是一条无聊的代码
}

