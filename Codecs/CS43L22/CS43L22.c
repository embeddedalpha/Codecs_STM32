/*
 * CS43L22.c
 *
 *  Created on: Sep 25, 2024
 *      Author: kunal
 */

#include "CS43L22.h"



static int Get_Bass_Gain(float gain)
{
    // Check bounds for the dB value
    if (db > 12.0f) {
        db = 12.0f; // Limit to maximum
    } else if (db < -10.5f) {
        db = -10.5f; // Limit to minimum
    }

    // Convert dB to the corresponding uint8_t value
    int steps = (int)((12.0f - db) / 1.5f);

    return steps;
}

static int Get_Treble_Gain(float gain)
{
    // Check bounds for the dB value
    if (db > 12.0f) {
        db = 12.0f; // Limit to maximum
    } else if (db < -10.5f) {
        db = -10.5f; // Limit to minimum
    }

    // Convert dB to the corresponding uint8_t value
    int steps = (int)((12.0f - db) / 1.5f);

    return steps;
}

uint8_t CS43L22_Init(CS43L22_Config *config)
{
	I2C_Init(&config -> hardware_i2c);

	GPIO_Pin_Init(GPIOD, 4, GPIO_Configuration.Mode.General_Purpose_Output, GPIO_Configuration.Output_Type.Push_Pull, GPIO_Configuration.Speed.Very_High_Speed, GPIO_Configuration.Pull.Pull_Up, GPIO_Configuration.Alternate_Functions.None);


	GPIO_Pin_High(GPIOD, 4);

	I2C_Master_Write_Register(&config -> hardware_i2c, CS43L22_Address, 0x02, 0x01);

	I2C_Master_Write_Register(&config -> hardware_i2c, CS43L22_Address, 0x00, 0x99);
	I2C_Master_Write_Register(&config -> hardware_i2c, CS43L22_Address, 0x47, 0x80);

	uint8_t retval = I2C_Master_Read_Register(&config->hardware_i2c, CS43L22_Address, 0x32);
	retval |= 1 << 7;
	I2C_Master_Write_Register(&config -> hardware_i2c, CS43L22_Address, 0x32, retval);

	retval = I2C_Master_Read_Register(&config->hardware_i2c, CS43L22_Address, 0x32);
	retval &= ~(1 << 7);
	I2C_Master_Write_Register(&config -> hardware_i2c, CS43L22_Address, 0x32, retval);

	I2C_Master_Write_Register(&config -> hardware_i2c, CS43L22_Address, 0x00, 0x00);

	return 1;

}



uint8_t CS43L22_Read_ID(CS43L22_Config *config)
{
	int8_t retval = 0;
	uint8_t temp = 0;
	temp = I2C_Master_Read_Register(&config->hardware_i2c, CS43L22_Address, 0x01);

	if((temp & 0xF0) == 0xE0)
	{
		retval = 1;
	}
	else
	{
		retval = 0;
	}

	return retval;
}



uint8_t CS43L22_Set_Treble_Corner_Frequency(CS43L22_Config *config, uint8_t val)
{
	CS43L22_Deactivate(config);

	uint8_t retval = I2C_Master_Read_Register(&config->hardware_i2c, CS43L22_Address, 0x1E);

	retval &= ~(3 << 3);
	retval |= val << 3;

	I2C_Master_Write_Register(&config -> hardware_i2c, CS43L22_Address, 0x1E, retval);
	CS43L22_Activate(config);
}

uint8_t CS43L22_Get_Treble_Corner_Frequency(CS43L22_Config *config)
{
	uint8_t retval = 0;
	retval = I2C_Master_Read_Register(&config->hardware_i2c, CS43L22_Address, 0x1E);
	return ( retval & (3 << 3)) >> 3;
}

uint8_t CS43L22_Set_Bass_Corner_Frequency(CS43L22_Config *config)
{
	CS43L22_Deactivate(config);

	uint8_t retval = I2C_Master_Read_Register(&config->hardware_i2c, CS43L22_Address, 0x1E);

	retval &= ~(3 << 1);
	retval |= val << 1;

	I2C_Master_Write_Register(&config -> hardware_i2c, CS43L22_Address, 0x1E, retval);
	CS43L22_Activate(config);
}

uint8_t CS43L22_Get_Bass_Corner_Frequency(CS43L22_Config *config)
{
	uint8_t retval = 0;
	retval = I2C_Master_Read_Register(&config->hardware_i2c, CS43L22_Address, 0x1E);
	return ( retval & (3 << 1)) >> 1;
}

uint8_t CS43L22_Tone_Control_Enable(CS43L22_Config *config)
{
	CS43L22_Deactivate(config);

	uint8_t val = 1;
	uint8_t retval = I2C_Master_Read_Register(&config->hardware_i2c, CS43L22_Address, 0x1E);

	retval &= ~(1 << 0);
	retval |= val << 0;

	I2C_Master_Write_Register(&config -> hardware_i2c, CS43L22_Address, 0x1E, retval);
	CS43L22_Activate(config);
}


void CS43L22_Headphone_Mute(CS43L22_Config *config, bool mute_on_off)
{
	CS43L22_Deactivate(config);

	CS43L22_Activate(config);
}


uint8_t CS43L22_Master_Volume_Control(CS43L22_Config *config, float volume)
{
	CS43L22_Deactivate(config);
	uint8_t result = 0;
    if (db > 12.0f) {
        db = 12.0f; // Limit to maximum
    } else if (db < -102.0f) {
        db = -102.0f; // Limit to minimum
    }

    // Calculate the corresponding uint8_t value
    uint8_t result;
    if (db >= 0.0f) {
        result = (uint8_t)(18 - (db / 12.0f) * 18);
    } else {
        result = (uint8_t)(18 + ((-db) * 2));
    }
    I2C_Master_Write_Register(&config -> hardware_i2c, CS43L22_Address, 0x02, result);
    CS43L22_Activate(config);
}


uint8_t CS43L22_Headphone_Volume_Control(CS43L22_Config *config)
{
	CS43L22_Deactivate(config);

	CS43L22_Activate(config);

}
uint8_t CS43L22_Speaker_A_Volume_Control(CS43L22_Config *config)
{
	CS43L22_Deactivate(config);
	uint8_t result = 0;
    if (db > 12.0f) {
        db = 12.0f; // Limit to maximum
    } else if (db < -102.0f) {
        db = -102.0f; // Limit to minimum
    }

    // Calculate the corresponding uint8_t value
    uint8_t result;
    if (db >= 0.0f) {
        result = (uint8_t)(18 - (db / 12.0f) * 18);
    } else {
        result = (uint8_t)(18 + ((-db) * 2));
    }
    I2C_Master_Write_Register(&config -> hardware_i2c, CS43L22_Address, 0x02, result);

	CS43L22_Activate(config);
}

uint8_t CS43L22_Activate(CS43L22_Config *config)
{
	uint8_t temp = 0;
	temp = I2C_Master_Read_Register(&config -> hardware_i2c, CS43L22_Address, 0x02);

	if(temp != 0x9E)
	{
		I2C_Master_Write_Register(&config -> hardware_i2c, CS43L22_Address, 0x02, 0b00000001);
	}
}

uint8_t CS43L22_Deactivate(CS43L22_Config *config)
{
	uint8_t temp = 0;
	temp = I2C_Master_Read_Register(&config -> hardware_i2c, CS43L22_Address, 0x02);

	if((temp != 0x01) || (temp != 0x9F))
	{
		I2C_Master_Write_Register(&config -> hardware_i2c, CS43L22_Address, 0x02, 0b00000001);
	}
}
