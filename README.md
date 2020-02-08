# circle-stdlib

![Status badge for master branch](https://github.com/smuehlst/circle-stdlib/workflows/branch%20%22master%22/badge.svg)
![Status badge for develop branch](https://github.com/smuehlst/circle-stdlib/workflows/branch%20%22develop%22/badge.svg)

## Overview

The goal of this project is to provide C and C++ standard library support for the
Raspberry Pi bare metal environment [Circle](https://github.com/rsta2/circle).

[Newlib](https://sourceware.org/newlib/) is used as the standard C library. The fork
[circle-newlib](https://github.com/smuehlst/circle-newlib) contains the changes for
building Newlib in combination with Circle.

[mbed TLS](https://tls.mbed.org/) can optionally be used for TLS connections in
Circle (call configure with `--opt-tls`, see also the
[README file for circle-mbedtls](circle-mbedtls.md)).

## Getting Started

### Prerequisites

* Linux or Windows 10 Subsystem for Linux (WSL).
* gcc ARM toolchain from [Arm Developer GNU-A Downloads](https://developer.arm.com/open-source/gnu-toolchain/gnu-a/downloads) on the path. Successfully tested with:
  * gcc 8.2-2019.01 [32-bit](https://developer.arm.com/-/media/Files/downloads/gnu-a/8.2-2019.01/gcc-arm-8.2-2019.01-x86_64-arm-eabi.tar.xz)/[64-bit](https://developer.arm.com/-/media/Files/downloads/gnu-a/8.2-2019.01/gcc-arm-8.2-2019.01-x86_64-aarch64-elf.tar.xz).
  * gcc 8.3-2019.03 [32-bit](https://developer.arm.com/-/media/Files/downloads/gnu-a/8.3-2019.03/binrel/gcc-arm-8.3-2019.03-x86_64-arm-eabi.tar.xz)/[64-bit](https://developer.arm.com/-/media/Files/downloads/gnu-a/8.3-2019.03/binrel/gcc-arm-8.3-2019.03-x86_64-aarch64-elf.tar.xz).
  * gcc 9.2-2019.12 [32-bit](https://developer.arm.com/-/media/Files/downloads/gnu-a/9.2-2019.12/binrel/gcc-arm-9.2-2019.12-x86_64-arm-none-eabi.tar.xz)/[64-bit](https://developer.arm.com/-/media/Files/downloads/gnu-a/9.2-2019.12/binrel/gcc-arm-9.2-2019.12-x86_64-aarch64-none-elf.tar.xz).

### Building the Libraries

```bash
git clone --recursive https://github.com/smuehlst/circle-stdlib.git
cd circle-stdlib
./configure
make
```

The `configure` script has the following options:

```bash
$ ./configure -h
usage: configure [ <option> ... ]
Configure Circle with newlib standard C library and mbed TLS library.

Options:
  -d, --debug                    build with debug information, without optimizer
  -h, --help                     show usage message
  -n, --no-cpp                   do not support C++ standard library
  --opt-tls                      build with mbed TLS support
  -p <string>, --prefix <string> prefix of the toolchain commands (default: arm-none-eabi-)
  --qemu                         build for running under QEMU in semihosting mode
  -r <number>, --raspberrypi <number>
                                 Circle Raspberry Pi model number (1, 2, 3, default: 1)
  --softfp                       use float ABI setting "softfp" instead of "hard"
  -s <path>, --stddefpath <path>
                                 path where stddef.h header is located (only necessary
                                 if  script cannot determine it automatically)
```

To clean the project directory, the following commands can be used:

```bash
make clean
make mrproper   # removes the configuration too
```

### Building the Samples

```bash
make build-samples
```

## Current Release [v13.0](https://github.com/smuehlst/circle-stdlib/releases/tag/v13.0)

* Synced with [Circle Step 41](https://github.com/rsta2/circle/releases/tag/Step41).
* Updated mbedtls to [release 2.16.4](https://github.com/ARMmbed/mbedtls/releases/tag/mbedtls-2.16.4).
* New [configure](configure) option `--qemu` to build with support for QEMU semihosting mode.
* Added [GitHub action](https://github.com/smuehlst/circle-stdlib/actions) that builds
  with the supported compilers in 32-bit and 64-bit mode and runs a smoke test under QEMU.
* Minor changes to circle-stdlib and mbedtls samples so they terminate under QEMU.

Thanks to Rene Stange for making it possible to run Circle programs under QEMU in
a fully automated manner.

## Previous Releases

### [v12.0](https://github.com/smuehlst/circle-stdlib/releases/tag/v12.0)

* Updated circle-newlib from upstream to fix a compilation error in the C++ sample when using gcc 8.3-2019.03.

### [v11.0](https://github.com/smuehlst/circle-stdlib/releases/tag/v11.0)

* Synced with [Circle Step 40](https://github.com/rsta2/circle/releases/tag/Step40).
* Raspberry Pi 4 support.

### [v10.0](https://github.com/smuehlst/circle-stdlib/releases/tag/v10.0)

* Synced with [Circle Step 39.2](https://github.com/rsta2/circle/releases/tag/Step39.2).

### [v9.0](https://github.com/smuehlst/circle-stdlib/releases/tag/v9.0)

* Synced with [Circle Step 39.1](https://github.com/rsta2/circle/releases/tag/Step39.1).
* AArch64 support.
* Removed deprecated build script `build.bash` (use `configure` and `make` instead).

### [v8.0](https://github.com/smuehlst/circle-stdlib/releases/tag/v8.0)

* Synced with [Circle Step 39](https://github.com/rsta2/circle/releases/tag/Step39).
* [mbed TLS](libs/mbedtls) support updated to release 2.16.0.

### [v7.0](https://github.com/smuehlst/circle-stdlib/releases/tag/v7.0)

* Synced with [Circle Step 37](https://github.com/rsta2/circle/releases/tag/Step37).
* [mbed TLS](libs/mbedtls) support updated to release 2.14.1.
* Circle is now included from its default repository. To sync an existing clone of the circle-stdlib repository, enter the following commands:

```bash
git submodule sync libs/circle
git submodule update --init --remote libs/circle
```

### [v6.0](https://github.com/smuehlst/circle-stdlib/releases/tag/v6.0)

* Synced with [Circle Step 36](https://github.com/rsta2/circle/releases/tag/Step36).

### [v5.0](https://github.com/smuehlst/circle-stdlib/releases/tag/v5.0)

* Synced with [Circle Step 35.1](https://github.com/rsta2/circle/releases/tag/Step35.1).
* Added support for <dirent.h> functions.
* Added support for time()-related functions.
* [mbed TLS](libs/mbedtls) support implemented by Rene Stange.
* Added `configure` script and `Makefile` to replace `build.bash`. build.bash is
  deprecated and will be removed in a future release.

### [v4.0](https://github.com/smuehlst/circle-stdlib/tree/v4.0)

* Synced with [Circle Step 34](https://github.com/rsta2/circle/releases/tag/Step34).
* Added CStdlibApp, CStdlibAppScreen, CStdlibAppStdio and CStdlibAppNetwork for
easier application creation (thanks to Rene Stange).

### [v3.0](https://github.com/smuehlst/circle-stdlib/tree/V3.0)

* Synced with [Circle Step 33](https://github.com/rsta2/circle/releases/tag/Step33).
* Implemented stdin/stdout/stderr based on Circle's CConsole class.
* A build of circle-stdlib with ARM gcc toolchains that include Newlib out-of-the-box now provides
support for C and C++ standard libraries. This is due to the fact that the Newlib provided by the toolchain
is replaced by circle-stdlib's Newlib build, and the toolchain's standard C++ library works with the
replaced Newlib.

### [v2.0](https://github.com/smuehlst/circle-stdlib/tree/v2.0)

This release implements Newlib's open(), close(), read() and write()
system calls bases on Circle's I/O functions. This enables stdio functionality.
A small [test program](samples/03-stdio-fatfs) demonstrates the use of
stdio file system functions with Circle.

### [v1.0](https://github.com/smuehlst/circle-stdlib/tree/v1.0)

Initial build of Newlib with Circle, without any systems calls being implemented.

## License

This project is licensed under the GNU GENERAL PUBLIC LICENSE
Version 3 - see the [LICENSE](LICENSE) file for details

## Acknowledgements

* Rene Stange for [Circle](https://github.com/rsta2/circle).
* The Newlib team for [Newlib](https://sourceware.org/newlib/).
* The mbed TLS team for [mbed TLS](https://tls.mbed.org/).
