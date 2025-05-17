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
- 
