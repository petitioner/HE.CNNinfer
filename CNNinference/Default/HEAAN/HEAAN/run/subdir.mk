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
	g++ -I"/home/tree/Downloads/IDASH2017-master/IDASH2017/HEAAN/HEAAN/src" -I"/home/tree/Downloads/IDASH2017-master/IDASH2017/lib/include" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


