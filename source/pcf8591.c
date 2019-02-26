#include "pcf8591.h"

u8 adc_read(u8 channel)
{
	u8 val;
    i2c_start();                     // 启动总线
    i2c_send_byte(AddWr);            // 发送器件地址
    i2c_send_byte(0x40 | channel);        // 发送器件子地址
    i2c_start();
    i2c_send_byte(AddWr + 1);
    val = i2c_recv_byte();
    i2c_stop();                       // 结束总线
    return  val;
}