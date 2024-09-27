################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Codecs/CS43L22/CS43L22.c 

OBJS += \
./Codecs/CS43L22/CS43L22.o 

C_DEPS += \
./Codecs/CS43L22/CS43L22.d 


# Each subdirectory must supply rules for building sources it contributes
Codecs/CS43L22/%.o Codecs/CS43L22/%.su Codecs/CS43L22/%.cyclo: ../Codecs/CS43L22/%.c Codecs/CS43L22/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"B:/STM32F407V_Firmware_C_Lang/Codecs/Codecs" -I"B:/STM32F407V_Firmware_C_Lang/Codecs/Drivers" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Codecs-2f-CS43L22

clean-Codecs-2f-CS43L22:
	-$(RM) ./Codecs/CS43L22/CS43L22.cyclo ./Codecs/CS43L22/CS43L22.d ./Codecs/CS43L22/CS43L22.o ./Codecs/CS43L22/CS43L22.su

.PHONY: clean-Codecs-2f-CS43L22

