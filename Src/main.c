#include <stdint.h>
#include "I2C/I2C.h"
#include "CS43L22/CS43L22.h"

CS43L22_Config driver;


int main(void)
{
	MCU_Clock_Setup();
	Delay_Config();


	driver.hardware_i2c.Port = I2C1;
	driver.hardware_i2c.SCL_Pin = I2C_Configuration.Pin.__I2C1__.SCL.PB6;
	driver.hardware_i2c.SDA_Pin = I2C_Configuration.Pin.__I2C1__.SDA.PB9;
	driver.hardware_i2c.DMA_Control = I2C_Configuration.DMA_Control.Disable;
	driver.hardware_i2c.Interrupts = I2C_Configuration.Interrupts.Disable;
	driver.hardware_i2c.Mode = I2C_Configuration.Mode.Master;
	driver.hardware_i2c.Speed_Mode = I2C_Configuration.Speed_Mode.FM_Mode;
	CS43L22_Init(&driver);




	for(;;);
}

