################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LCD_driver/DIO_prog.c \
../LCD_driver/LCD_prog.c 

OBJS += \
./LCD_driver/DIO_prog.o \
./LCD_driver/LCD_prog.o 

C_DEPS += \
./LCD_driver/DIO_prog.d \
./LCD_driver/LCD_prog.d 


# Each subdirectory must supply rules for building sources it contributes
LCD_driver/%.o: ../LCD_driver/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


