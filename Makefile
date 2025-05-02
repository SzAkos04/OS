PROJECT := SillyOS
BUILD_DIR := build
ISO := $(BUILD_DIR)/boot.img
QEMU := qemu-system-i386
QEMUFLAGS := --no-reboot -drive format=raw,file=$(ISO)

.PHONY: all build run clean boot kernel

all: build

build: $(ISO)

$(ISO): boot kernel
	@mkdir -p $(BUILD_DIR)
	cat $(BUILD_DIR)/bootloader.bin $(BUILD_DIR)/kernel.bin > $(ISO)

boot:
	$(MAKE) -C boot

kernel:
	$(MAKE) -C kernel

run: $(ISO)
	$(QEMU) $(QEMUFLAGS)

clean:
	$(MAKE) -C boot clean
	$(MAKE) -C kernel clean
	rm -rf $(BUILD_DIR)
