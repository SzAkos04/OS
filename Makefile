ASM := nasm
CC := gcc
QEMU := qemu-system-i386
PROJECT := OS
ASMFLAGS := -f bin
SRC_DIR := src
SRC_ASM := $(wildcard $(SRC_DIR)/*.asm)
BUILD_DIR := build
BOOTLOADER_SRC := $(SRC_DIR)/bootloader.asm
KERNEL_SRC := $(filter-out $(BOOTLOADER_SRC), $(SRC_ASM))
.PHONY: all build run clean

all: build

build: $(BUILD_DIR)/$(PROJECT).bin

$(BUILD_DIR)/$(PROJECT).bin: $(BOOTLOADER_SRC) $(KERNEL_SRC)
	@mkdir -p $(@D)
	$(ASM) $(ASMFLAGS) $(BOOTLOADER_SRC) -o $@
	$(ASM) $(ASMFLAGS) $(KERNEL_SRC) -o $(BUILD_DIR)/kernel.bin

run: build
	@od -t x1 -A n $(BUILD_DIR)/$(PROJECT).bin
	$(QEMU) $(BUILD_DIR)/$(PROJECT).bin

clean:
	rm -rf $(BUILD_DIR)
