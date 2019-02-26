#ifndef __LCD_H__
#define __LCD_H__

/*
 * module：LCD1602
 * author：IfanTsai
 * api：
 * void lcd_init()
 * void lcd_write_ch(uchar pos, uchar ch)
 * void lcd_write_ch_auto(uchar ch)
 * void lcd_write_str(uchar pos, uchar str[])
 * void lcd_write_str_auto(uchar str[])       |    lcd_write
 * void lcd_set_space(uchar pos)
 * void lcd_back_space()
 * void lcd_clear()
 *
 */
#include "main.h"

void Write_Cmd(uchar cmd);
void Write_Dat(uchar dat);

//#define lcd_enter() (Write_Cmd(0xc0)) //换行
#define lcd_clear()           (Write_Cmd(0x01)) //清屏
#define lcd_write_ch_auto(ch) (Write_Dat(ch))
#define lcd_write(str)        (lcd_write_str_auto(str))
void lcd_init();
void lcd_write_ch(uchar pos, uchar ch);
void lcd_write_str(uchar pos, uchar str[]);
void lcd_write_str_auto(uchar str[]);
void lcd_set_space(uchar pos);
void lcd_back_space();

#endif