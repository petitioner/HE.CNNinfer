################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm

# Define the project root path
PROJECT_ROOT := $(abspath $(dir $(firstword $(MAKEFILE_LIST)))/..)

# Directories
SRC_DIR := $(PROJECT_ROOT)/src
INCLUDE_DIR := $(PROJECT_ROOT)/lib/include
HEAAN_INCLUDE_DIR := $(PROJECT_ROOT)/HEAAN/HEAAN/src
LIB_DIR := $(PROJECT_ROOT)/lib
HEAAN_LIB_DIR := $(PROJECT_ROOT)/HEAAN/HEAAN/lib

# Compiler and flags
CXX := g++
CXXFLAGS := -I$(INCLUDE_DIR) -I$(HEAAN_INCLUDE_DIR) -std=c++11 -O2 -g -Wall
LDFLAGS := -L$(LIB_DIR) -L$(HEAAN_LIB_DIR) -pthread
LIBS := -lntl -lgmp -lHEAAN

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include HEAAN/HEAAN/src/subdir.mk
-include HEAAN/HEAAN/run/subdir.mk
-include HEAAN/HEAAN/lib/src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# All Target
all: CNNinference 

# Tool invocations
CNNinference: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker4Testing'
	$(CXX) $(LDFLAGS) -o $@ $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Compile command
%.o: $(SRC_DIR)/%.cpp
	@echo 'Building file: $<'
	$(CXX) $(CXXFLAGS) -MMD -MP -MF"$(@:%.o=%.d)" -c -o $@ $<

# Other Targets
clean:
	-$(RM) $(CC_DEPS) $(C++_DEPS) $(EXECUTABLES) $(C_UPPER_DEPS) $(CXX_DEPS) $(OBJS) $(CPP_DEPS) $(C_DEPS) CNNinference
	-@echo ' '

.PHONY: all clean dependents

-include ../makefile.targets
