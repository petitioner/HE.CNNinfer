################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CNNinference.cpp \
../src/Methods.cpp \
../src/Tools.cpp \
../src/VolleyRevolverEncoding.cpp 

OBJS += \
./src/CNNinference.o \
./src/Methods.o \
./src/Tools.o \
./src/VolleyRevolverEncoding.o 

CPP_DEPS += \
./src/CNNinference.d \
./src/Methods.d \
./src/Tools.d \
./src/VolleyRevolverEncoding.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/john/eclipse-workspace/CNNinference/lib/include" -I"/home/john/eclipse-workspace/CNNinference/HEAAN/HEAAN/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


