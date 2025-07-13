# Linux Character Device Driver Example

## Table of Contents
1. [Introduction](#introduction)
2. [Prerequisites](#prerequisites)
3. [Project Structure](#project-structure)
4. [Building Instructions](#building-instructions)

## Introduction
This project demonstrates a Linux character device driver implementation using the modern method. The driver creates a character device file and handles basic file operations (open, read, write, close).

### Key Features
- Character device registration usign modern API
- File operation implementation
- Device file create in /dev
- Read/write operations handling
- Proper error handling and cleanup

## Prerequisites

### System Requirements
- Linux Operating System (Ubuntu/Debian recommended)
- Kernel version: 5.x or later
- Root access for module loading/unloading

### Required Packages
```bash
# Install essential build tools
sudo apt-get update
sudo apt-get install build-essential
sudo apt-get install linux-headers-$(uname -r)
```

## Project Structure
/  
├── 📑 [chardev.c](/chardev.c)  
└── 📑 [Makefile](/Makefile)  


## Building Instructions

```text
Step 1: Build Module
$ make

Step 2: Load Module
$ sudo insmod chardev.ko

Step 3: Verify Module Loading
$ lsmod | grep chardev
$ dmesg | tail

Step 4: Check Device File Creation
$ ls -l /dev/chardev_char

Step 5: Test char device operation using device file
$ cat /dev/chardev_char
$ dmesg | tail

Step 6: Unload Module
$ sudo rmmod chardev
```
