PROJECT := SillyOS
ASM := nasm
CC := gcc
CFLAGS := -m32 -ffreestanding -fno-pie -fno-builtin -fno-stack-protector -nostdlib -Isrc/libc
LD := ld
LDFLAGS := -melf_i386 -Ttext 0x1000 --oformat binary
QEMU := qemu-system-i386
QEMUFLAGS_DEFAULT := -drive if=floppy,format=raw
ifeq ($(CI),true)
QEMUFLAGS := -nographic -serial mon:stdio -no-reboot -no-shutdown
endif
SRC_DIR := src
BUILD_DIR := build
C_SRC := $(shell find $(SRC_DIR) -type f -name '*.c')
# this must be first, otherwise it breaks during linking
OBJ := $(BUILD_DIR)/kernel_entry.o
OBJ += $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(C_SRC))
BOOTLOADER := $(SRC_DIR)/bootloader.asm
KERNEL_ENTRY := $(SRC_DIR)/kernel/kernel_entry.asm
ISO := $(BUILD_DIR)/boot/boot.img
.PHONY: all build run clean

all: build

build: $(ISO)

# create the final bootable `build/boot/boot.iso` file
$(ISO): $(BUILD_DIR)/bootloader.bin $(BUILD_DIR)/kernel.bin
	@mkdir -p $(@D)
	cat $^ > $@

# compile the bootloader
$(BUILD_DIR)/bootloader.bin: $(BOOTLOADER)
	@mkdir -p $(@D)
	$(ASM) -f bin $< -o $@

# compile the kernel entry
$(BUILD_DIR)/kernel_entry.o: $(KERNEL_ENTRY)
	@mkdir -p $(@D)
	$(ASM) -f elf32 $< -o $@

# compile the kernel
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# link the kernel
$(BUILD_DIR)/kernel.bin: $(OBJ)
	@mkdir -p $(@D)
	$(LD) $(LDFLAGS) $^ -o $@

run: $(ISO)
	$(QEMU) $(QEMUFLAGS) $(QEMUFLAGS_DEFAULT),file=$<

clean:
	rm -rf $(BUILD_DIR)

