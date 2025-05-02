ASM := nasm
SRC := bootloader.asm
OUT := ../build/bootloader.bin

.PHONY: all clean

all: $(OUT)

$(OUT): $(SRC)
	@mkdir -p ../build
	$(ASM) -f bin $< -o $@

clean:
	rm -f $(OUT)
