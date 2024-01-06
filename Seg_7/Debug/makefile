################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/DIO/subdir.mk
-include HAL/Switch_Comp/subdir.mk
-include HAL/SevSeg/subdir.mk
-include HAL/LED/subdir.mk
-include Apps/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Seg_7.lss \

FLASH_IMAGE += \
Seg_7.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Seg_7.elf secondary-outputs

# Tool invocations
Seg_7.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Seg_7.map -mmcu=atmega32 -o "Seg_7.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Seg_7.lss: Seg_7.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Seg_7.elf  >"Seg_7.lss"
	@echo 'Finished building: $@'
	@echo ' '

Seg_7.hex: Seg_7.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Seg_7.elf  "Seg_7.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Seg_7.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Seg_7.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Seg_7.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
