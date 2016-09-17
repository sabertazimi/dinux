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
CP = cp -fr
MKDIR = mkdir -p

# macro for flags
C_FLAGS = -c -Wall -m32 -ggdb -gstabs+ -nostdinc -fno-builtin -fno-stack-protector -I include
LD_FLAGS = -T $(TOOLS_DIR)/kernel.ld -m elf_i3866 -nostdlib
ASM_FLAGS = -f elf -g -F stabs

# names
KERNEL_NAME=dinux

# path
BIN_DIR = bin
MOUNT_DIR = /mnt/dinux
TOOLS_DIR = tools

all: $(S_OBJECTS) $(C_OBJECTS) link update_image

.c.o:
	@echo Compiling C Source Files $< ...
	$(CC) $(C_FLAGS) $< -o $@

.s.o:
	@echo Compiling Asm Source Files $< ...
	$(ASM) $(ASM_FLAGS) $<

link:
	@echo Linking kernel image
	$(LD) $(LD_FLAGS) $(S_OBJECTS) $(C_OBJECTS) -o $(BIN_DIR)/$(KERNEL_NAME)

.PHONY:clean
clean:
	$(RM) $(S_OBJECTS) $(C_OBJECTS) $(BIN_DIR)/$(KERNEL_NAME)

.PHONY:create_image
create_image:
	dd if=/dev/zero of=floppy.img bs=512 count=2880
	mkfs.vfat floppy.img
	mv floppy.img $(BIN_DIR)

.PHONY:update_image
update_image:
	make mount_image
	sudo $(CP) $(BIN_DIR)/$(KERNEL_NAME) $(MOUNT_DIR)/$(KERNEL_NAME)
	sleep 1
	make umount_image

.PHONY:mount_image
mount_image:
	sudo $(MKDIR) $(MOUNT_DIR)
	sudo mount $(BIN_DIR)/floppy.img $(MOUNT_DIR)

.PHONY:umount_image
umount_image:
	sudo umount $(MOUNT_DIR)

.PHONY:qemu
qemu:
	qemu -fda $(BIN_DIR)/floppy.img -boot a

.PHONY:bochs
bochs:
	bochs -f $(TOOLS_DIR)/bochsrc.conf

.PHONY:debug
debug:
	qemu -S -s -fda $(BIN_DIR)/floppy.img -boot -a &
	sleep 1
	cgdb -x $(TOOLS_DIR)/gdbinit

# vim:ft=make
#
