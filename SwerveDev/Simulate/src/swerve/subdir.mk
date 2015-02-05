################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/swerve/DoublePot.cpp \
../src/swerve/PIDValue.cpp \
../src/swerve/Swerve.cpp \
../src/swerve/SwerveModule.cpp 

OBJS += \
./src/swerve/DoublePot.o \
./src/swerve/PIDValue.o \
./src/swerve/Swerve.o \
./src/swerve/SwerveModule.o 

CPP_DEPS += \
./src/swerve/DoublePot.d \
./src/swerve/PIDValue.d \
./src/swerve/Swerve.d \
./src/swerve/SwerveModule.d 


# Each subdirectory must supply rules for building sources it contributes
src/swerve/%.o: ../src/swerve/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"C:\Team537Workspace\TestCode2015\SwerveDev/src" -IC:\Users\code01/wpilib/cpp/current/sim/include -I/usr/include -I/usr/include/gazebo-3.1 -I/usr/include/sdformat-2.2 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


