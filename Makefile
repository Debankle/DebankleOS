C_SOURCES = $(wildcard drivers/*.c kernel/*.c libc/*.c cpu/*.c)
S_SOURCES = $(wildcard boot/*.s drivers/*.s cpu/*.s kernel/*.s)

C_OBJECTS = ${C_SOURCES:.c=.o}
S_OBJECTS = ${S_SOURCES:.s=.o}

CC = gcc
CFLAGS = -g -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector \
			-nostartfiles -nodefaultlibs -c -Wall -Wextra -Werror
LDFLAGS = -T link.ld -melf_i386
AS = nasm
ASFLAGS = -f elf

all: kernel.elf

kernel.elf: $(C_OBJECTS) $(S_OBJECTS)
	ld $(LDFLAGS) $^ -o kernel.elf

os.iso: kernel.elf
	cp kernel.elf iso/boot/kernel.elf
	genisoimage -R -b boot/grub/stage2_eltorito \
		-no-emul-boot -boot-load-size 4 -A os \
		-input-charset utf8 -quiet -boot-info-table \
		-o os.iso iso

run: os.iso
	bochs -f bochsrc.txt -q

%.o: %.c
	$(CC) $(CFLAGS)  $< -o $@

%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

clean:
	rm -rf $(C_OBJECTS) $(S_OBJECTS) kernel.elf os.iso bochslog.txt