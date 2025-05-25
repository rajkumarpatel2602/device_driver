## Module install on rootfs(built with busybox)

module.builtin is a list of statically linked modules or intree modules
module.dep is a list of dynamically linked or out of tree modules along with its dependency list. (can be added using modprobe. insmode is also used to load module but not smart as modprobe, as it doesn't read modules.dep file. so always use modprobe.)

module.dep
![image](https://github.com/user-attachments/assets/fab598b7-4d64-4896-a309-412ee6b8d87b)
![image](https://github.com/user-attachments/assets/6018539c-7593-4e29-bb1a-f8d43e0b1e3c)

![image](https://github.com/user-attachments/assets/fbafc97a-2a3b-4d27-8dc7-344229af768f)


