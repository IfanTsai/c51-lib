#ifndef __AT24C02_H__
#define __AT24C02_H__

/*
 * module：AT24C02    (E2PROM)
 * author：IfanTsai
 * api：void at24c02_init()
 *      void at24c02_write(u8 addr, u8 dat)
 *      u8 at24c02_read(u8 addr)
 */

#include "main.h"
#include "i2c.h"

#define at24c02_init()  i2c_init()
void at24c02_write(u8 addr, u8 dat);
u8 at24c02_read(u8 addr);

#endif