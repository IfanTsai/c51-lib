#ifndef __KEY_H__
#define __KEY_H__

/*
 * module：4*4矩阵按键
 * author：IfanTsai
 * api：
 * uchar key_polling()   轮询模式读取4*4按键，成功返回0 - 15，失败返回-1
 * uchar key_blocking()  阻塞模式读取4*4按键，成功返回0 - 15，失败返回-1
 */

#include "main.h"

uchar key_polling();
uchar key_blocking();

#endif