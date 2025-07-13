# Linux Kernel Module - Hello World Example

## Table of Contents
1. [Introduction](#introduction)
2. [Prerequisites](#prerequisites)
3. [Project Structure](#project-structure)
4. [Building Instructions](#building-instructions)

## Introduction
This project demonstrates a basic Linux kernel module implementation. The module performs simple initialization and cleanup operations, serving as a foundation for understanding kernel module development.

### Key Features
- Basic kernel module initialization
- Cleanup handling
- Kernel message logging
- Proper module documentation

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
├── 📑 [helloworld.c](/helloworld.c)  
└── 📑 [Makefile](/Makefile)  


## Building Instructions

```text
Step 1: Build Module
$ make

Step 2: Load Module
$ sudo insmod helloworld.ko

Step 3: Verify Module
$ lsmod | grep helloworld
$ dmesg | tail

Step 4: Unload Module
$ sudo rmmod helloworld
```
