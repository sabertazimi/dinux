# dinux

A toy operating system

[![Author](https://img.shields.io/badge/author-sabertazimi-lightgrey.svg)](https://github.com/sabertazimi)
[![Stable](https://img.shields.io/badge/stability-stable-brightgreen.svg)](https://github.com/sabertazimi/dinux)
[![MIT](https://img.shields.io/badge/license-mit-brightgreen.svg)](https://github.com/sabertazimi/dinux/blob/master/LICENSE)

## Installation

```sh
$ sudo apt install build-essential nasm
$ sudo apt install cgdb
$ sudo apt install qemu bochs
$ sudo ln -s /usr/bin/qemu-system-i386 /usr/bin/qemu
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

## License

MIT License Copyright (c) 2016 [sabertazimi](https://github.com/sabertazimi)

## Contact

-   [![Email](https://img.shields.io/badge/mailto-sabertazimi-brightgreen.svg?style=flat-square)](mailto:sabertazimi@gmail.com)
-   [![GitHub](https://img.shields.io/badge/contact-github-000000.svg?style=flat-square)](https://github.com/sabertazimi)
-   [![Twitter](https://img.shields.io/badge/contact-twitter-blue.svg?style=flat-square)](https://twitter.com/sabertazimi)
