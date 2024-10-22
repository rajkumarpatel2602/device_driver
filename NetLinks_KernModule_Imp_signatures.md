::Aum Tat Sat::

Linux kernel installation
- .iso file required.
- version "uname -r"
- bootlin helps for web brwosing the code, else just download, unzip and use it.

Kernel module
- All drivers are kerenel modules (but all kernel modules are not device driveres), and it helps to insert as a piece of addition to existing kernel without recompiling kernel or reboot
- insert module, remove module and list module are used. i.e. insmod, rmmod, lsmod
- kernel headers required to be pre-installed for kernel module `ls /usr/src`
- if headers not present then install using apt update, apt install linux-headers-$(uname -r)
- #define <kernel/module.h> must to have header
- module_init() module_remove() are used to register the functions which are getting called during insmod, rmmod.
- tail -f /var/log/kern.log to check kernel logs
- kernel module has '.ko' extension
- MODULE_AUTHOR, _DESCRIPTION, _LICENSE is what's required?
