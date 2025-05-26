## Module install on rootfs(built with busybox)

module.builtin is a list of statically linked modules or intree modules
module.dep is a list of dynamically linked or out of tree modules along with its dependency list. (can be added using modprobe. insmode is also used to load module but not smart as modprobe, as it doesn't read modules.dep file. so always use modprobe.)

module.dep
![image](https://github.com/user-attachments/assets/fab598b7-4d64-4896-a309-412ee6b8d87b)
![image](https://github.com/user-attachments/assets/6018539c-7593-4e29-bb1a-f8d43e0b1e3c)

![image](https://github.com/user-attachments/assets/fbafc97a-2a3b-4d27-8dc7-344229af768f)

## Steps to load all images.
- Download kernel from beaglebone github repo. and also download arm cross compiler toolchain.
- build defconfig. build with "$make ARCH=arm CROSS_COMPILE=~/arm-toolchain/arm- defconfig"
- menuconfig if you want to exclude modueles or unnecessary board supported peripherals "$make ARCH=arm CROSS_COMPILE=~/arm-toolchain/arm- menuconfig"
- build with "$make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- uImage dtbs RAMDISK_LOCATION -j4" (uboot header + zImage = uImage)
- ~/arch/arm/boot/uImage, ~/arch/arm/boot/detbs/arm-335x-boneblack.dtb (keep in tftp or somewhere else.)
- You should have 3 prebuilt bins: 1. u-boot.img, u-boot-spl.bin, MLO (MLO and u-boot.img are almost constant, and won't get changed - extra-> "for board", burn in SD. also keep uenv.txt to tell u-boot to mount rootfs, and load uImage from tftp server.)
- rootfs(how to generate, written below) will be used via NFS protocol, and called as nfs mounting technique.
- ![image](https://github.com/user-attachments/assets/975804f3-607e-435b-8a3b-145929cbc7c7)
- ![image](https://github.com/user-attachments/assets/9867e1a2-3aa6-477d-bb52-68cf5d1b9d0e)


- build out of tree mdoudes by "$make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- modules -j4"
- Now to install on rootfs, build rootfs using busybox

Build rootfs using busybox (busybox image contains all linux commands and tools and infact, all commands inside build is symlinked to ./bin/busybox. when complete build folder contains 1.4MB size, 1.3MB is of itself busybox.)
- Download busybox
- generate defconfig. "$make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- defconfig"
- change default settings if you want make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- menuconfig
- Install using this command "$make ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- CONFIG_PREFIX=/media/Root(path to ROOT) install

Now install loadable modules on this rootfs.
- "$make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- INSTALL_MOD_PATH=<path_to_rfs> modules_install"

- At last, placements are as below.
![image](https://github.com/user-attachments/assets/1a11a602-090c-4237-b53c-b5ef44b2846a)

- cp uEnv-nfs.txt /media/username/boot/uenv.txt
- ![image](https://github.com/user-attachments/assets/b11e17dd-8e79-4b53-a766-f50c55e3786a)
- ![image](https://github.com/user-attachments/assets/cdfd73e8-3cf8-4cf8-a363-7056dbb9e872)

TFTP booting needs, dtb and uImage in /var/lib/tftp/* , as we're booting from tftp.
![image](https://github.com/user-attachments/assets/f7b31f55-46c6-42da-bf7e-e0a5ced0e820)
copy rootfs
![image](https://github.com/user-attachments/assets/86bae707-d8f3-4379-ab62-fa8c27adc2c2)
![image](https://github.com/user-attachments/assets/a24907ca-2e5f-4ff9-ba05-a9614f5c0574)

host pc needs to give nfs client registration ($ vim /etc/exports)
![image](https://github.com/user-attachments/assets/6ae648f5-e847-4feb-afd6-e207e3213c28)
![image](https://github.com/user-attachments/assets/59893344-440b-42fe-a510-5aa2f2d67eb9)
nfs configuration
![image](https://github.com/user-attachments/assets/d38b6c62-42be-4454-86ad-fdf6a7dd629b)
![image](https://github.com/user-attachments/assets/0b2531f5-5847-40fa-aa2f-6967a69e26a4)

stuck, as ip is not configured on host system.
uart logs.
![image](https://github.com/user-attachments/assets/613eaec7-7ba3-460f-a7c2-1c9c8d788943)
![image](https://github.com/user-attachments/assets/bfac2da2-c48f-4044-bf0d-cacf55b5cd84)
![image](https://github.com/user-attachments/assets/1a6e257d-2349-42cf-a0b4-1d93666a4411)
check on host terminal ifconfig
![image](https://github.com/user-attachments/assets/6c9797e6-c78a-4b0f-924e-ded6be174864)

open /etc/network/interfaces
do static ip assignments
![image](https://github.com/user-attachments/assets/8471007e-49d6-4618-bf90-e46f291b33d0)
restart service to config ethernet ip address
![image](https://github.com/user-attachments/assets/0d961c06-2f42-4f44-bce1-60272f1b2cdd)
![image](https://github.com/user-attachments/assets/60f00dbe-615e-491a-96df-4e2c5fbdce2c)

sudo minicom and boot from sd-card now
![image](https://github.com/user-attachments/assets/6a2bbd9b-6d41-4ba3-b313-30231ac3215c)

mounting succeed, but there are error related to tty devices. workaround is to create dev directory on nfs filesystem
![image](https://github.com/user-attachments/assets/aa3a59c6-d14b-43e0-8aa0-d260ba151ce6)
![image](https://github.com/user-attachments/assets/41a8d56d-9b6f-4514-853f-1b555b8fbc3e)
now, reboot and boot through sd-card again
![image](https://github.com/user-attachments/assets/68910294-4ccb-4f4f-9140-7bcff4670f85)
after enter we get busybox console.

first application linux launches from filesystem is init program(busybox init program), in sbin directory.
from this init, one can bring up different services.

## init process
![image](https://github.com/user-attachments/assets/4138197a-031d-414b-8277-d0969dc5910d)
init userspace application location // last step of kernel initialization. kernel_init of main.c of linux kernel, call for init is made.
it has pid#1 and parent of all linux processes.
![image](https://github.com/user-attachments/assets/703e71e0-0e29-4000-a31a-e9b9b4e14867)
busybox init location
![image](https://github.com/user-attachments/assets/9e6c27bf-cac8-4c3d-b5a7-1f84eaab4b72)
![image](https://github.com/user-attachments/assets/fde208fb-58ce-49c6-97a0-b6b3f69e0959)
we don't have rcS script in file system, and hence this script can't be executed from init process
![image](https://github.com/user-attachments/assets/fdaecdba-6337-45e4-b2d6-9aaa33715cb6)
![image](https://github.com/user-attachments/assets/b62e91e7-bbd0-45b5-93c2-96d52265c998)
