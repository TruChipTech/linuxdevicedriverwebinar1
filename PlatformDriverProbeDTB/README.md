# Linux Platform Driver Example for Raspberry Pi

## Table of Contents
1. [Introduction](#introduction)
2. [Prerequisites](#prerequisites)
3. [Project Structure](#project-structure)
4. [Building Instructions](#building-instructions)

## Introduction
This project demonstrates a Linux Platform Driver implementation for Raspberry Pi using Device Tree Overlay. The driver implements platform device registration and handling using modern Linux kernel APIs.

### Key Features
- Platform driver registration using modern API
- Device Tree Overlay support
- Raspberry Pi compatibility
- Proper probe and remove handling
- Clean driver initialization and cleanup

## Prerequisites

### System Requirements
- Raspberry Pi board (BCM2835 compatible)
- Raspberry Pi OS (Debian-based)
- Kernel version: 5.x or later
- Root access for module loading/unloading

### Required Packages
```bash
# Install essential build tools
sudo apt-get update
sudo apt-get install build-essential
sudo apt-get install raspberrypi-kernel-headers
sudo apt-get install device-tree-compiler
```

## Project Structure
/  
├── 📑 [platformdev.c](/platformdev.c)
├── 📑 [platformdev.dts](/platformdev.dts)
└── 📑 [Makefile](/Makefile)  


## Building Instructions

```text
Step 1: Build Module
$ make

Step 2: Load Module
$ sudo insmod platformdev.ko

Step 3: Verify Module Loading
$ lsmod | grep platformdev
$ dmesg | tail

Step 4: Load overlay file
$ sudo dtoverlay platformdev.dtbo

Step 5: Verify Tree Loading
# Check if overlay is loaded
$ dtoverlay -l

# View device tree status
$ dtc -I fs /proc/device-tree > dt.dts
$ grep -r "platformdev" dt.dts

Step 6: Verify if probe function is executed
# Verify probe function execution
$ dmesg | grep "platformdev_probe"

Step 7: Unload Module
$ sudo rmmod platformdev
```
