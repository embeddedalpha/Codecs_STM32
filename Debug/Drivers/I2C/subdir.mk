################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/I2C/I2C.c 

OBJS += \
./Drivers/I2C/I2C.o 

C_DEPS += \
./Drivers/I2C/I2C.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/I2C/%.o Drivers/I2C/%.su Drivers/I2C/%.cyclo: ../Drivers/I2C/%.c Drivers/I2C/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"B:/STM32F407V_Firmware_C_Lang/Codecs/Codecs" -I"B:/STM32F407V_Firmware_C_Lang/Codecs/Drivers" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-I2C

clean-Drivers-2f-I2C:
	-$(RM) ./Drivers/I2C/I2C.cyclo ./Drivers/I2C/I2C.d ./Drivers/I2C/I2C.o ./Drivers/I2C/I2C.su

.PHONY: clean-Drivers-2f-I2C

