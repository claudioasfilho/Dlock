################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/SiliconLabs/SimplicityStudio/v3_3/developer/sdks/efm32/v2/kits/common/bsp/bsp_stk_leds.c 

OBJS += \
./BSP/bsp_stk_leds.o 

C_DEPS += \
./BSP/bsp_stk_leds.d 


# Each subdirectory must supply rules for building sources it contributes
BSP/bsp_stk_leds.o: C:/SiliconLabs/SimplicityStudio/v3_3/developer/sdks/efm32/v2/kits/common/bsp/bsp_stk_leds.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb '-DDEBUG_EFM=1' '-DEFM32PG1B200F256GM48=1' '-DRETARGET_VCOM=1' '-DDEBUG=1' -I"C:/SiliconLabs/SimplicityStudio/v3_3/developer/sdks/efm32/v2/kits/SLSTK3401A_EFM32PG/config" -I"C:/SiliconLabs/SimplicityStudio/v3_3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v3_3/developer/sdks/efm32/v2/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v3_3/developer/sdks/efm32/v2/emdrv/common/inc" -I"C:/SiliconLabs/SimplicityStudio/v3_3/developer/sdks/efm32/v2/emdrv/rtcdrv/inc" -I"C:/SiliconLabs/SimplicityStudio/v3_3/developer/sdks/efm32/v2/emdrv/dmadrv/inc" -I"C:/SiliconLabs/SimplicityStudio/v3_3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3_3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3_3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32PG1B/Include" -I"C:\Users\clfilho\Dropbox (Silicon Labs)\Code_Workspace_2\Digilock-3\src" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -std=c99 -MMD -MP -MF"BSP/bsp_stk_leds.d" -MT"BSP/bsp_stk_leds.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


