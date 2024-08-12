################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Define the project root path
PROJECT_ROOT := $(abspath $(dir $(firstword $(MAKEFILE_LIST)))/../../../..)

# Directories
RUN_SRC_DIR := $(PROJECT_ROOT)/HEAAN/HEAAN/run
INCLUDE_DIR := $(PROJECT_ROOT)/lib/include
HEAAN_INCLUDE_DIR := $(PROJECT_ROOT)/HEAAN/HEAAN/src

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
$(RUN_SRC_DIR)/test.cpp 

OBJS += \
$(RUN_SRC_DIR)/test.o 

CPP_DEPS += \
$(RUN_SRC_DIR)/test.d 

# Each subdirectory must supply rules for building sources it contributes
%.o: $(RUN_SRC_DIR)/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler 4 Testing'
	g++ -I$(HEAAN_INCLUDE_DIR) -I$(INCLUDE_DIR) -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
