obj-m += platformdev.o

all: module dt
	echo Builded Device Tree Overlay and kernel module

module:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
dt: platformdev.dts
	dtc -@ -I dts -O dtb -o platformdev.dtbo platformdev.dts
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	rm -rf platformdev.dtbo
	
