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
- You should have 3 prebuilt bins: 1. u-boot.img, u-boot-spl.bin, MLO (MLO and u-boot.img are almost constant, and won't get changed - extra-> "for board", burn in SD.)
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
