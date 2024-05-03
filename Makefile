ASM := nasm
CC := gcc
QEMU := qemu-system-i386
PROJECT := OS
ASMFLAGS := -f bin
SRC_DIR := src
SRC_ASM := $(wildcard $(SRC_DIR)/bootloader.asm)
BUILD_DIR := build
.PHONY: all build run clean

all: build

build: $(BUILD_DIR)/$(PROJECT).bin

$(BUILD_DIR)/$(PROJECT).bin: $(SRC_ASM)
	@mkdir -p $(@D)
	$(ASM) $(ASMFLAGS) $< -o $@

run: build
	@od -t x1 -A n $(BUILD_DIR)/$(PROJECT).bin
	$(QEMU) $(BUILD_DIR)/$(PROJECT).bin

clean:
	rm -rf $(BUILD_DIR)
