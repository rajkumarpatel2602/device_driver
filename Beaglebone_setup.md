## check existing debian
- lsb_release -da

## Booting with sdcard (Steps on my Mac)
- Insert sd card
- Install unarchiver with brew install urar.
- Use belenaEtach(https://etcher.balena.io/#download-etcher) to flash debian image. (https://www.beagleboard.org/distros/am3358-debian-10-3-2020-04-06-4gb-sd-iot)
- Find latest images here : https://www.beagleboard.org/distros
- Insert uSD card on BBB
- Press boot key next opposite to reset button.
- Power down BBB and then power up.
- Board has boot from uSD now.
- Login to bbb. ssh debian@192.168.6.2 (for mac)
- sudo enable-beagle-flasher
- sudo reboot
- Flashing starts here, do nothing.
- Board goes power down and then power on with reset, and voila.

## Enabling internet
On BBB
- cat /etc/resolve.conf
- Add - nameserver 8.8.8.8 and nameserver 8.8.4.4, save and exit
- add interface for gateway #sudo route add default gw 192.168.6.1 usb1
On Host pc
- enable ip forwarding #sysctl -w net.inet.ip.forwarding=1

https://superuser.com/questions/1164627/how-do-i-share-my-macs-internet-connection-with-my-beaglebone-black

I will assume that you have successfully installed the necessary drivers and the beaglebone shows up in your list of network interfaces. Once that is the case, make sure you have properly configured the IP address and netmask. For the default beaglebone connection this looks something like this: networking setup

Once that is done, verify that you can connect to the beaglebone:
```
* mac$ ssh root@192.168.6.2 // for mac
Debian GNU/Linux 7

BeagleBoard.org Debian Image 2015-11-12

Support/FAQ: http://elinux.org/Beagleboard:BeagleBoneBlack_Debian

default username:password is [debian:temppwd]

Last login: Thu Nov 12 19:06:13 2015 from mac.local
root@beaglebone:~#
```
on BBB

```
* $ echo "nameserver 8.8.8.8" > /etc/resolv.conf

debian@BeagleBone:~$ cat /etc/resolv.conf 
# This file is managed by man:systemd-resolved(8). Do not edit.
#
# This is a dynamic resolv.conf file for connecting local clients directly to
# all known uplink DNS servers. This file lists all configured search domains.
#
# Third party programs should typically not access this file directly, but only
# through the symlink at /etc/resolv.conf. To manage man:resolv.conf(5) in a
# different way, replace this symlink by a static file or a different symlink.
#
# See man:systemd-resolved.service(8) for details about the supported modes of
# operation for /etc/resolv.conf.

# No DNS servers known.
nameserver 8.8.8.8
```

You are now ready to setup the nat, to allow the beaglebone to share your network connection. For that, first find the name of the network interface that's associated with your beaglebone:

```
* $ ifconfig | grep -C 3 192.168.7.1 // for mac, 192.168.6.1
en9: flags=8863<UP,BROADCAST,SMART,RUNNING,SIMPLEX,MULTICAST> mtu 1486
    ether 04:a3:16:ad:6c:4d
    inet6 fe80::6a3:16ff:fead:6c4d%en9 prefixlen 64 scopeid 0x4
    inet 192.168.7.1 netmask 0xfffffffc broadcast 192.168.7.3
    nd6 options=1<PERFORMNUD>
    media: autoselect
    status: active
```

Then, activate ip forwarding and set the appropriate firewall rule:
```
* mac$ sudo sysctl net.inet.ip.forwarding=1
net.inet.ip.forwarding: 0 -> 1
```

```
* mac$ echo "nat on en0 from en9:network to any -> (en0)" | sudo pfctl -f - -e
pfctl: Use of -f option, could result in flushing of rules
present in the main ruleset added by the system at startup.
See /etc/pf.conf for further details.

No ALTQ support in kernel
ALTQ related functions disabled
pf enabled
```
Naturally, you need to substitute en9 for the interface name you found in the previous step. Also, if you already have the firewall enabled, you'll want to manually add that to the firewall configuration.

Lastly, we need to set up the default gateway:
```
* mac$ ssh root@192.168.6.2
* beaglebone# route add default gw 192.168.6.1 usb0 // use ip which you get on host machine
beaglebone# ping 8.8.8.8
PING 8.8.8.8 (8.8.8.8) 56(84) bytes of data.
64 bytes from 8.8.8.8: icmp_req=1 ttl=54 time=16.6 ms
64 bytes from 8.8.8.8: icmp_req=2 ttl=54 time=20.5 ms
```

If everything worked, you should see the ping replies come in. If you can't connect to the beaglebone anymore, deactivate the firewall pfctl -d and verify that the rule was correct. If you can connect to the beaglebone, but the ping doesn't succeed, verify the routing table (route on the beaglebone, the nat table on the mac pfctl -s nat, and make sure that you ran the sysctl).

```
debian@BeagleBone:~$ ifconfig
eth0: flags=4099<UP,BROADCAST,MULTICAST>  mtu 1500
        ether 64:8c:bb:f2:cf:5b  txqueuelen 1000  (Ethernet)
        RX packets 0  bytes 0 (0.0 B)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 0  bytes 0 (0.0 B)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

lo: flags=73<UP,LOOPBACK,RUNNING>  mtu 65536
        inet 127.0.0.1  netmask 255.0.0.0
        inet6 ::1  prefixlen 128  scopeid 0x10<host>
        loop  txqueuelen 1000  (Local Loopback)
        RX packets 11180  bytes 906819 (885.5 KiB)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 11180  bytes 906819 (885.5 KiB)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

usb0: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500
        inet 192.168.7.2  netmask 255.255.255.0  broadcast 192.168.7.255
        inet6 fe80::668c:bbff:fef2:cf5e  prefixlen 64  scopeid 0x20<link>
        ether 64:8c:bb:f2:cf:5e  txqueuelen 1000  (Ethernet)
        RX packets 0  bytes 0 (0.0 B)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 0  bytes 0 (0.0 B)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

usb1: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500
        inet 192.168.6.2  netmask 255.255.255.0  broadcast 192.168.6.255
        inet6 fe80::668c:bbff:fef2:cf60  prefixlen 64  scopeid 0x20<link>
        ether 64:8c:bb:f2:cf:60  txqueuelen 1000  (Ethernet)
        RX packets 2932  bytes 298972 (291.9 KiB)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 1789  bytes 312292 (304.9 KiB)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0
```


## Enabling vscode server on debian

https://forum.beagleboard.org/t/replacing-cloud9-ide-with-vs-code-server-bb-code-server/32061
```
sudo apt update
sudo apt upgrade

sudo apt install bb-code-server
sudo reboot

Start VS Code Server on http://192.168.7.2:3000

sudo systemctl enable bb-code-server
sudo systemctl start bb-code-server

autostart
sudo systemctl add-wants multi-user.target bb-code-server
```

# QEMU or cross compilation for kerel
https://www.youtube.com/watch?v=LyWlpuntdU4&list=PLCGpd0Do5-I0yRJDNcT5eKZVvgCdr2NLh&index=1
sudo apt-get install make build-essential libncurses-dev bison flex libssl-dev libelf-dev

arm cross compiler toolchain (https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads)
wget https://developer.arm.com/-/media/Files/downloads/gnu/14.2.rel1/binrel/arm-gnu-toolchain-14.2.rel1-aarch64-arm-none-linux-gnueabihf.tar.xz

busybox -- swiss knife made of tools and commands to use before init process start
<img width="720" alt="image" src="https://github.com/user-attachments/assets/92365d60-bede-4d52-a20c-100aa2d75bb1" />
wget https://busybox.net/downloads/busybox-1.37.0.tar.bz2

kernel image
https://www.kernel.org/
<img width="1035" alt="image" src="https://github.com/user-attachments/assets/ba21b2cc-7a90-44b7-9145-e0a4099dcb2e" />

build command
make ARCH=arm CROSS_COMPILE=/path/to/arm/toolchain/bin/arm-none-linux-aebsomething- defconfig // defconfig building
make ARCH=arm CROSS_COMPILE=/path/to/arm/toolchain/bin/arm-none-linux-aebsomething- -j8 // building

<img width="1512" alt="image" src="https://github.com/user-attachments/assets/a268c5b9-0278-498a-9f01-888e8a75eaf8" />

// I had to download everything on mac system first, and then did ssh to utm
steps are as below
<img width="621" alt="image" src="https://github.com/user-attachments/assets/f75bf27d-e8ea-4715-913e-9fa3e1e2589d" />
<img width="1495" alt="image" src="https://github.com/user-attachments/assets/73c518c1-ab2d-41b5-9e6f-e67660e92011" />
<img width="1428" alt="image" src="https://github.com/user-attachments/assets/f61b96b8-e734-46b7-8aaf-4082ed59562e" />




# Compilation commaands

https://github.com/niekiran/EmbeddedLinuxBBB/blob/master/notes/compilation_commands

*************************cross tool-chain installation and settings for linux host******************

STEP 1 : Download arm cross toolchain for your Host machine

STEP 2 :  export  path of the cross compilation toolchain. 

export PATH=$PATH:/home/kiran/BBB_Workspace/Downloads/gcc-linaro-6.3.1-2017.02-x86_64_arm-linux-gnueabihf/bin


*************************U-boot Compilation ***************************************************


STEP 1: distclean : deletes all the previously compiled/generated object files. 

make CROSS_COMPILE=arm-linux-gnueabihf- distclean

STEP 2 : apply board default configuration for uboot

make CROSS_COMPILE=arm-linux-gnueabihf- am335x_boneblack_defconfig


STEP 3 : run menuconfig, if you want to do any settings other than default configuration . 

make CROSS_COMPILE=arm-linux-gnueabihf-  menuconfig


STEP 4 : compile 

make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -j4  // -j4(4 core machine) will instruct the make tool to spawn 4 threads
make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -j8  // -j8(8 core machine) will instruct the make tool to spawn 8 threads


************************* linux compilation ***************************************************
STEP 1:
 make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- distclean

STEP 2:
 make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- bb.org_defconfig (4.4)
for 4.11 use omap2plus_defconfig

STEP 3:
 make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- menuconfig

STEP 4:
 make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- uImage dtbs LOADADDR=0x80008000 -j4

STEP 5:
 make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -j4 modules

STEP 6:
 make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- INSTALL_MOD_PATH=<path of the RFS> modules_install


************************* Busy box compilation ***************************************************

STEP 1: download busybox 

STEP 2 : Apply default configuration
make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- defconfig

STEP 3 : change default settings if you want 
make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- menuconfig

STEP 4 : generate the busy box binary and minimal file system 
make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- CONFIG_PREFIX=<install_path> install



*********************************build-root compilation ***********************************
1) download the build root package from 

https://buildroot.org/

2) configure the build root 


*******************************Dropbear compilation*************************************

1) Download Dropbear 

2) Configure Dropbear

./configure --host=arm-linux-gnueabihf --disable-zlib --prefix=/home/kiran/BBB_Workspace/dropbear CC=arm-linux-gnueabihf-gcc

3) compile the Dropbear as static 

make PROGRAMS="dropbear dropbearkey dbclient scp" STATIC=1

4) install dropbear generated binaries 
make PROGRAMS="dropbear dropbearkey dbclient scp" install


5) generate RSA and DSS keys 
dropbearkey -t dss -f dropbear_dss_host_key
dropbearkey -t rsa -f dropbear_rsa_host_key

6) run the dropbear 
$dropbear

7) make a SSh connection from pc 
ssh -l root 192.168.7.2

## To install an openssh server on your ubuntu host 
sudo apt-get install openssh-server

## Build root
literally baap of everything. 
creates u-boot.img, zImage, uImage, MLO (spl), rootfs using busybox, downaload and install cross-compiling toolchain. A complete package to get embedded board specific binary genration. 
- make something_defconfig
- make menuconfig
- make -jn and boom.
Everything just gets build in place in output directory. use these image, and transfer to your SD card and enjoy.
