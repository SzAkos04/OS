ASM := nasm
ASMFLAGS := -f bin
QEMU := qemu-system-i386
# QEMUFLAGS := -fda
QEMUFLAGS := -drive if=floppy,format=raw
PROJECT := OS
SRC_DIR := src
BOOTLOADER := $(SRC_DIR)/bootloader.asm
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
	$(QEMU) $(QEMUFLAGS),file=$(ISO)

clean:
	rm -rf $(BUILD_DIR)
