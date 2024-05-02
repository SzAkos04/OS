ASM := nasm
CC := gcc
LD := ld
QEMU := qemu-system-i386
PROJECT := OS
ASMFLAGS := -f elf
CFLAGS := -m16 -nostdlib -fno-pie -fno-stack-protector
LDFLAGS := -m elf_i386 -Ttext 0x7e00 --oformat binary
SRC_DIR := src
SRC_ASM := $(wildcard $(SRC_DIR)/*.asm)
SRC_C := $(wildcard $(SRC_DIR)/*.c)
BUILD_DIR := build
OBJ_ASM := $(SRC_ASM:$(SRC_DIR)/%.asm=$(BUILD_DIR)/%.o)
OBJ_C := $(SRC_C:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
.PHONY: all build run clean

all: build

build: $(BUILD_DIR)/$(PROJECT).bin

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.asm
	@mkdir -p $(@D)
	$(ASM) $(ASMFLAGS) $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/$(PROJECT).bin: $(OBJ_ASM) $(OBJ_C)
	$(LD) $^ -o $@ $(LDFLAGS)

run: build
	@od -t x1 -A n $(BUILD_DIR)/$(PROJECT).bin
	$(QEMU) $(BUILD_DIR)/$(PROJECT).bin

clean:
	rm -rf $(BUILD_DIR)
