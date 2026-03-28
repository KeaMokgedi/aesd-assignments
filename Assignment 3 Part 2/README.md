# AESD Assignment 3: Kernel Build & Process Management

## Author
* **Name**: Moemedi Keabetswe Mokgedi
* **GitHub Username**: KeaMokgedi

## Project Description
This repository contains the implementation for Assignment 3, which focuses on low-level Linux systems programming and embedded systems integration.

### Part 1: System Calls
Implemented a custom process management utility in C that replaces the standard `system()` function.
* **`do_system`**: Executes commands using the standard library.
* **`do_exec`**: Manually creates a child process using `fork()`, executes commands via `execv()`, and synchronizes using `waitpid()`.
* **`do_exec_redirect`**: Extends the manual execution to redirect standard output to a specified file using `dup2()`.

### Part 2: Manual Linux Build
Automated the creation of a custom Linux system for an ARM64 target architecture.
* **Kernel**: Configured and compiled Linux Kernel v5.1.10.
* **Root Filesystem**: Built a minimal rootfs using BusyBox v1.33.1.
* **Library Integration**: Manually resolved and integrated dynamic linker and shared C libraries from the ARM toolchain.
* **Initramfs**: Packaged the rootfs into a compressed cpio archive for booting in QEMU.

## Repository Structure
* **`examples/systemcalls/systemcalls.c`**: Logic for process management.
* **`finder-app/manual-linux.sh`**: The master automation script for the system build.
* **`finder-app/finder.sh` & `writer.sh`**: Utility scripts updated with `#!/bin/sh` for BusyBox compatibility.
* **`finder-app/Makefile`**: Cross-compiler compatible build file for the writer utility.

## Build and Execution

### Building the System
To trigger the automated build of the kernel and root filesystem, run:
```bash
cd finder-app
./manual-linux.sh /tmp/aeld
