################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/I2S/I2S.c 

OBJS += \
./Drivers/I2S/I2S.o 

C_DEPS += \
./Drivers/I2S/I2S.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/I2S/%.o Drivers/I2S/%.su Drivers/I2S/%.cyclo: ../Drivers/I2S/%.c Drivers/I2S/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"B:/STM32F407V_Firmware_C_Lang/Codecs/Codecs" -I"B:/STM32F407V_Firmware_C_Lang/Codecs/Drivers" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-I2S

clean-Drivers-2f-I2S:
	-$(RM) ./Drivers/I2S/I2S.cyclo ./Drivers/I2S/I2S.d ./Drivers/I2S/I2S.o ./Drivers/I2S/I2S.su

.PHONY: clean-Drivers-2f-I2S

