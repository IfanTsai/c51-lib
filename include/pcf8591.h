#ifndef __PCF8591_H__
#define __PCF8591_H__

/*
 * module：PCF8591  (ADC)
 * author：IfanTsai
 * api：void adc_init()
 *      u8 adc_read(u8 channel)
 *
 */

#include "main.h"
#include "i2c.h"

#define adc_init() i2c_init()
u8 adc_read(u8 channel);

#endif