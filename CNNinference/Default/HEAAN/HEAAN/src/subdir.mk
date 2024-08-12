################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Define the project root path
PROJECT_ROOT := $(abspath $(dir $(firstword $(MAKEFILE_LIST)))/../../../../../..)

# Directories
SRC_DIR := $(PROJECT_ROOT)/HEAAN/HEAAN/src
INCLUDE_DIR := $(PROJECT_ROOT)/lib/include

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
$(SRC_DIR)/BootContext.cpp \
$(SRC_DIR)/Ciphertext.cpp \
$(SRC_DIR)/EvaluatorUtils.cpp \
$(SRC_DIR)/HEAAN.cpp \
$(SRC_DIR)/Key.cpp \
$(SRC_DIR)/Plaintext.cpp \
$(SRC_DIR)/Ring.cpp \
$(SRC_DIR)/RingMultiplier.cpp \
$(SRC_DIR)/Scheme.cpp \
$(SRC_DIR)/SchemeAlgo.cpp \
$(SRC_DIR)/SecretKey.cpp \
$(SRC_DIR)/SerializationUtils.cpp \
$(SRC_DIR)/StringUtils.cpp \
$(SRC_DIR)/TestScheme.cpp \
$(SRC_DIR)/TimeUtils.cpp 

OBJS += \
$(SRC_DIR)/BootContext.o \
$(SRC_DIR)/Ciphertext.o \
$(SRC_DIR)/EvaluatorUtils.o \
$(SRC_DIR)/HEAAN.o \
$(SRC_DIR)/Key.o \
$(SRC_DIR)/Plaintext.o \
$(SRC_DIR)/Ring.o \
$(SRC_DIR)/RingMultiplier.o \
$(SRC_DIR)/Scheme.o \
$(SRC_DIR)/SchemeAlgo.o \
$(SRC_DIR)/SecretKey.o \
$(SRC_DIR)/SerializationUtils.o \
$(SRC_DIR)/StringUtils.o \
$(SRC_DIR)/TestScheme.o \
$(SRC_DIR)/TimeUtils.o 

CPP_DEPS += \
$(SRC_DIR)/BootContext.d \
$(SRC_DIR)/Ciphertext.d \
$(SRC_DIR)/EvaluatorUtils.d \
$(SRC_DIR)/HEAAN.d \
$(SRC_DIR)/Key.d \
$(SRC_DIR)/Plaintext.d \
$(SRC_DIR)/Ring.d \
$(SRC_DIR)/RingMultiplier.d \
$(SRC_DIR)/Scheme.d \
$(SRC_DIR)/SchemeAlgo.d \
$(SRC_DIR)/SecretKey.d \
$(SRC_DIR)/SerializationUtils.d \
$(SRC_DIR)/StringUtils.d \
$(SRC_DIR)/TestScheme.d \
$(SRC_DIR)/TimeUtils.d 

# Each subdirectory must supply rules for building sources it contributes
%.o: $(SRC_DIR)/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler 4 TTesTT'
	g++ -I$(INCLUDE_DIR) -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
