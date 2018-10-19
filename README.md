# Program Simblee from command line
```
~/.arduino15/packages/Simblee/hardware/Simblee/1.1.4/RFDLoader_linux /dev/ttyUSB0 *.ino.hex
```

Important files:
```
arm-none-eabi-gcc -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -fno-builtin -MMD -mcpu=cortex-m0 -DF_CPU=16000000 -DARDUINO=10802 -mthumb -D__Simblee__ itoa.c -o itoa.c.o
arm-none-eabi-g++ -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -fno-builtin -MMD -mcpu=cortex-m0 -DF_CPU=16000000 -DARDUINO=10802 -mthumb -D__Simblee__ -I. -I./system/Simblee -I./system/CMSIS/CMSIS/Include main.cpp -o main.cpp.o
arm-none-eabi-gcc -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -fno-builtin -MMD -mcpu=cortex-m0 -DF_CPU=16000000 -DARDUINO=10802 -mthumb -D__Simblee__ -I. -I./system/Simblee -I./system/CMSIS/CMSIS/Include Memory.c -o Memory.c.o
arm-none-eabi-g++ -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -fno-builtin -MMD -mcpu=cortex-m0 -DF_CPU=16000000 -DARDUINO=10802 -mthumb -D__Simblee__ -I. -I./system/Simblee -I./system/CMSIS/CMSIS/Include Print.cpp -o Print.cpp.o
arm-none-eabi-g++ -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -fno-builtin -MMD -mcpu=cortex-m0 -DF_CPU=16000000 -DARDUINO=10802 -mthumb -D__Simblee__ -I. -I./system/Simblee -I./system/CMSIS/CMSIS/Include RingBuffer.cpp -o RingBuffer.cpp.o
arm-none-eabi-g++ -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -fno-builtin -MMD -mcpu=cortex-m0 -DF_CPU=16000000 -DARDUINO=10802 -mthumb -D__Simblee__ -I. -I./system/Simblee -I./system/CMSIS/CMSIS/Include Stream.cpp -o Stream.cpp.o
arm-none-eabi-g++ -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -fno-builtin -MMD -mcpu=cortex-m0 -DF_CPU=16000000 -DARDUINO=10802 -mthumb -D__Simblee__ -I. -I./system/Simblee -I./system/CMSIS/CMSIS/Include Tone.cpp -o Tone.cpp.o
arm-none-eabi-g++ -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -fno-builtin -MMD -mcpu=cortex-m0 -DF_CPU=16000000 -DARDUINO=10802 -mthumb -D__Simblee__ -I. -I./system/Simblee -I./system/CMSIS/CMSIS/Include UARTClass.cpp -o UARTClass.cpp.o
arm-none-eabi-g++ -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -fno-builtin -MMD -mcpu=cortex-m0 -DF_CPU=16000000 -DARDUINO=10802 -mthumb -D__Simblee__ -I. -I./system/Simblee -I./system/CMSIS/CMSIS/Include variant.cpp -o variant.cpp.o
arm-none-eabi-gcc -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -fno-builtin -MMD -mcpu=cortex-m0 -DF_CPU=16000000 -DARDUINO=10802 -mthumb -D__Simblee__ -I. -I./system/Simblee -I./system/CMSIS/CMSIS/Include WInterrupts.c -o WInterrupts.c.o
arm-none-eabi-gcc -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -fno-builtin -MMD -mcpu=cortex-m0 -DF_CPU=16000000 -DARDUINO=10802 -mthumb -D__Simblee__ -I. -I./system/Simblee -I./system/CMSIS/CMSIS/Include wiring_analog.c -o wiring_analog.c.o
arm-none-eabi-gcc -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -fno-builtin -MMD -mcpu=cortex-m0 -DF_CPU=16000000 -DARDUINO=10802 -mthumb -D__Simblee__ -I. -I./system/Simblee -I./system/CMSIS/CMSIS/Include wiring.c -o wiring.c.o
arm-none-eabi-gcc -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -fno-builtin -MMD -mcpu=cortex-m0 -DF_CPU=16000000 -DARDUINO=10802 -mthumb -D__Simblee__ -I. -I./system/Simblee -I./system/CMSIS/CMSIS/Include wiring_digital.c -o wiring_digital.c.o
arm-none-eabi-g++ -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -fno-builtin -MMD -mcpu=cortex-m0 -DF_CPU=16000000 -DARDUINO=10802 -mthumb -D__Simblee__ -I. -I./system/Simblee -I./system/CMSIS/CMSIS/Include wiring_pulse.cpp -o wiring_pulse.cpp.o
arm-none-eabi-gcc -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -fno-builtin -MMD -mcpu=cortex-m0 -DF_CPU=16000000 -DARDUINO=10802 -mthumb -D__Simblee__ -I. -I./system/Simblee -I./system/CMSIS/CMSIS/Include wiring_shift.c -o wiring_shift.c.o
arm-none-eabi-g++ -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -fno-builtin -MMD -mcpu=cortex-m0 -DF_CPU=16000000 -DARDUINO=10802 -mthumb -D__Simblee__ -I. -I./system/Simblee -I./system/CMSIS/CMSIS/Include WMath.cpp -o WMath.cpp.o
arm-none-eabi-g++ -c -g -Os -w -std=gnu++11 -ffunction-sections -fdata-sections -fno-rtti -fno-exceptions -fno-builtin -MMD -mcpu=cortex-m0 -DF_CPU=16000000 -DARDUINO=10802 -mthumb -D__Simblee__ -I. -I./system/Simblee -I./system/CMSIS/CMSIS/Include WString.cpp -o  WString.cpp.o # https://github.com/arduino/ArduinoCore-samd/pull/195
arm-none-eabi-gcc -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -fno-builtin -MMD -mcpu=cortex-m0 -DF_CPU=16000000 -DARDUINO=10802 -mthumb -D__Simblee__ -I. -I./system/Simblee -I./system/CMSIS/CMSIS/Include syscalls.c -o syscalls.c.o
arm-none-eabi-gcc -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -fno-builtin -MMD -mcpu=cortex-m0 -DF_CPU=16000000 -DARDUINO=10802 -mthumb -D__Simblee__ -I. -I./system/Simblee -I./system/CMSIS/CMSIS/Include hooks.c -o hooks.c.o

arm-none-eabi-ar rcs core.a itoa.c.o
arm-none-eabi-ar rcs core.a hooks.c.o
arm-none-eabi-ar rcs core.a main.cpp.o
arm-none-eabi-ar rcs core.a Memory.c.o
arm-none-eabi-ar rcs core.a Print.cpp.o
arm-none-eabi-ar rcs core.a RingBuffer.cpp.o
arm-none-eabi-ar rcs core.a Stream.cpp.o
arm-none-eabi-ar rcs core.a syscalls.c.o
arm-none-eabi-ar rcs core.a Tone.cpp.o
arm-none-eabi-ar rcs core.a UARTClass.cpp.o
arm-none-eabi-ar rcs core.a WInterrupts.c.o
arm-none-eabi-ar rcs core.a wiring_analog.c.o
arm-none-eabi-ar rcs core.a wiring.c.o
arm-none-eabi-ar rcs core.a wiring_digital.c.o
arm-none-eabi-ar rcs core.a wiring_pulse.cpp.o
arm-none-eabi-ar rcs core.a wiring_shift.c.o
arm-none-eabi-ar rcs core.a WMath.cpp.o
arm-none-eabi-ar rcs core.a WString.cpp.o

arm-none-eabi-g++ -Wl,--gc-sections --specs=nano.specs -mcpu=cortex-m0 -mthumb -D__Simblee__ -TSimblee.ld -Wl,-Map,firmware.ino.map -Wl,--cref -o firmware.ino.elf -L. -Wl,--warn-common -Wl,--warn-section-align -Wl,--start-group syscalls.c.o variant.cpp.o libSimbleeSystem.a core.a -Wl,--end-group
arm-none-eabi-objcopy -O ihex firmware.ino.elf firmware.ino.hex
```
