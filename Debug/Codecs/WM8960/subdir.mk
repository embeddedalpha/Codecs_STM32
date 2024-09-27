################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Codecs/WM8960/WM8960.c 

OBJS += \
./Codecs/WM8960/WM8960.o 

C_DEPS += \
./Codecs/WM8960/WM8960.d 


# Each subdirectory must supply rules for building sources it contributes
Codecs/WM8960/%.o Codecs/WM8960/%.su Codecs/WM8960/%.cyclo: ../Codecs/WM8960/%.c Codecs/WM8960/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"B:/STM32F407V_Firmware_C_Lang/Codecs/Codecs" -I"B:/STM32F407V_Firmware_C_Lang/Codecs/Drivers" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Codecs-2f-WM8960

clean-Codecs-2f-WM8960:
	-$(RM) ./Codecs/WM8960/WM8960.cyclo ./Codecs/WM8960/WM8960.d ./Codecs/WM8960/WM8960.o ./Codecs/WM8960/WM8960.su

.PHONY: clean-Codecs-2f-WM8960

