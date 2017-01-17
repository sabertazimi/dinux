# dinux

A toy operating system

```sh
     _ _
  __| (_)_ __  _   ___  __
 / _` | | '_ \| | | \ \/ /
| (_| | | | | | |_| |>  <
 \__,_|_|_| |_|\__,_/_/\_\
```

[![Author](https://img.shields.io/badge/author-sabertazimi-lightgrey.svg)](https://github.com/sabertazimi)
[![Stable](https://img.shields.io/badge/stability-stable-brightgreen.svg)](https://github.com/sabertazimi/dinux)
[![MIT](https://img.shields.io/badge/license-mit-brightgreen.svg)](https://github.com/sabertazimi/dinux/blob/master/LICENSE)

## Installation

```sh
$ sudo apt install libc6-dev-i386 build-essential
$ sudo apt install nasm qemu bochs
```

```sh
$ wget http://alpha.gnu.org/gnu/grub/grub-0.97-i386-pc.tar.gz
$ tar xzvf grub-0.97-i386-pc.tar.gz
$ dd if=/dev/zero of=floppy.img bs=512 count=2880
$ mkfs.vfat floppy.img
$ sudo mount floppy.img /mnt/dinux
$ sudo mkdir -p /mnt/dinux/boot/grub
$ sudo cp -fr grub-0.97-i386-pc/boot/grub/stage1 grub-0.97-i386-pc/boot/grub/stage2 /mnt/dinux/boot/grub
$ sudo vim /mnt/dinux/boot/grub/grub.conf
```

## Bootloader/Grub

利用现成的 bootloader - grub 可以不用编写 **A20开启** 与 **内核装载** 的代码, grub 将 kernel 加载进内核后, 整个计算机处于:

*   A20 开启
*   段/页机制关闭

## CGA/VGA Text Memory

通过向物理地址(最低 1MB) 0x8b000 写数据, 可实现简单的打印字符功能. 从 0x8b000 开始将其视为一个 元素为 2 字节数据, 大小为 25*80 的二维数组. 数组元素所包含信息如下所示:

*   (hi -> lo) 4 - 4 - 8: background_color - foreground_color - character_ascii

## License

MIT License Copyright (c) 2016 [sabertazimi](https://github.com/sabertazimi)

## Contact

-   [![Email](https://img.shields.io/badge/mailto-sabertazimi-brightgreen.svg?style=flat-square)](mailto:sabertazimi@gmail.com)
-   [![GitHub](https://img.shields.io/badge/contact-github-000000.svg?style=flat-square)](https://github.com/sabertazimi)
-   [![Twitter](https://img.shields.io/badge/contact-twitter-blue.svg?style=flat-square)](https://twitter.com/sabertazimi)
