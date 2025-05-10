## Video
https://www.youtube.com/watch?v=NNol7fRGo2E

## Terms
Arm ARCH SPEC MANUAL

Arm core
- Application -- MMU, Cache
- Microcontroller -- No MMU, No Cache, external memory
- RealTime -- hardly used. avoids deep pipelining, and out of order execution to preserve deterministism.

SoC (Vendors uses these core rigths from arm and uses along with different IP blocks and do packaging and present SoC)

Vendors might take license for AArch and then build their core, and build soc on top of it. like Apple a6

Hardware Platform
- Raspberry Pi from broadcom
- Beaglbon from TI

BIOS
For x86
- MBR // old one
- UEFI
For Arm
- UEFI

Boot loader
- First Stage
- Second Stage
For Arm ROM code
- Grub // heavy
- Uboot // light
- BareBox
For x86
- IO. SYS, NTLDR, BOOTMGR and GRUB.

Device description
x86
- PCI, USB auto discovery
- ACPI shared hardware information to Linux.

For Arm
- Platform devices required board files to be shared in upstream
- Device Tree helped here.

Device tree // part of multiplatform efforts
- OS agnostic
- Source in kernel and boot loder loads kernel and dt code, and kernel uses it for device discovery and driver binding.

Linux kernel
- earlier different soc needed different compilation of kernel
- now single compiled kernel can be used by different soc platforms/family. and thanks to device tree and updates in driver subsystem.
- Single image of arm6/7, arm4/5, arm8

Building root filesystem
Linux distro provides standard rootfs as we see in desktop. there are advanced rootfs as android and tizen. 
but we can actually create our own customized/stripped down rootfs.
- Distro provideed rootfs (provided by)
ubuntu, fedora, debian
- Specialized rootfs (provided by)
Android, tizen
- Customized (created via)
yocto/openEmbedded, buildroot, openWRT

For running os and devices on SoC
- Need uboot or bootloader
- Need compiled image
- Need rootfilesystem
- Need dtb
