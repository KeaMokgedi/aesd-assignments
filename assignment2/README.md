# AESD Assignment 2: Writer Utility

## Description
A C-based system utility designed to write a specific string to a file. This project demonstrates proficiency in low-level file I/O, system logging (`syslog`), and cross-platform build automation using Makefiles.

## Features
* [cite_start]**Automated Build System**: A Makefile that supports both native x86/64 and ARM aarch64 cross-compilation[cite: 3].
* [cite_start]**System Logging**: Integrated with the `LOG_USER` facility to record debug information and error states[cite: 1].
* [cite_start]**Robust Error Handling**: Provides detailed error reporting using `stderr` and `syslog` with `errno` descriptions[cite: 1].

## Getting Started

### Prerequisites
* **Development Environment**: Ubuntu Linux VM.
* **Compiler**: `gcc` for native builds and `aarch64-linux-gnu-gcc` for cross-compilation.
* **Tools**: `make` and `file` utility.

### Building the Project
Navigate to the `finder-app` directory:

1. **Native Build**:
   ```bash
   make clean
   make
