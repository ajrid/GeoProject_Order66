################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS := 


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../GeoCache.cpp


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
GeoCache.o

OBJS_AS_ARGS +=  \
GeoCache.o

C_DEPS +=  \
GeoCache.d

C_DEPS_AS_ARGS +=  \
GeoCache.d

OUTPUT_FILE_PATH +=Geocache.elf

OUTPUT_FILE_PATH_AS_ARGS +=Geocache.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+=  \
E:/Xzecutus/Desktop/GeoProject_Order66/Resources/Resources/COASolutions/ArduinoCore/Debug/libArduinoCore.a \
E:/Xzecutus/Desktop/GeoProject_Order66/Resources/Resources/COASolutions/NeoPixel/Debug/libNeoPixel.a \
E:/Xzecutus/Desktop/GeoProject_Order66/Resources/Resources/COASolutions/OneSheeld/Debug/libOneSheeld.a \
E:/Xzecutus/Desktop/GeoProject_Order66/Resources/Resources/COASolutions/SecureDigital/Debug/libSecureDigital.a \
E:/Xzecutus/Desktop/GeoProject_Order66/Resources/Resources/COASolutions/SoftwareSerial/Debug/libSoftwareSerial.a

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler



./%.o: .././%.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 4.9.2
	$(QUOTE)E:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DARDUINO=168 -DF_CPU=16000000L -DDEBUG  -I"../../ArduinoCore" -I"../../NeoPixel" -I"../../SoftwareSerial" -I"../../OneSheeld" -I"../../SecureDigital"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega328p -B "E:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.0.106\gcc\dev\atmega328p" -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR8/GNU Linker : 4.9.2
	$(QUOTE)E:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="Geocache.map" -Wl,--start-group -Wl,-lLABLibrary -Wl,-lArduinoCore -Wl,-lNeoPixel -Wl,-lOneSheeld -Wl,-lSecureDigital -Wl,-lSoftwareSerial  -Wl,--end-group -Wl,-L"F:\COA\GeoProject_Order66\GeoCache\GeoCache" -Wl,-L"E:\Xzecutus\Desktop\GeoProject_Order66\Resources\Resources\COASolutions\ArduinoCore\Debug" -Wl,-L"E:\Xzecutus\Desktop\GeoProject_Order66\Resources\Resources\COASolutions\NeoPixel\Debug" -Wl,-L"E:\Xzecutus\Desktop\GeoProject_Order66\Resources\Resources\COASolutions\OneSheeld\Debug" -Wl,-L"E:\Xzecutus\Desktop\GeoProject_Order66\Resources\Resources\COASolutions\SecureDigital\Debug" -Wl,-L"E:\Xzecutus\Desktop\GeoProject_Order66\Resources\Resources\COASolutions\SoftwareSerial\Debug"  -Wl,--gc-sections -mmcu=atmega328p -B "E:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.0.106\gcc\dev\atmega328p"  
	@echo Finished building target: $@
	"E:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "Geocache.elf" "Geocache.hex"
	"E:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "Geocache.elf" "Geocache.eep" || exit 0
	"E:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "Geocache.elf" > "Geocache.lss"
	"E:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "Geocache.elf" "Geocache.srec"
	"E:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "Geocache.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "Geocache.elf" "Geocache.a" "Geocache.hex" "Geocache.lss" "Geocache.eep" "Geocache.map" "Geocache.srec" "Geocache.usersignatures"
	