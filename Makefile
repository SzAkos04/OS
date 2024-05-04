PROJECT := OS
ASM := nasm
ASMFLAGS := -f bin
CC := gcc
CFLAGS := -m32 -ffreestanding -fno-pie
LD := ld
LDFLAGS := -melf_i386 -Ttext 0x1000 --oformat binary
QEMU := qemu-system-i386
QEMUFLAGS := -drive if=floppy,format=raw
SRC_DIR := src
BUILD_DIR := build
C_SRC := $(shell find $(SRC_DIR) -type f -name '*.c')
OBJ := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(C_SRC))
BOOTLOADER := $(SRC_DIR)/bootloader.asm
ISO := $(BUILD_DIR)/boot/boot.iso
.PHONY: all build run clean

all: build

build: $(ISO)

$(ISO): $(BUILD_DIR)/$(PROJECT).bin $(BUILD_DIR)/kernel.bin
	cat $^ > $@

$(BUILD_DIR)/$(PROJECT).bin: $(BOOTLOADER)
	@mkdir -p $(@D)
	$(ASM) $(ASMFLAGS) $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/kernel.bin: $(OBJ)
	@mkdir -p $(@D)
	$(LD) -o $@ $(LDFLAGS) $^

run: build
	@od -t x1 -A n $(BUILD_DIR)/$(PROJECT).bin
	$(QEMU) $(QEMUFLAGS),file=$(ISO)

clean:
	rm -rf $(BUILD_DIR)
