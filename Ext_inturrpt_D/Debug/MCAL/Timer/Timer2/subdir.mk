################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Timer/Timer2/Timer2_program.c 

OBJS += \
./MCAL/Timer/Timer2/Timer2_program.o 

C_DEPS += \
./MCAL/Timer/Timer2/Timer2_program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Timer/Timer2/%.o: ../MCAL/Timer/Timer2/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


