################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_Prog.c \
../KPD_Prog.c \
../Lcd_Prog.c \
../main.c \
../needed_function.c \
../stack_char.c \
../stack_float.c \
../stack_int.c 

OBJS += \
./DIO_Prog.o \
./KPD_Prog.o \
./Lcd_Prog.o \
./main.o \
./needed_function.o \
./stack_char.o \
./stack_float.o \
./stack_int.o 

C_DEPS += \
./DIO_Prog.d \
./KPD_Prog.d \
./Lcd_Prog.d \
./main.d \
./needed_function.d \
./stack_char.d \
./stack_float.d \
./stack_int.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


