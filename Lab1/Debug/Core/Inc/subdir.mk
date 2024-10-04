################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Core/Inc/Func_asm.s 

OBJS += \
./Core/Inc/Func_asm.o 

S_DEPS += \
./Core/Inc/Func_asm.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/%.o: ../Core/Inc/%.s Core/Inc/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Core-2f-Inc

clean-Core-2f-Inc:
	-$(RM) ./Core/Inc/Func_asm.d ./Core/Inc/Func_asm.o

.PHONY: clean-Core-2f-Inc

