################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include lcd/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(I_DEPS)),)
-include $(I_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(M_DEPS)),)
-include $(M_DEPS)
endif
ifneq ($(strip $(MI_DEPS)),)
-include $(MI_DEPS)
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
avr_ultrasonic_0.lss \

FLASH_IMAGE += \
avr_ultrasonic_0.hex \

EEPROM_IMAGE += \
avr_ultrasonic_0.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: avr_ultrasonic_0.elf secondary-outputs

# Tool invocations
avr_ultrasonic_0.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,avr_ultrasonic_0.map -mmcu=atmega328p -o "avr_ultrasonic_0.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

avr_ultrasonic_0.lss: avr_ultrasonic_0.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S avr_ultrasonic_0.elf  >"avr_ultrasonic_0.lss"
	@echo 'Finished building: $@'
	@echo ' '

avr_ultrasonic_0.hex: avr_ultrasonic_0.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex avr_ultrasonic_0.elf  "avr_ultrasonic_0.hex"
	@echo 'Finished building: $@'
	@echo ' '

avr_ultrasonic_0.eep: avr_ultrasonic_0.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex avr_ultrasonic_0.elf  "avr_ultrasonic_0.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: avr_ultrasonic_0.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p avr_ultrasonic_0.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(M_DEPS)$(MI_DEPS)$(S_DEPS)$(LSS)$(C_DEPS)$(FLASH_IMAGE)$(ELFS)$(I_DEPS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(SIZEDUMMY)$(S_UPPER_DEPS) avr_ultrasonic_0.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
