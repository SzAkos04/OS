ASM := nasm
CC := gcc
QEMU := qemu-system-i386
QEMUFLAGS := -fda
PROJECT := OS
ASMFLAGS := -f bin
SRC_DIR := src
BOOTLOADER := $(wildcard $(SRC_DIR)/bootloader.asm)
BUILD_DIR := build
ISO := $(BUILD_DIR)/boot/boot.iso
.PHONY: all build run clean

all: build

build: $(ISO)

$(ISO): $(BUILD_DIR)/$(PROJECT).bin
	@mkdir -p $(@D)
	dd if=/dev/zero of=$@ bs=512 count=2880
	dd if=$< of=$@ conv=notrunc

$(BUILD_DIR)/$(PROJECT).bin: $(BOOTLOADER)
	@mkdir -p $(@D)
	$(ASM) $(ASMFLAGS) $< -o $@

run: build
	@od -t x1 -A n $(BUILD_DIR)/$(PROJECT).bin
	$(QEMU) $(QEMUFLAGS) $(ISO)

clean:
	rm -rf $(BUILD_DIR)
