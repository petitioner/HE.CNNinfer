################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../HEAAN/HEAAN/run/test.cpp 

OBJS += \
./HEAAN/HEAAN/run/test.o 

CPP_DEPS += \
./HEAAN/HEAAN/run/test.d 


# Each subdirectory must supply rules for building sources it contributes
HEAAN/HEAAN/run/%.o: ../HEAAN/HEAAN/run/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/john/eclipse-workspace/CNNinference/lib/include" -I"/home/john/eclipse-workspace/CNNinference/HEAAN/HEAAN/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


