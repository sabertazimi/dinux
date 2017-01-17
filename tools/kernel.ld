/*
 * OUTPUT_FORMAT("binary")
 */
ENTRY(start)
SECTIONS {
    /*
     * __bios__ = 0xa0000;  # 绑定BIOS保留内存的地址到__bios__
     * vgamem = 0xb8000;    # 绑定vga缓冲区的地址到符号vgamem
     */
    PROVIDE(kern_start = 0xc0100000);
    . = 0x100000;
    .init.text : {
        *(.init.text);
        . = ALIGN(4096);
    }
    .init.data : {
        *(.init.data);
        . = ALIGN(4096);
    }
    . += 0xc0000000;
    .text : AT(ADDR(.text) - 0xc0000000) { /* 内核二进制镜像中的 .text 段(Section), 从 0x100000 开始 */
        __begin__ = .;   
        __code__ = .;
        /* bin/entry.o(.text) bin/main.o(.text) *(.text); # 将bin/entry.o中的 .text 段安排到内核镜像的最前方 */
        . = ALIGN(4096); /* 4KB 对齐 */
    }
    .data : AT(ADDR(.data) - 0xc0000000) {
        __data__ = .;
        *(.data);
        *(.rodata);
        . = ALIGN(4096);
    }
    .bss : AT(ADDR(.bss) - 0xc0000000) {
        __bss__ = .;
        *(.bss);
        . = ALIGN(4096);
    }
    .stab : AT(ADDR(.stab) - 0xc0000000) {
        *(.stab)
        . = ALIGN(4096);
    }
    .stabstr : AT(ADDR(.stabstr) - 0xc0000000) {
        *.(stabstr)
        . = ALIGN(4096);
    }
    PROVIDE(kern_end = .);
    __end__ = .;
    /DISCARD/ : {
        *(.comment) *(.eh_frame)
    }
}
