PWD   := $(shell pwd)
obj-m += chardev.o


all:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD)
clean:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean

