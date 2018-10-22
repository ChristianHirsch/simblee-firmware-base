BUILD_DIR?=./build
SRC_DIRS?=./src/
SIMBLEE_DIR?=/home/$(USER)/.arduino15/packages/Simblee/hardware/Simblee/1.1.4
SRCS:=$(shell find $(SRC_DIRS) -name '*.cpp' -or -name '*.c' -or -name '*.s')
OBJS:=$(SRCS:%=$(BUILD_DIR)/%.o)

CC=arm-none-eabi-gcc
CFLAGS=-c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -fno-builtin -MMD -mcpu=cortex-m0 -DF_CPU=16000000 -DARDUINO=10802 -mthumb -D__Simblee__

CPP=arm-none-eabi-g++
CPPFLAGS=-c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -fno-builtin -MMD -mcpu=cortex-m0 -DF_CPU=16000000 -DARDUINO=10802 -mthumb -D__Simblee__

LDFLAGS=-Wl,--gc-sections --specs=nano.specs -mcpu=cortex-m0 -mthumb -D__Simblee__ -T$(SIMBLEE_DIR)/variants/Simblee/linker_scripts/gcc/Simblee.ld -Wl,--cref -L. -Wl,--warn-common -Wl,--warn-section-align -Wl,--start-group $(SIMBLEE_DIR)/variants/Simblee/libSimbleeSystem.a $(SIMBLEE_DIR)/variants/Simblee/libSimblee.a $(BUILD_DIR)/core.a -Wl,--end-group

INCDIRS=-I./include -I$(SIMBLEE_DIR)/system/Simblee -I$(SIMBLEE_DIR)/system/CMSIS/CMSIS/Include

AR=arm-none-eabi-ar
OBJCOPY=arm-none-eabi-objcopy
RFDLOADER=$(SIMBLEE_DIR)/RFDLoader_linux

$(BUILD_DIR)/%.c.o: %.c
	$(CC) $(CFLAGS) $(INCDIRS) -o $@ $<
	$(AR) rcs $(BUILD_DIR)/core.a $@

$(BUILD_DIR)/%.cpp.o: %.cpp
	$(CPP) $(CPPFLAGS) $(INCDIRS) -o $@ $<
	$(AR) rcs $(BUILD_DIR)/core.a $@

$(BUILD_DIR)/firmware.elf: $(OBJS)
	$(CPP) $(LDFLAGS) -Wl,-Map,$@.map -o $@

$(BUILD_DIR)/firmware.hex: $(BUILD_DIR)/firmware.elf
	$(OBJCOPY) -O ihex $< $@

upload: $(BUILD_DIR)/firmware.hex
	$(RFDLOADER) /dev/ttyUSB0 $<

.PHONY: clean

clean:
	rm -f $(BUILD_DIR)/$(SRC_DIRS)/*.[od] $(BUILD_DIR)/core.a $(BUILD_DIR)/firmware.elf $(BUILD_DIR)/firmware.hex $(BUILD_DIR)/firmware.elf.map
