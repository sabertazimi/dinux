#
# Makefile
# sabertazimi, 2016-09-17 14:16
#

C_SOURCES = $(shell find . -name "*.c")
C_OBJECTS = $(patsubst %.c, %.o, $(C_SOURCES))
S_SOURCES = $(shell find . -name "*.S")
S_OBJECTS = $(patsubst %.s, %.o, $(S_SOURCES))

# macro for tools
CC = gcc
LD = ld
ASM = nasm
RM = rm -fr
MV = mv
MKDIR = mkdir -p

# macro for flags
C_FLAGS = -c -Wall -m32 -ggdb -gstabs+ -nostdinc -fno-builtin -fno-stack-protector -I include
LD_FLAGS = -T tools/kernel.ld -m elf_i3866 -nostdlib
ASM_FLAGS = -f elf -g -F stabs

all: $(S_OBJECTS) $(C_OBJECTS) link update_image

.c.o:
	@echo Compiling C Source Files $< ...
	$(CC) $(C_FLAGS) $< -o $@

.s.o:
	@echo Compiling Asm Source Files $< ...
	$(ASM) $(ASM_FLAGS) $<

link:
	@echo Linking kernel image
	$(LD) $(LD_FLAGS) $(S_OBJECTS) $(C_OBJECTS) -o dinux

.PHONY:clean
clean:
	$(RM) $(S_OBJECTS) $(C_OBJECTS) dinux

.PHONY:update_image
	make mount_image
	sudo cp dinux /mnt/kernel/dinux
	sleep 1
	make umount_image

.PHONY:mount_image
mount_image:
	sudo mount floppy.img /mnt/kernel

.PHONY:umount_image
umount_image:
	sudo umount /mnt/kernel

.PHONY:qemu
qemu:
	qemu -fda floppy.img -boot a

.PHONY:bochs
bochs:
	bochs -f tools/bochsrc.conf

.PHONY:debug
debug:
	qemu -S -s -fda floppy.img -boot -a &
	sleep 1
	cgdb -x tools/gdbinit

# vim:ft=make
#
