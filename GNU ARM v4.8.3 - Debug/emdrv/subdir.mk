################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emdrv/dmadrv/src/dmadrv.c \
C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emdrv/rtcdrv/src/rtcdriver.c 

OBJS += \
./emdrv/dmadrv.o \
./emdrv/rtcdriver.o 

C_DEPS += \
./emdrv/dmadrv.d \
./emdrv/rtcdriver.d 


# Each subdirectory must supply rules for building sources it contributes
emdrv/dmadrv.o: C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emdrv/dmadrv/src/dmadrv.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DDEBUG_EFM=1' '-DEFM32PG1B200F256GM48=1' '-DRETARGET_VCOM=1' '-DDEBUG=1' -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/SLSTK3401A_EFM32PG/config" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emdrv/common/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emdrv/rtcdrv/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emdrv/dmadrv/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32PG1B/Include" -I"C:\Users\amleung\SimplicityStudio\v3_workspace\EFM32PG_Training\src" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"emdrv/dmadrv.d" -MT"emdrv/dmadrv.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emdrv/rtcdriver.o: C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emdrv/rtcdrv/src/rtcdriver.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DDEBUG_EFM=1' '-DEFM32PG1B200F256GM48=1' '-DRETARGET_VCOM=1' '-DDEBUG=1' -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/SLSTK3401A_EFM32PG/config" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emdrv/common/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emdrv/rtcdrv/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/emdrv/dmadrv/inc" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32PG1B/Include" -I"C:\Users\amleung\SimplicityStudio\v3_workspace\EFM32PG_Training\src" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"emdrv/rtcdriver.d" -MT"emdrv/rtcdriver.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


