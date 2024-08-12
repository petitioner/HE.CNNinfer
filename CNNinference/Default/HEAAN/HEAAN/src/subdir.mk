################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Define the project root path
PROJECT_ROOT := $(abspath $(dir $(firstword $(MAKEFILE_LIST)))/../../..)

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/BootContext.cpp \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/Ciphertext.cpp \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/EvaluatorUtils.cpp \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/HEAAN.cpp \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/Key.cpp \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/Plaintext.cpp \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/Ring.cpp \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/RingMultiplier.cpp \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/Scheme.cpp \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/SchemeAlgo.cpp \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/SecretKey.cpp \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/SerializationUtils.cpp \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/StringUtils.cpp \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/TestScheme.cpp \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/TimeUtils.cpp 

OBJS += \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/BootContext.o \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/Ciphertext.o \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/EvaluatorUtils.o \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/HEAAN.o \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/Key.o \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/Plaintext.o \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/Ring.o \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/RingMultiplier.o \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/Scheme.o \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/SchemeAlgo.o \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/SecretKey.o \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/SerializationUtils.o \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/StringUtils.o \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/TestScheme.o \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/TimeUtils.o 

CPP_DEPS += \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/BootContext.d \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/Ciphertext.d \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/EvaluatorUtils.d \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/HEAAN.d \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/Key.d \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/Plaintext.d \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/Ring.d \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/RingMultiplier.d \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/Scheme.d \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/SchemeAlgo.d \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/SecretKey.d \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/SerializationUtils.d \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/StringUtils.d \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/TestScheme.d \
$(PROJECT_ROOT)/HEAAN/HEAAN/src/TimeUtils.d 

# Each subdirectory must supply rules for building sources it contributes
$(PROJECT_ROOT)/HEAAN/HEAAN/src/%.o: $(PROJECT_ROOT)/HEAAN/HEAAN/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler 4 Testing'
	g++ -I"$(PROJECT_ROOT)/HEAAN/HEAAN/src" -I"$(PROJECT_ROOT)/lib/include" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
