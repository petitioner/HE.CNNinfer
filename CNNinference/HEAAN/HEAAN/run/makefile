# This sample should be run after make libHEAAN.a file in lib folder

# Define the project root path (assumes this Makefile is in a directory under the project root)
PROJECT_ROOT := $(abspath $(dir $(firstword $(MAKEFILE_LIST)))/../../../..)

# Directories
LIB_DIR := $(PROJECT_ROOT)/lib
SRC_DIR := $(PROJECT_ROOT)/src
HEAAN_LIB := $(LIB_DIR)/libHEAAN.a

# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++11 -O2 -I$(SRC_DIR) -pthread
LDFLAGS := -L$(LIB_DIR) -lntl -lgmp -lm

# All Target
all: clean TestHEAAN

# Tool invocations
TestHEAAN:
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	$(CXX) test.cpp -o TestHEAAN $(LDFLAGS) $(HEAAN_LIB)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	@echo 'Cleaning up...'
	rm -f TestHEAAN
