################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CNNinference.cpp \
../src/VolleyRevolverEncoding.cpp \
../src/Methods.cpp \
../src/Tools.cpp 

OBJS += \
./src/CNNinference.o \
./src/VolleyRevolverEncoding.o \
./src/Methods.o \
./src/Tools.o 

CPP_DEPS += \
./src/CNNinference.d \
./src/VolleyRevolverEncoding.d \
./src/Methods.d \
./src/Tools.d 

# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I$(INCLUDE_DIR) -I$(HEAAN_INCLUDE_DIR) -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
