#ifndef __KEY_H__
#define __KEY_H__

/*
 * module：4*4矩阵按键
 * author：IfanTsai
 * api：
 * char key_polling()   轮询模式读取4*4按键，成功返回0 - 15，失败返回-1
 * char key_blocking()  阻塞模式读取4*4按键，成功返回0 - 15，失败返回-1
 */

#include "main.h"

char key_polling();
char key_blocking();

#endif
