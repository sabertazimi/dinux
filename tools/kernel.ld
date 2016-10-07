/*
 * OUTPUT_FORMAT("binary")
 */
ENTRY(start)
SECTIONS {
    /*
     * __bios__ = 0xa0000;  # 绑定BIOS保留内存的地址到__bios__
     * vgamem = 0xb8000;    # 绑定vga缓冲区的地址到符号vgamem
     */
    . = 0x100000;
    PROVIDE(kern_start = .);
    .text : {            /* 内核二进制镜像中的 .text 段(Section), 从 0x100000 开始 */
        __begin__ = .;   
        __code__ = .;
        /* bin/entry.o(.text) bin/main.o(.text) *(.text); # 将bin/entry.o中的 .text 段安排到内核镜像的最前方 */
        . = ALIGN(4096); /* 4KB 对齐 */
    }
    .data : {
        __data__ = .;
        *(.data);
        *(.rodata);
        . = ALIGN(4096);
    }
    .bss : {
        __bss__ = .;
        *(.bss);
        . = ALIGN(4096);
    }
    .stab : {
        *(.stab)
        . = ALIGN(4096);
    }
    .stabstr : {
        *.(stabstr)
        . = ALIGN(4096);
    }
    /DISCARD/ : {
        *(.comment) *(.eh_frame)
    }
    PROVIDE(kern_end = .);
    __end__ = .;
}
