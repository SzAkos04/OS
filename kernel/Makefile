ASM := nasm
CC := gcc
LD := ld

BUILD_DIR := ../build
INCLUDE_DIR := ../include
CFLAGS := -m32 -ffreestanding -fno-pie -fno-stack-protector -nostdlib -I$(INCLUDE_DIR)
LDFLAGS := -melf_i386 -Ttext 0x1000 --oformat binary

ASM_SRC := kernel_entry.asm
C_SRC := $(wildcard *.c)

ASM_OBJ := $(patsubst %.asm, $(BUILD_DIR)/kernel/%.o, $(ASM_SRC))
C_OBJ := $(patsubst %.c, $(BUILD_DIR)/kernel/%.o, $(C_SRC))
OBJ := $(ASM_OBJ) $(C_OBJ)

.PHONY: all clean

all: $(BUILD_DIR)/kernel.bin

$(BUILD_DIR)/kernel.bin: $(OBJ)
	@mkdir -p $(dir $@)
	$(LD) $(LDFLAGS) -o $@ $^

$(BUILD_DIR)/kernel/%.o: %.asm
	@mkdir -p $(dir $@)
	$(ASM) -f elf32 $< -o $@

$(BUILD_DIR)/kernel/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)/kernel
	rm -f $(BUILD_DIR)/kernel.bin
