################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Obtener_Dato.c \
../hardware.c \
../main.c 

C_DEPS += \
./Obtener_Dato.d \
./hardware.d \
./main.d 

OBJS += \
./Obtener_Dato.o \
./hardware.o \
./main.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./Obtener_Dato.d ./Obtener_Dato.o ./hardware.d ./hardware.o ./main.d ./main.o

.PHONY: clean--2e-

