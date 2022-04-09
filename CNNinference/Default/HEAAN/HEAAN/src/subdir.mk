################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../HEAAN/HEAAN/src/BootContext.cpp \
../HEAAN/HEAAN/src/Ciphertext.cpp \
../HEAAN/HEAAN/src/EvaluatorUtils.cpp \
../HEAAN/HEAAN/src/HEAAN.cpp \
../HEAAN/HEAAN/src/Key.cpp \
../HEAAN/HEAAN/src/Plaintext.cpp \
../HEAAN/HEAAN/src/Ring.cpp \
../HEAAN/HEAAN/src/RingMultiplier.cpp \
../HEAAN/HEAAN/src/Scheme.cpp \
../HEAAN/HEAAN/src/SchemeAlgo.cpp \
../HEAAN/HEAAN/src/SecretKey.cpp \
../HEAAN/HEAAN/src/SerializationUtils.cpp \
../HEAAN/HEAAN/src/StringUtils.cpp \
../HEAAN/HEAAN/src/TestScheme.cpp \
../HEAAN/HEAAN/src/TimeUtils.cpp 

OBJS += \
./HEAAN/HEAAN/src/BootContext.o \
./HEAAN/HEAAN/src/Ciphertext.o \
./HEAAN/HEAAN/src/EvaluatorUtils.o \
./HEAAN/HEAAN/src/HEAAN.o \
./HEAAN/HEAAN/src/Key.o \
./HEAAN/HEAAN/src/Plaintext.o \
./HEAAN/HEAAN/src/Ring.o \
./HEAAN/HEAAN/src/RingMultiplier.o \
./HEAAN/HEAAN/src/Scheme.o \
./HEAAN/HEAAN/src/SchemeAlgo.o \
./HEAAN/HEAAN/src/SecretKey.o \
./HEAAN/HEAAN/src/SerializationUtils.o \
./HEAAN/HEAAN/src/StringUtils.o \
./HEAAN/HEAAN/src/TestScheme.o \
./HEAAN/HEAAN/src/TimeUtils.o 

CPP_DEPS += \
./HEAAN/HEAAN/src/BootContext.d \
./HEAAN/HEAAN/src/Ciphertext.d \
./HEAAN/HEAAN/src/EvaluatorUtils.d \
./HEAAN/HEAAN/src/HEAAN.d \
./HEAAN/HEAAN/src/Key.d \
./HEAAN/HEAAN/src/Plaintext.d \
./HEAAN/HEAAN/src/Ring.d \
./HEAAN/HEAAN/src/RingMultiplier.d \
./HEAAN/HEAAN/src/Scheme.d \
./HEAAN/HEAAN/src/SchemeAlgo.d \
./HEAAN/HEAAN/src/SecretKey.d \
./HEAAN/HEAAN/src/SerializationUtils.d \
./HEAAN/HEAAN/src/StringUtils.d \
./HEAAN/HEAAN/src/TestScheme.d \
./HEAAN/HEAAN/src/TimeUtils.d 


# Each subdirectory must supply rules for building sources it contributes
HEAAN/HEAAN/src/%.o: ../HEAAN/HEAAN/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/tree/Downloads/IDASH2017-master/IDASH2017/HEAAN/HEAAN/src" -I"/home/tree/Downloads/IDASH2017-master/IDASH2017/lib/include" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


