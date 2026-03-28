# AESD Assignment 3 Part 1: System Calls and Process Management

## Author
* **Name**: Moemedi Keabetswe Mokgedi
* **GitHub Username**: KeaMokgedi

## Project Description
This project focuses on implementing low-level process management in C using Linux system calls. The core objective was to replace the standard `system()` function with a more controlled execution flow using `fork()`, `execv()`, and `waitpid()`.

### Implemented Functions in `systemcalls.c`:
1. **`do_system`**: Executes a command using the standard system library call.
2. **`do_exec`**: Creates a child process to execute a specific command path and waits for completion.
3. **`do_exec_redirect`**: Executes a command while redirecting the standard output (`stdout`) to a specified file using `dup2()`.



## Repository Structure
* **`examples/systemcalls/`**: Contains the C implementation for process control.
* **`finder-app/`**: Contains the updated `finder-test.sh` script with compilation steps removed.
* **`conf/`**: Contains `username.txt` for identification.

## How to Run Tests
To verify the implementation within the Linux VM, run the following command from the root directory:

```bash
./unit-test.sh
