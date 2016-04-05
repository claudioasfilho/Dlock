################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers/retargetio.c \
C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers/retargetserial.c 

OBJS += \
./Drivers/retargetio.o \
./Drivers/retargetserial.o 

C_DEPS += \
./Drivers/retargetio.d \
./Drivers/retargetserial.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/retargetio.o: C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers/retargetio.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb '-DDEBUG_EFM=1' '-DEFM32PG1B200F256GM48=1' '-DRETARGET_VCOM=1' '-DDEBUG=1' -I"C:/SiliconLabs/SimplicityStudio/v3_3/developer/sdks/efm32/v2/kits/SLSTK3401A_EFM32PG/config" -I"C:/SiliconLabs/SimplicityStudio/v3_3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v3_3/developer/sdks/efm32/v2/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v3_3/developer/sdks/efm32/v2/emdrv/common/inc" -I"C:/SiliconLabs/SimplicityStudio/v3_3/developer/sdks/efm32/v2/emdrv/rtcdrv/inc" -I"C:/SiliconLabs/SimplicityStudio/v3_3/developer/sdks/efm32/v2/emdrv/dmadrv/inc" -I"C:/SiliconLabs/SimplicityStudio/v3_3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3_3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3_3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32PG1B/Include" -I"C:\Users\clfilho\Dropbox (Silicon Labs)\Code_Workspace_2\Digilock-3\src" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -std=c99 -MMD -MP -MF"Drivers/retargetio.d" -MT"Drivers/retargetio.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/retargetserial.o: C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/efm32/v2/kits/common/drivers/retargetserial.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb '-DDEBUG_EFM=1' '-DEFM32PG1B200F256GM48=1' '-DRETARGET_VCOM=1' '-DDEBUG=1' -I"C:/SiliconLabs/SimplicityStudio/v3_3/developer/sdks/efm32/v2/kits/SLSTK3401A_EFM32PG/config" -I"C:/SiliconLabs/SimplicityStudio/v3_3/developer/sdks/efm32/v2/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v3_3/developer/sdks/efm32/v2/emlib/inc" -I"C:/SiliconLabs/SimplicityStudio/v3_3/developer/sdks/efm32/v2/emdrv/common/inc" -I"C:/SiliconLabs/SimplicityStudio/v3_3/developer/sdks/efm32/v2/emdrv/rtcdrv/inc" -I"C:/SiliconLabs/SimplicityStudio/v3_3/developer/sdks/efm32/v2/emdrv/dmadrv/inc" -I"C:/SiliconLabs/SimplicityStudio/v3_3/developer/sdks/efm32/v2/kits/common/bsp" -I"C:/SiliconLabs/SimplicityStudio/v3_3/developer/sdks/efm32/v2/kits/common/drivers" -I"C:/SiliconLabs/SimplicityStudio/v3_3/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32PG1B/Include" -I"C:\Users\clfilho\Dropbox (Silicon Labs)\Code_Workspace_2\Digilock-3\src" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -std=c99 -MMD -MP -MF"Drivers/retargetserial.d" -MT"Drivers/retargetserial.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


