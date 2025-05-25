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
- build with "$make ARCH=arm CROSS_COMPILE=~/arm-toolchain/arm- uImage dtbs RAMDISK_LOCATION -j4" (uboot header + zImage = uImage)
- ~/arch/arm/boot/uImage, ~/arch/arm/boot/detbs/your_bb_black.dtb
- You should have 3 prebuilt bins: 1. u-boot.img, u-boot-spl.bin, MLO
- build out of tree mdoudes by "$make ARCH=arm CROSS_COMPILE=~/arm-toolchain/arm- modules -j4"
- Now to install on rootfs, build rootfs using busybox

Build rootfs using busybox
- Download busybox
- generate defconfig. "$make ARCH=arm CROSS_COMPILE=~/arm-toolchain/arm- defconfig"
- Menuconfig "$make ARCH=arm CROSS_COMPILE=~/arm-toolchain/arm- menuconfig"
- Install using this command "$make ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- CONFIG_PREFIX=/media/Root(path to ROOT) install

Now install modules on this rootfs.
- "$make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- INSTALL_MOD_PATH=<path_to_rfs> modules_install"
