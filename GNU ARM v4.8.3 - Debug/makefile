################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include emlib/subdir.mk
-include Drivers/subdir.mk
-include CMSIS/efm32pg1b/subdir.mk
-include BSP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: Digilock-3.axf

# Tool invocations
Digilock-3.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -T "Digilock-3.ld" -Xlinker --gc-sections -Xlinker -Map="Digilock-3.map" -mfpu=fpv4-sp-d16 -mfloat-abi=softfp --specs=nano.specs -u _printf_float -o Digilock-3.axf "./src/em_gpcrc.o" "./src/main.o" "./emlib/em_adc.o" "./emlib/em_assert.o" "./emlib/em_cmu.o" "./emlib/em_cryotimer.o" "./emlib/em_emu.o" "./emlib/em_gpio.o" "./emlib/em_int.o" "./emlib/em_ldma.o" "./emlib/em_prs.o" "./emlib/em_rtcc.o" "./emlib/em_system.o" "./emlib/em_usart.o" "./Drivers/retargetio.o" "./Drivers/retargetserial.o" "./CMSIS/efm32pg1b/startup_efm32pg1b.o" "./CMSIS/efm32pg1b/system_efm32pg1b.o" "./BSP/bsp_stk_leds.o" -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building hex file: Digilock-3.hex'
	arm-none-eabi-objcopy -O ihex "Digilock-3.axf" "Digilock-3.hex"
	@echo ' '

	@echo 'Building bin file: Digilock-3.bin'
	arm-none-eabi-objcopy -O binary "Digilock-3.axf" "Digilock-3.bin"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "Digilock-3.axf"
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) Digilock-3.axf
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
