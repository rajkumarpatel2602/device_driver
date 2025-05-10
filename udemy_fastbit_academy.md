## building first kerne module

## makefile for module building

command
![image](https://github.com/user-attachments/assets/5a638971-67af-4d52-ba45-f9a213f378ec)

build for target arch
![image](https://github.com/user-attachments/assets/2f025ef5-4936-4019-bf53-1bfb1852e3f1)
This way built modules can be inserted on target machine
![image](https://github.com/user-attachments/assets/a798acf9-cff2-4877-9996-af681d83a77a)

build for host, or against pre-compiled kernel
![image](https://github.com/user-attachments/assets/1b2f5b8f-948c-4d6f-a8ce-b4bf603348ad)
These way built modules can be inserted in host machine
![image](https://github.com/user-attachments/assets/153aa8c1-888b-4e37-ba63-5f4cd667e0a2)

## Adding in-tree module
![image](https://github.com/user-attachments/assets/d56ec967-bc22-4179-a738-3f1370d083b6)
![image](https://github.com/user-attachments/assets/49e00827-cc8f-48b6-962b-a92b78e8c748)

Steps:
create a folder inside driver/char/. e.g. driver/char/my_c_dev
Add kconfig, describe your kernel module. tristate is config description string. CUSTOM_MOD_NAME is option appear is linux .config.
and name of module is shown as menuconfig option.
![image](https://github.com/user-attachments/assets/36e55324-2dbb-467f-bad2-8c9338d208f7)

Add kconfig to upper level kconfig.
![image](https://github.com/user-attachments/assets/23a27b33-2e95-4ecb-81ea-1663eb19b7b5)

Add Makefile, use "$(CONFIG_CUSTOM_MOD_NAME)" // check config preprended.
![image](https://github.com/user-attachments/assets/7ec45c0c-bd6a-424c-a993-30d22243ea3f)

Add makefile to uper makefile. Linkage of path happens here.
![image](https://github.com/user-attachments/assets/9b6a90ef-3256-46e7-86e2-8aceb71300ac)
kernel build system will come to driver/char, and will read this makefile, and it will go inside given obj-y path and usae that Makefile

comeback to linux top level directory
![image](https://github.com/user-attachments/assets/99107d5e-dd10-4324-beee-a6f0132bfffb)
![image](https://github.com/user-attachments/assets/bc312495-3ba6-4237-8029-fd95e194a7d4)
![image](https://github.com/user-attachments/assets/bf62453c-24e1-4679-82e7-8f6f2346d6cb)
![image](https://github.com/user-attachments/assets/bee8e9b7-d06d-4c95-86c0-4807a0d89dbc)
main menu is fastbit custom entry, and inside that, list of modules
![image](https://github.com/user-attachments/assets/40bee106-bb12-4481-a427-a50329b41e90)
![image](https://github.com/user-attachments/assets/ba9a7627-00dc-41cb-a0c7-91fdda1de4a3)
use M for dynamically loading the module, and * for static linking of module
![image](https://github.com/user-attachments/assets/56268145-648d-4ca7-9db8-d82428f9b2c4)
This selection changes the .config file on saving and exit
![image](https://github.com/user-attachments/assets/7bdd7813-69c7-4033-b97c-3b7f9a1dc7d2)
![image](https://github.com/user-attachments/assets/f3f42955-febd-4ea3-a887-5f2838792766)

To build module, this kconfig will be used
![image](https://github.com/user-attachments/assets/3f3b6de1-9bbb-4dd9-89db-6e39aa816a77)
![image](https://github.com/user-attachments/assets/9f0ad4df-314f-4058-89fd-b0c39e6c9d2d)
command to build loadable modules
![image](https://github.com/user-attachments/assets/a517dd00-fed1-4504-b8a7-51d1d21d93cc)


goto directory and check file main.ko
![image](https://github.com/user-attachments/assets/4905ea4c-df8d-4caf-85eb-e0b2ad074fd7)

see, it's an intree module now.
Very important session:
https://www.udemy.com/course/linux-device-driver-programming-using-beaglebone-black/learn/lecture/21622444?start=45#overview

![image](https://github.com/user-attachments/assets/366ded7c-637a-4028-9d34-a8d17f00af4d)![image](https://github.com/user-attachments/assets/8fde6e27-dc33-4e5b-ad97-d3eb2a355c34)![image](https://github.com/user-attachments/assets/43b861fc-cf9d-4d41-8435-11f34b30a5c4)![image](https://github.com/user-attachments/assets/0c3c1add-d47e-405c-8ad0-8ab495dd8385)

Minor numbers help to differencitate between device file. By major, VFS choses device file, and with minor number, which instance or which device file is used by user, that's recognized by driver. So minor are used for driver to differentiate device instance requests, and major are used by vfs for systemcall or user call forwarding which are initiated by device file.

![image](https://github.com/user-attachments/assets/1808d565-a6b2-4674-9118-06cf9de6f3c9)

![image](https://github.com/user-attachments/assets/05f0657a-f5d7-4406-80c6-8bd86508b01d)

![image](https://github.com/user-attachments/assets/cb09e5c0-4b02-49d7-9fa4-8cd160bba4d9)

Driver need to ask kernel for device number, vfs connectiona nnd file creation.

![image](https://github.com/user-attachments/assets/ea7c5177-8d03-43b1-bec6-0df922dfc509)

important headers

![image](https://github.com/user-attachments/assets/e2c7252e-86c9-456c-afd0-bdbf3bc405db)

eeprom is the name to idenityf device number range.

![image](https://github.com/user-attachments/assets/8332bbc5-e6d6-4576-86e8-7d54fa45261e)

![image](https://github.com/user-attachments/assets/b8148250-1e9e-43f4-8ab0-97b4be354ef4)

![image](https://github.com/user-attachments/assets/e4fa8788-7009-4c4f-a893-484aa5e1291e)

![image](https://github.com/user-attachments/assets/82718baf-2595-4d38-a1b4-4680a9000385)

Important data structures for file oeprations/ device file operations.

Cdev(points to file ops supported), file_ops(mentions supported file ops), file(allocated on opening of a file and stays in kernel memory. Holds process interaction with an open file), inode(stored on disk, and unique per file. Hold's file metadata)

![image](https://github.com/user-attachments/assets/2b6be25e-3b46-40bb-b6f0-2557f724062a)

![image](https://github.com/user-attachments/assets/b7dc3830-8694-489d-9e11-f1f353c90112)

VFS objects are file_ops, cdev, file, inode.

![image](https://github.com/user-attachments/assets/8cc0936f-af36-42c2-8a3d-0a80fccb5426)

When device file is created, vfs functions are called. Vfs do some association using some functions as shown above.

Steps:
when device file is created (udevd does this based on indication from loading driver module via event)
	- A file is created (an inode is created and stored in memory)
	- Inode is initialised with some default values for device number and dummy file operation methods, as shown above.
 
Now wait for open call… story starts there of actual linking of driver methods.

![image](https://github.com/user-attachments/assets/70889418-715b-4b3c-8fd5-2f5d21c90c85)

![image](https://github.com/user-attachments/assets/c562761f-ff4d-4a5d-9d13-7a6f666d66c9)

![image](https://github.com/user-attachments/assets/e712c88b-306e-4ec4-9f12-ace6d10cf8ca)

![image](https://github.com/user-attachments/assets/e9a2b55f-46c2-4977-8611-b9f94f1396cf)

![image](https://github.com/user-attachments/assets/2f2dd9bc-a3d1-4c7d-b582-22802fe84a13)

![image](https://github.com/user-attachments/assets/f8c55138-d6dd-4e04-a0e3-34cfb7de5211)

Complete scenario

![image](https://github.com/user-attachments/assets/16c91427-a807-470b-a010-6b7f868bb5b8)

![image](https://github.com/user-attachments/assets/5e86e8ac-6e82-4bed-a0c8-5c64a285a348)

![image](https://github.com/user-attachments/assets/e7498e93-d9db-497c-84af-18829c771fd0)

![image](https://github.com/user-attachments/assets/1c32c74f-7f1a-4018-ae08-871321211fe9)

![image](https://github.com/user-attachments/assets/af4e877c-620e-4a3a-8973-4989528845b7)

![image](https://github.com/user-attachments/assets/b75acf9f-2755-468e-ae8d-2d5122360710)

![image](https://github.com/user-attachments/assets/5f484fd1-5897-438b-9dfa-1d01f5f618f2)

![image](https://github.com/user-attachments/assets/93d5b2f5-4253-4d1f-9a4f-f535e7ab6d63)

![image](https://github.com/user-attachments/assets/83e3f2a6-5f12-4ae4-9b15-09e5d317e1cd)

![image](https://github.com/user-attachments/assets/a401ef4c-ad6f-475c-aec1-22dbd170e4b1)

![image](https://github.com/user-attachments/assets/80e542f7-60cb-454a-9a0a-40f4e918f70a)

![image](https://github.com/user-attachments/assets/9e1f7e9c-b3b9-40cd-bc51-d48091cf881b)

![image](https://github.com/user-attachments/assets/19425732-f9f9-4c31-81a6-4ad6077c0cf8)

![image](https://github.com/user-attachments/assets/845e4f26-f917-4d2a-b6da-035f4125f724)

![image](https://github.com/user-attachments/assets/64c798f4-df55-436f-8189-adea7c25cd85)

![image](https://github.com/user-attachments/assets/07627862-8d7d-43ef-a0b8-73a40b5aa669)

Export major minor info to udevd by using kernel apis.

![image](https://github.com/user-attachments/assets/c5f47364-9294-4d44-b678-3f515e7f2db6)

![image](https://github.com/user-attachments/assets/d2fb89ef-4845-48bf-99d6-717190e8c392)

![image](https://github.com/user-attachments/assets/ad2dc9c6-d604-4a44-9177-891f774212e7)

![image](https://github.com/user-attachments/assets/ccaa595e-3b77-44e1-ab9a-5d35e82c3751)

![image](https://github.com/user-attachments/assets/d0de487b-c372-42e6-aaf0-6f5814494a4e)

![image](https://github.com/user-attachments/assets/4585a697-a1b3-4ae1-ac17-f066d79c7dfb)

![image](https://github.com/user-attachments/assets/f6b35b6e-1c5e-4e64-9c7d-a4dedb9ee4fd)

![image](https://github.com/user-attachments/assets/d2a1184e-ede3-40c9-a80e-138b542ae022)

![image](https://github.com/user-attachments/assets/5d9b87e3-2f53-4531-8670-794b8322593d)

![image](https://github.com/user-attachments/assets/5ed8c7af-d7aa-47eb-bf21-83aa0eee4433)

![image](https://github.com/user-attachments/assets/a6f5fcc6-521d-4b79-9693-5269f73a02bb)

![image](https://github.com/user-attachments/assets/f87e304a-d2fb-4ae8-82fb-51bb2eb97b38)

CDEV add
Minor numbers help to differencitate between device file. By major, VFS choses device file, and with minor number, which instance or which device file is used by user, that's recognized by driver. So minor are used for driver to differentiate device instance requests, and major are used by vfs for systemcall or user call forwarding which are initiated by device file. 
Driver need to ask kernel for device number, vfs connectiona nnd file creation.
important headers
eeprom is the name to idenityf device number range.
Important data structures for file oeprations/ device file operations.
Cdev(points to file ops supported), file_ops(mentions supported file ops), file(allocated on opening of a file and stays in kernel memory. Holds process interaction with an open file), inode(stored on disk, and unique per file. Hold's file metadata)
VFS objects are file_ops, cdev, file, inode.
When device file is created, vfs functions are called. Vfs do some association using some functions as shown above.
Steps:
when device file is created (udevd does this based on indication from loading driver module via event)
	- A file is created (an inode is created and stored in memory)
	- Inode is initialised with some default values for device number and dummy file operation methods, as shown above.
	- Now wait for open call… story starts there of actual linking of driver methods.
Complete scenario
	OPEN method prototype:
	What to do in open system call of char dev
	Close method // only succeed when f_cnt is zero, and no one is using the file and release method will be called.
	Read method
	Key thing is, if less bytes are read, then doesn't mean call failed.
  Write::
	Lseek::
prototypes
Export major minor info to udevd by using kernel apis.

Error number: errorno is set whenever driver method encounter an error. this can transcend from kernel to user space. ways to pass a message to user.
![image](https://github.com/user-attachments/assets/c5ded905-d165-4a46-accd-e18bc3fce058)

Copy to user:

why to use? because we can't trust user calls. if these calls return non-zero then we need to worry.

![image](https://github.com/user-attachments/assets/6954c340-f91d-42db-8062-4c33e58c942c)

always first arg will be destination.
![image](https://github.com/user-attachments/assets/e9167b50-dc0b-4002-9c46-c8514c3a5e0a)
![image](https://github.com/user-attachments/assets/66754dcc-0390-4404-a72c-bc71bcf96428)

Inode are unique to file. but FILE * struct is always created when fopen gets called.
![image](https://github.com/user-attachments/assets/80cd2f95-dcab-4b46-b6f2-404753f29e3d)

f_pos is kept track for each individual process because, whichever process will call fopen, it will see its unique f_pos.
![image](https://github.com/user-attachments/assets/40da182c-b6ac-44e6-9a0a-6cdf3ca44c6a)

Every read and write will take place from f_pos only.
![image](https://github.com/user-attachments/assets/a1f43655-5c88-4c3b-a209-403ab1dfbd15)

Read:
![image](https://github.com/user-attachments/assets/c7f2018b-fe34-4bb8-ad53-60b34ac7ab5c)
![image](https://github.com/user-attachments/assets/0573734c-fcb8-47c0-9b14-ff076466a18c)
![image](https://github.com/user-attachments/assets/fe931941-0eab-4a14-b7fb-d2cb1d6e0ab1)
![image](https://github.com/user-attachments/assets/5c330f9b-830b-4061-ba55-bf5c1e5b1b5e)
![image](https://github.com/user-attachments/assets/f84f9f1c-9524-4033-87cd-2a68cad83c61)

Write:
only difference is return code. ENOMEM is used if count is adjusted to zero.
![image](https://github.com/user-attachments/assets/013e33a3-ae92-48d4-be56-8d8059ddd95b)
![image](https://github.com/user-attachments/assets/f2f1e495-fa49-4cf8-ad6f-e0e7be3c49fe)
![image](https://github.com/user-attachments/assets/398059cf-fd1f-4934-87f7-759a737077c1)

lseek: meaning can be changed according to device and driver implementation.
![image](https://github.com/user-attachments/assets/c445ae16-b723-4275-9072-91a72603ae70)
![image](https://github.com/user-attachments/assets/d1e3c2db-fc47-4110-83d9-72dc519c8365)

Testing:
![image](https://github.com/user-attachments/assets/50f17b7f-f64f-435c-b4cf-c0c167c2fe68)

cat application retries
![image](https://github.com/user-attachments/assets/8ec0fad8-1ca9-41e1-b55d-0fa81008395b)

Error handling in kernel module init
![image](https://github.com/user-attachments/assets/c6c46a6c-204b-438d-b0de-ecf46dd0b7b7)
Goto is verymuch valid for kernel programming and specially for error handling.

Handling error scenarios
![image](https://github.com/user-attachments/assets/da6a852f-0a3f-4be4-823b-d265a19bc5ab)
![image](https://github.com/user-attachments/assets/538595e0-5703-4871-9948-e64ffb6fbd0f)

MULTIPLE DEVICES using ONE Pseudo Character Driver.
![image](https://github.com/user-attachments/assets/83359706-122a-40c2-88c9-a5ce3df703f4)
![image](https://github.com/user-attachments/assets/c3123fc0-e528-40b2-96d0-dfa6b938e211)

device file names
![image](https://github.com/user-attachments/assets/2cc0c847-cb26-40fa-b4d8-3489e04156c4)

Device specific info
![image](https://github.com/user-attachments/assets/8f775485-2bcd-4d2f-9e8e-4fe46d9bc4b0)
![image](https://github.com/user-attachments/assets/ff51442b-b65a-4871-9c76-51638798c0eb)

![image](https://github.com/user-attachments/assets/d3f8651b-c1ba-48c7-a5fb-b35f59ef2eb0)

Device specific private data: cdev struct is device specific. every device has to get registered with vfs. 4 devices means, 4 cdev structure.
![image](https://github.com/user-attachments/assets/f7954dd0-a6f3-4115-bfde-72f754672120)

Driver specific private data:
![image](https://github.com/user-attachments/assets/0a7349d6-6a49-4885-91f5-51717b6513cd)

Makefile - just name change
![image](https://github.com/user-attachments/assets/79e769e8-85f4-436d-9a2d-c7d3dca7ef1a)

Allocation for chardev region: 4 devices, with base as 0. means major will be dynamically allocated, and point to DYN_MAJOR_NO:0, by changing 0 to 1, 2, 3 one can get other devices. 
![image](https://github.com/user-attachments/assets/e592ab51-ca78-41bb-aa8e-f3b589905762)
![image](https://github.com/user-attachments/assets/102d857e-0095-4264-9e81-3a5ca3d37dcd)

cdev_add() and device_create(), MAJOR() and MINOR() are to be called in loop. However, alloc_chardev_region() and class_create() doesn't required to be called in loop. took out class create before cdev_add()
![image](https://github.com/user-attachments/assets/efd48727-f153-4832-aa6e-78dc573e4d0a)
![image](https://github.com/user-attachments/assets/4de0fcbe-2721-4779-9242-24504282bf07)
![image](https://github.com/user-attachments/assets/39ad4069-f71b-490e-bc1a-78bb4ea3a111)

device_destroy() can be called on invalid dev_t, same for cdev_del()
![image](https://github.com/user-attachments/assets/db033ac2-762a-489f-b181-01e0d15d0d47)
![image](https://github.com/user-attachments/assets/ef54b804-d4fb-4ae7-b583-bb35e311f8dd)
![image](https://github.com/user-attachments/assets/688b0b99-ab47-4f74-a143-ded1118dacbf)
reused in cleanup function.
![image](https://github.com/user-attachments/assets/110e192d-1a7a-47af-98fc-44bf56179b5a)

On each open call, and new kernel file object is created. inode holds unique information related to device.
e.g. i_rdev for dev_t type. one can get minor from this. i_cdev contains per device, cdev related info. from this cdev address from address, private device data structure or container base address can be accessed using container_of() macro.
![image](https://github.com/user-attachments/assets/b802fd24-3364-4dfa-b854-5eb249516d2f)
![image](https://github.com/user-attachments/assets/045db4eb-f205-4886-b8b9-f6d3167c4005)
![image](https://github.com/user-attachments/assets/95deba36-32ee-46bf-9de0-9fc1aa0e5ee1)
![image](https://github.com/user-attachments/assets/5850a1cf-b31b-46d4-ba34-71a297316dd2)
![image](https://github.com/user-attachments/assets/0895e295-9877-4901-9b28-5fbf1eaa1b35)
![image](https://github.com/user-attachments/assets/5e48108c-7477-4427-9d33-3a25826936c7)
![image](https://github.com/user-attachments/assets/399fc73f-82b0-44eb-97c5-af494e7cb289)
vfs doesn't supply inode to read and write method, so we can't get this info by container_of() in these api. need to save this from other methods.
where to use?
use in file object which vfs supplies to other method. there's a private_data field, which can be used.
![image](https://github.com/user-attachments/assets/860a58bb-0ec1-4b0b-9d8e-c40bb9898099)
write method
![image](https://github.com/user-attachments/assets/7e514559-f7b1-4711-907c-3b3b6e3ca4d7)


Premission checking is also need to be implemented here in open()
vfs calls driver's open method, with information of inode and file pointer.
![image](https://github.com/user-attachments/assets/9985e6ae-06bf-4255-9776-f61991e62a6b)
file kernel object structure has f_mode field, which catch user's intention for access while opening file.
![image](https://github.com/user-attachments/assets/35d22b15-3bd3-44dd-a75a-2821cacb78c8)
![image](https://github.com/user-attachments/assets/46f3093c-2e0e-4de8-b6cf-eaf915358b28)
![image](https://github.com/user-attachments/assets/77bb72e2-f73c-47c7-9f1d-2a18821491f7)
![image](https://github.com/user-attachments/assets/44a48ae0-b0e2-4903-9256-43d7968e810b)

Writting on readonly file.
![image](https://github.com/user-attachments/assets/5d7153dc-f1f9-4be8-9115-bc3196b24d70)

Writting to readonly device file : strace comes in handy, as it shows all system call trace.
Strace is used to debug user level application.
![image](https://github.com/user-attachments/assets/7b4de7d5-0815-4a1f-a715-1837c03f9cc3)
![image](https://github.com/user-attachments/assets/4c73a538-b744-4817-94fc-321180b118f2)

successful write on device 2
![image](https://github.com/user-attachments/assets/f1350973-21f1-4d0f-be80-b545eded1938)
![image](https://github.com/user-attachments/assets/7541c18b-4369-4fe1-97c5-ef3517bafe27)

file operation
![image](https://github.com/user-attachments/assets/7e192e01-5c02-4df1-be95-b74c88076397)
![image](https://github.com/user-attachments/assets/8ef44d9a-1a29-4528-8069-d86ffc6714e3)


Platform drivers

![image](https://github.com/user-attachments/assets/a72cadf9-b61b-47c2-a6a9-ecee3b9afc94)
![image](https://github.com/user-attachments/assets/f0e6b53e-2848-4212-9e00-316d3610e76e)
![image](https://github.com/user-attachments/assets/12bfcc1f-845b-4816-8297-b0512ebda66e)
![image](https://github.com/user-attachments/assets/2544f59d-b606-48d4-abbe-d285e0317981)
![image](https://github.com/user-attachments/assets/a5d2fc0b-3b85-428c-84f8-b9aeb6c1c6c9)
![image](https://github.com/user-attachments/assets/4fa5e51b-3d62-42c0-b9de-fea113f82feb)
![image](https://github.com/user-attachments/assets/bcc3b772-b9f6-48d7-9081-eb7e34a6df98)
Linux gives unique name to these non-discoverable or hotpluggable buses, and that name is 'platform bus'
![image](https://github.com/user-attachments/assets/4a90131a-37dd-4750-b1c5-4a217d319a4e)
Linux doesn't distinguish buses as i2c, spi, or l3, l4 interconnect, APB or AHB, like that. it simply says, platform bus.
from hardware perspective devices are may be connected on these different buses. but for linux it's all platfor bus. it's a pseudo bus.
and devices connected on these buses are called platform devices.
![image](https://github.com/user-attachments/assets/a0cc1bce-37e3-4740-b237-a79baa2e6c6f)
There are on-chip peripherals and off-chip peripherals.
Below devices are platform devices, because there are not auto-discoverable by their host bus interface.
![image](https://github.com/user-attachments/assets/ee2ed53c-e4e7-4bea-9255-9fa3ca2d8856)
Platform devices has to be part of "Linux Device Model", so that, "device information" about these devices can be fed to linux kernel at either boot or compile time.
![image](https://github.com/user-attachments/assets/cf2eaec9-69ff-401b-86e4-132fcd26660f)
Which device info to be provided to linux kernel, so that it can do autoload of appropriate driver and do configuration properly
![image](https://github.com/user-attachments/assets/4cb46fa6-5e3a-4c95-83e9-ebeb23994000)

How to register platform device?
![image](https://github.com/user-attachments/assets/5832e554-ad92-4592-a8a7-c55fae55b76c)

3 paths
![image](https://github.com/user-attachments/assets/4bd8b4d1-9671-48a6-9716-90fccd8fee59)

Board file approach
![image](https://github.com/user-attachments/assets/23231c42-8c0d-4c03-867f-80106e0b6823)

Device tree
![image](https://github.com/user-attachments/assets/86f5e5be-b287-4c21-b4da-8da84c282ee7)

Where board files are placed?
per device in arch folder all board files are preesnt. These are part of kernel source, which is a bad bad idea. supported before 3.6 kernel.
![image](https://github.com/user-attachments/assets/55680091-2c4c-4aa1-972f-b1f4393cba67)
![image](https://github.com/user-attachments/assets/ccce2299-b931-4502-b3bd-27692291c2e2)

Whenever linux kernel detects a board, it jumps to devxxxx_init() function in its board file. It includes platform devices configurations, resources.
![image](https://github.com/user-attachments/assets/84a6c7cc-e560-4ced-a6cb-ea9e58ae01f3)

newer kernel has removed platform or board specific board files, rather it has just kept a generic board file.
![image](https://github.com/user-attachments/assets/ebaea0b3-b093-45c5-af5c-34ed75a726c9)

this includes generic info for various board, but exact board specific details are instantiated from device tree. you won't find no platform device structure.
![image](https://github.com/user-attachments/assets/5521ae1b-6652-4914-ad6d-fb8e4a10bba1)

Example platform driver
![image](https://github.com/user-attachments/assets/e374aeca-994f-4825-a69b-39466e8f857a)
![image](https://github.com/user-attachments/assets/93f03654-95e0-4de3-b823-e48a3595687e)

TI gives drivers for platform devices/driver for peripherals.
![image](https://github.com/user-attachments/assets/5f33e955-3a0e-4bf0-a579-d16cd724feb1)

Red circle is i2c (peripheral) devices / i2c client devices. Yellow circle is i2c bus controller / i2c host controller / i2c cotroller.
![image](https://github.com/user-attachments/assets/ccf6c80c-4080-4e37-b46e-3eb418ab8270)

I am writting i2c device driver - writing driver for i2c device which is connected to i2c controller over i2c bus. i2c controller driver is most probably given by vendor itself. these are controller driver. so controller drivers are mostly available, but device drivers are to be written.

![image](https://github.com/user-attachments/assets/fdbd2789-1420-4299-909a-36278115ead8)

Registering platform device and platform driver
Platform driver
![image](https://github.com/user-attachments/assets/38910ead-c350-4a55-a4f8-ba70f809b627)
![image](https://github.com/user-attachments/assets/57ed26b3-c1cf-4d3a-8a98-a1d3cf012a5e)

Platform device. call this function to register from board file or device setup file.
![image](https://github.com/user-attachments/assets/ad28bbc8-25ab-4c04-a6a3-93c9762e5c03)
![image](https://github.com/user-attachments/assets/48fc42c0-34fa-4ae6-b544-b108107d49e6)

How correct driver is autoloaded whenever one add a new platform device? kernel use some matching here. we are just supposed to take care of registering right way.
![image](https://github.com/user-attachments/assets/c97cd61b-6860-42a0-b361-93732b3cb88e)

Matching mechanism. Every bus type has its match function.
![image](https://github.com/user-attachments/assets/495587f6-5e90-4e38-9053-0f0dbea26c79)

Name based matching mechanism
![image](https://github.com/user-attachments/assets/1e5c2d94-431b-416b-a1ec-859d7a7819ce)

when match detected, bus driver management code determines driver for newly added device, and that driver's probe function is called with this device as an arg.
![image](https://github.com/user-attachments/assets/e0a37d23-e370-469d-a4c8-c007a60acbf3)
![image](https://github.com/user-attachments/assets/6513e0f5-33eb-4e50-8f85-d1abc39e0433)
![image](https://github.com/user-attachments/assets/2ef63e79-6afe-4917-93fe-2d532dd5aff0)

Probe function is very important // binding of device to kernel framework
![image](https://github.com/user-attachments/assets/b01895c8-d83b-4dfd-b026-fd28cfa9878d)

Remove function // unbinding of device to kernel framework
![image](https://github.com/user-attachments/assets/16631ee7-b976-438e-b71d-a65c05efcc05)

Probe an Remove are mandatory, where as other can be implemented as per need.
![image](https://github.com/user-attachments/assets/9ceaf742-eee4-4276-b8d0-74346b6897ba)
![image](https://github.com/user-attachments/assets/82cb9628-ad6c-400b-a765-4b2b1bf0c611)

Exercise: implement psuedo char driver as platform driver
![image](https://github.com/user-attachments/assets/d39d0370-acd6-48cc-abad-c5c889c6613f)

2 files. 1 module for platform driver, 2nd module file for platform device setup
![image](https://github.com/user-attachments/assets/f35ac4d0-3c47-4fb7-a5b8-1f3947772f7b)

2 more functions are required for platform driver
driver		![image](https://github.com/user-attachments/assets/439b809e-924f-4ffc-936a-5af4875d796b)
device setup	![image](https://github.com/user-attachments/assets/1c234006-f9c7-4b3a-afdb-1056d3905820)

Device setup module
![image](https://github.com/user-attachments/assets/55374234-f342-4a3d-bd46-261128f1724e)

Skeleton
![image](https://github.com/user-attachments/assets/1988d607-a60d-4ec7-af80-cb8754d0fbab)
![image](https://github.com/user-attachments/assets/27d8c3aa-5ce7-4ad6-a7ea-eb9d62c9f09b)

Earlier we passed device private data as different structure. this will be now called as device platform data. during registration, we should register data as well.
![image](https://github.com/user-attachments/assets/2f34459f-db66-4adb-b92a-dd0dbe995632)

platform.h to contain platform data
![image](https://github.com/user-attachments/assets/ab8aa708-9f8a-4b7d-b779-8f5042db13d9)
![image](https://github.com/user-attachments/assets/45e331db-9aa3-4784-a43c-289deb18f792)

where to store? platform_device -> dev structure -> platform_data
![image](https://github.com/user-attachments/assets/0297d9ea-afdb-4b7b-9c07-11d9bddd40cb)
![image](https://github.com/user-attachments/assets/8497d8c0-85ed-4751-a747-1d3f398672be)
![image](https://github.com/user-attachments/assets/0f1d3ffb-6880-4a47-9010-8d9ffa30bf7a)

One more item to be initialized is release function inside dev structure.
![image](https://github.com/user-attachments/assets/bf7a420d-46a6-441b-8023-106346ada543)
![image](https://github.com/user-attachments/assets/333309f9-864f-4317-a201-7beb817b9a7d)

we are using more global data, just in case if it's dynamically allocated, we need a point when it can be freed at the point of unbinding/relase.
![image](https://github.com/user-attachments/assets/f46631dc-373b-4dd5-b93d-d3cd759a2d46)
![image](https://github.com/user-attachments/assets/b68a1b67-fc1e-4076-a455-b3afcbbeeaaf)

Platformd devices are added and removed
![image](https://github.com/user-attachments/assets/f64d9977-e2e4-44ec-8120-fdadcafcfead)

Platform Driver code

Same as pseudo char driver. with probe and remove method difference. moreover, platform driver registration has to happen.
Also platform driver members are to be initialized. which are important??? check below.
![image](https://github.com/user-attachments/assets/1e8476a1-742d-4542-b835-3795e7818d10)

this name has to be same as suplied in platfrom device
![image](https://github.com/user-attachments/assets/9b3833af-95cc-4ed7-8609-8e2b467948ec)
![image](https://github.com/user-attachments/assets/3d198a66-6fe9-4ce4-b6ec-a32830b42ced)
![image](https://github.com/user-attachments/assets/60e5815b-ff3d-4a36-9085-faf6f083f342)

Number of times platform_device_register() gets called, that many time, probe has to be called.

Driver unloading - Remove function is called first before cleanup, to give a chance to unbind any device before unloading driver.
![image](https://github.com/user-attachments/assets/bdf66c81-9976-4c2e-a6c6-5c8ccaab9b2e)

CLI
![image](https://github.com/user-attachments/assets/72521404-779a-4e7f-a808-d9918bdab359)
![image](https://github.com/user-attachments/assets/c43c3eaf-f5be-41da-a58f-8b2225a729b8)

Probe function
What it should do, when platform device match is found with our driver?
![image](https://github.com/user-attachments/assets/f88e5d0a-ef2c-4b0c-9f1c-f8b160d32b4a)
Get device platform data
![image](https://github.com/user-attachments/assets/0817fd3e-8cdd-4e32-8f9c-0c6ede045bac)
![image](https://github.com/user-attachments/assets/6d911799-f194-4b6b-b473-19995dc0d09d)

Kmalloc/Kzalloc and Kfree
![image](https://github.com/user-attachments/assets/325d9bd4-c58e-44e1-bcb3-10933bdfe595)
![image](https://github.com/user-attachments/assets/7cfd965a-51d4-40d4-a7d3-3be603dd74ab)
![image](https://github.com/user-attachments/assets/4b048953-f612-43e1-a19b-d6ca99756fde)
![image](https://github.com/user-attachments/assets/58891cf0-1b5c-49b4-a76b-032d0443f797)
GFP KERNEL(put caller to sleep if no memory available) and GFP ATOMIC(interrupt handler)
![image](https://github.com/user-attachments/assets/fd05e7da-7a2a-48aa-be93-165ca0940314)
![image](https://github.com/user-attachments/assets/b941fae3-7af3-4b01-95a1-25cf5f48a8ac)
![image](https://github.com/user-attachments/assets/522d1455-f9cf-40cd-9c06-76f94e203900)
![image](https://github.com/user-attachments/assets/8c65fd98-891b-4773-94e0-0ab43ac3e324)
Kzalloc zeros all the allocation
![image](https://github.com/user-attachments/assets/d9859871-3776-4c83-940c-1bc0c1e6abb4)
Kzfree
![image](https://github.com/user-attachments/assets/68956a32-ef8a-4990-9af1-cc9658485c8e)
Krealloc
![image](https://github.com/user-attachments/assets/2ff7d6da-04ac-4fe4-8683-8bd9cffd9682)

![image](https://github.com/user-attachments/assets/166b3e6c-cbe3-42a5-a1be-e93fa7b29702)
![image](https://github.com/user-attachments/assets/e586c743-ed1e-4488-be29-bb9735fd07a1)
![image](https://github.com/user-attachments/assets/d20d46a6-b0f0-40d1-85db-1406efd8a8ee)
![image](https://github.com/user-attachments/assets/f8f38eec-1aa7-4004-bee2-5f46593c844b)
![image](https://github.com/user-attachments/assets/46bde85a-5a5d-4b67-ba49-94cf7b24b624)


Remove function
![image](https://github.com/user-attachments/assets/1761f93f-0809-461e-a596-58567974808c)
![image](https://github.com/user-attachments/assets/73e4ee40-7d5d-4c70-8373-9c0f2d407b72)
inside probe
![image](https://github.com/user-attachments/assets/4c95fa4a-b1d5-461f-96ab-d3db355a8a54)
![image](https://github.com/user-attachments/assets/bc2b5a20-3206-480e-9340-b231f39c3609)
![image](https://github.com/user-attachments/assets/816e8d6f-c833-49d2-bdc0-7b44c8a30f19)
![image](https://github.com/user-attachments/assets/5b25c3ec-446b-4dc8-9094-2aa24eee062c)
![image](https://github.com/user-attachments/assets/d0aa3eb3-9674-4324-95f5-8ef262afe478)
![image](https://github.com/user-attachments/assets/307e2edc-d6d3-4cbf-96ba-d7566924cca9)
![image](https://github.com/user-attachments/assets/e8323bc1-ddfe-4b7c-bf30-e3e4325a2c15)
goto just gest removed as it's automatically freed.
![image](https://github.com/user-attachments/assets/7fe289fe-a2ed-4608-94f7-ea6cb9cdff18)


insmode pcd_device_setup.ko for device load
insmode pcd_platform_driver.ko for driver load , probe gets called here, as match gets found.
![image](https://github.com/user-attachments/assets/018581fd-1a2d-4442-ae98-a298d04a41e7)
![image](https://github.com/user-attachments/assets/76058309-7f56-446e-8773-bde576f0cb45)
![image](https://github.com/user-attachments/assets/c60188f3-fa6d-4d84-b9a8-461caa221260)
![image](https://github.com/user-attachments/assets/5969e5af-88e3-4348-8fc1-5b175afb9926)
driver is still in use
![image](https://github.com/user-attachments/assets/e4753c0b-6f7a-4753-8b86-7276c08614cc)
![image](https://github.com/user-attachments/assets/a3b892c6-d660-43f2-a173-e727e2027b9f)
if driver unloading is done first, then it will remove related devices as well.
however, release function will get called on removing setup device module.
![image](https://github.com/user-attachments/assets/1c93b2a2-deb9-4671-bb93-f5e16f18b834)


Resource managed api
![image](https://github.com/user-attachments/assets/9b174604-67b7-49a8-84c3-d35ee370d445)
![image](https://github.com/user-attachments/assets/b5ea7bdc-b1ba-4c21-9d55-9e6abd716a92)
![image](https://github.com/user-attachments/assets/62f43599-0e83-4a5a-9beb-694ef461332a)

![image](https://github.com/user-attachments/assets/c674c357-f338-4053-8e01-1103cad0d7fb)
list of resource managed apis in devres.h
![image](https://github.com/user-attachments/assets/af6659cf-97b4-4e4b-a9ea-36a030910b38)

How to get rid of gotos in driver writting , simplification of probe and remove. only use RMK api when we does on behalf of "struct device"
![image](https://github.com/user-attachments/assets/c1cdf95a-1813-4a22-94bf-6a8185303f47)
![image](https://github.com/user-attachments/assets/88aff16a-f6e8-40d4-b491-e52e00009794)

Changing probe api
![image](https://github.com/user-attachments/assets/71145944-7ec5-4990-a4f3-3564d9cee3ef)
![image](https://github.com/user-attachments/assets/e89625dd-c7cc-4a1b-976d-0f9991ae2bd9)
![image](https://github.com/user-attachments/assets/dc3eb3fa-64f6-4afe-84e3-4df21a0cb116)

Adding some more platform devices
![image](https://github.com/user-attachments/assets/18637531-99d7-4188-a62d-ae8064f2a71d)
![image](https://github.com/user-attachments/assets/e8aa3bda-3b93-4fa9-81cb-a8795cbacac9)
Add multiple devices in one go
![image](https://github.com/user-attachments/assets/ccac9b0c-f7a8-4280-a184-417fefc12040)
![image](https://github.com/user-attachments/assets/2d2dc2eb-0941-4246-9d45-c3dd83416f10)
Kernel crash
![image](https://github.com/user-attachments/assets/d902d2c0-4786-4de8-a6ea-b9278b8840e6)

![image](https://github.com/user-attachments/assets/6f08e235-879a-4f86-a55a-94e01281ea9d)
id1 used more
![image](https://github.com/user-attachments/assets/0e1469fb-e253-4eb8-b760-c8ee625d2c96)
Removing caused issue of crash
![image](https://github.com/user-attachments/assets/f9490820-5de1-4e97-8e40-31ec450c446a)
dmesg
![image](https://github.com/user-attachments/assets/499bc601-b75e-48de-a874-569af771051e)
![image](https://github.com/user-attachments/assets/c310fbdc-7fa4-4944-995a-064275c6a767)
Reboot machine now

for platform device setup module
pcdev_platform_init() and pcdev_platform_exit() are required.
These are calling register and unregister apis for platform device. platform device is given by platform_device structure. user defined, but some mandatory fields are there.
![image](https://github.com/user-attachments/assets/e095bf96-bf2f-4de9-ae1d-49e1014a31a0)

Platform device and driver matching technique, using platform device ids
![image](https://github.com/user-attachments/assets/6eb92f6a-9460-4665-ae99-bc72e3ee146a)
- single driver store diff configs
- it detects chip - verify device id - and load respective config params, and thus config device properly
![image](https://github.com/user-attachments/assets/62fffb09-93a5-411a-83e5-85d6ef3438ff)

Platform driver must support different device ids. when driver detect any id from supported range, it's a match, probe gets called, and device gets configured.
![image](https://github.com/user-attachments/assets/699e12cb-dfaf-40dd-8da3-51bb35b44ce7)
modify pcd platform drier, to support different version of pcdevs. pcdev-A1x, pcdev-B1x, pcdev-C1x

Hookup device id table here
![image](https://github.com/user-attachments/assets/6d7990c4-f2fa-4a7c-8080-ea3715ca0a7a)
![image](https://github.com/user-attachments/assets/d3005d2b-e508-4edd-84ef-051945fddfe0)

device setup has name change
![image](https://github.com/user-attachments/assets/000025bf-8c10-4085-8d49-961afb4f5e7a)

in driver code, we are eliminating name based matching, and now, going for id based matching.
![image](https://github.com/user-attachments/assets/a4e08694-408b-4a41-9b07-e5efc29d17e9)
![image](https://github.com/user-attachments/assets/0a06c6b6-f49c-46cc-b3df-2c7a559baf45)

if id table based matching is selected then driver.name based matching won't be happening
![image](https://github.com/user-attachments/assets/73f5f8f0-1bec-40bd-8543-9761ddc7c1ec)

see here, last 2 options, 1st device tree based, then acpi based, then id based and then name based matching happeening. 
![image](https://github.com/user-attachments/assets/e84128fe-3fa5-4e31-bf56-db6be13b092d)
![image](https://github.com/user-attachments/assets/93dbe885-2a2a-4bb2-9919-2e254219cbf2)
![image](https://github.com/user-attachments/assets/fa75dd7c-1ada-40ab-8d9f-9ca29aa617be)

Header is mod_devicetable.h
![image](https://github.com/user-attachments/assets/f57a4fa2-d542-40d9-90fd-d49256d346ec)

dmsg -C // clear dmessage
![image](https://github.com/user-attachments/assets/2b59351e-98de-4a10-89b9-48750633d3dc)

3 types of device ids are provided so only 3 devices got loaded
![image](https://github.com/user-attachments/assets/7313c7e0-f5f9-403a-ac94-cf9fb48e9025)

4th one D1x is not supported by driver, so not loaded.
Add to id table and rmmod pcd_platform_driver.ko, add
![image](https://github.com/user-attachments/assets/53d0c731-cd16-41d3-b98b-72cb8b68caed)

insmode pcd_platform_driver.ko
![image](https://github.com/user-attachments/assets/62fe3ccb-451f-4b44-8a6a-a24e7322e057)

Config Item usage
![image](https://github.com/user-attachments/assets/b9671e37-77c9-4d7f-be89-aa2f71f4ed61)
![image](https://github.com/user-attachments/assets/2951d2e2-8942-4b18-8207-9d7d52730ffc)
![image](https://github.com/user-attachments/assets/9a8d551a-db6a-4358-8944-f327ad884952)

platform  driver init and cleanup made easy
![image](https://github.com/user-attachments/assets/9e362e79-7b7a-454a-895d-80ed24b5a6c5)

if just register and unregistering is happening then good to use this macro, else ignore.
![image](https://github.com/user-attachments/assets/86b5adba-cdea-4633-8ca9-5683b667d56d)

just pass platform driver structure name -- e.g pcd_platform_driver
![image](https://github.com/user-attachments/assets/21e38096-25c0-45f2-a2cd-adc65d546c93)
![image](https://github.com/user-attachments/assets/db4cd827-aea6-4c0c-bc45-2571588e7c71)

Here, we are not just doing register-unregister so we can't use. look below
![image](https://github.com/user-attachments/assets/8e89aac3-53ae-4251-b5d1-eada8547a1b0)


## Device Trees
![image](https://github.com/user-attachments/assets/cbc975d1-7349-4b35-9ae0-751b6a60e538)
![image](https://github.com/user-attachments/assets/e9f08af3-8c4a-4674-857e-b5586fbaafa3)
![image](https://github.com/user-attachments/assets/64bb6702-24c5-423a-98a9-990773a49aa8)
![image](https://github.com/user-attachments/assets/1e9c09c0-5e03-4881-b143-48c87887570d)

kernel creates kernel data structure with fed device tree - HW configurations,
this details are pased to driver, using probe function.
![image](https://github.com/user-attachments/assets/057712a9-ac30-44a7-b0a6-ef53b6c98519)
![image](https://github.com/user-attachments/assets/c7b1ffbe-b090-4102-8854-4cb0c23d8454)
![image](https://github.com/user-attachments/assets/6d177c30-c323-4659-8e33-05fce7acac62)

Writting device tree
![image](https://github.com/user-attachments/assets/ca52a6b6-7f94-4531-aaf0-f8d48efb591d)
![image](https://github.com/user-attachments/assets/ba64729e-aca0-4050-abbc-641ba5d11c91)
![image](https://github.com/user-attachments/assets/915097cd-e051-45b2-9cc5-8cfba51f2071)
Hierrarchy
![image](https://github.com/user-attachments/assets/03f8b016-455a-43f6-9302-e5912e52e5d1)
![image](https://github.com/user-attachments/assets/3a232d8c-5434-49d1-a32a-8d8ccdd107b4)
SOC specific dtsi (on-chip peripheral and processor description) is included to board specific dtsi(on-board peripheral)
![image](https://github.com/user-attachments/assets/c10b4544-e082-43df-b34e-7ac617489725)
dtsi, device tree source include files, which are menat to be included. and dts are actual device tree source file.
![image](https://github.com/user-attachments/assets/815eb063-5e13-41aa-8935-da8445a8a02e)
![image](https://github.com/user-attachments/assets/e2b10648-62bf-4c04-ae17-3e5e082aa363)
device tree structure
![image](https://github.com/user-attachments/assets/2e63c12f-40cf-43a5-819c-48e7af9034b8)
device tree is collection of nodes(nodes are devices) which are related to each other with parent-child relationship
root node is required, and it's a beginning/starting point of device tree. this is the reference node.
![image](https://github.com/user-attachments/assets/2f5a551e-95aa-4c81-a23b-c83793ade92b)
properties are used to descrive node/device.
![image](https://github.com/user-attachments/assets/72bc90db-c8d2-4f39-9631-6a16618b8060)
CPU and memory nodes are root level nodes
parent-child relationship
![image](https://github.com/user-attachments/assets/6c59aa2f-1f12-4699-bbd0-a8c2897371ce)
i2c node explains controller of the hardware, and child nodes describes devices/user/clients connected to controller.
![image](https://github.com/user-attachments/assets/a9a5db3c-e038-4c4c-a3c1-7ebaab2542f9)
structural representation
root level nodes are also called soc level nodes. There are set of properties, which we can set for a device
![image](https://github.com/user-attachments/assets/bf034b1f-f459-45a3-9399-e5f1e03619f3)
![image](https://github.com/user-attachments/assets/fba8a45d-15cf-4877-ba30-7832c1d64d42)
![image](https://github.com/user-attachments/assets/c6234059-8cd3-4aaf-b948-38711ca5336f)
in root node, cpu and memory node are present at root level. mandatory as a root level node.
![image](https://github.com/user-attachments/assets/20e2def7-91fa-48a6-8cfd-81b1d5c802eb)

How to write?
![image](https://github.com/user-attachments/assets/9893f0fc-ff73-422f-aa10-8f97e8e2c02e)
soc level DT is provided by vendors in the form of dtsi
user mostly write device tree level over-lays or add-ons for board relate changes.
![image](https://github.com/user-attachments/assets/d6d07800-c989-4011-a8c4-a114999a7d20)
![image](https://github.com/user-attachments/assets/f70f97d0-ae58-43bd-a8cf-b18b5d4b48e1)
properties of root node
![image](https://github.com/user-attachments/assets/a8ea8604-9aaf-49a2-8e34-a5b7eee6f124)
Every dtree has one root node. Top level device tree file give root node, 
in board specific dts dummy root nodes are used for some overwritting of top level dtree root node.

dtsi
![image](https://github.com/user-attachments/assets/dec66fda-36d8-4e88-b4ae-6f94a23a59ce)
dts
![image](https://github.com/user-attachments/assets/e5d382ce-b3d5-4e34-8454-78314d127471)
property added
![image](https://github.com/user-attachments/assets/254b286a-4621-4a4d-920b-36e6f57dbc3b)

over writting top level device tree inclusion/dtsi in device speicfic or board specific dts file
![image](https://github.com/user-attachments/assets/52116a5a-65e9-4ccc-a243-21acc8398b75)
![image](https://github.com/user-attachments/assets/9838b6f5-fb4c-4773-a468-e7d4b101ff22)

DT writting syntax
![image](https://github.com/user-attachments/assets/81e2b311-e503-4ee7-9a90-7a0051bc846f)
![image](https://github.com/user-attachments/assets/760fecfb-2d88-4dee-8eeb-798640d261af)
![image](https://github.com/user-attachments/assets/d24cb22d-7344-4c86-9d46-f3f4db40a77e)
![image](https://github.com/user-attachments/assets/38819748-2972-44be-98be-f4edd4da5b5c)
![image](https://github.com/user-attachments/assets/147abd4d-8f48-4621-b68d-74b38c0c9c45)
![image](https://github.com/user-attachments/assets/75bdcb53-3188-4e85-b2ab-5ed5c1932ef5)
unit-name is address of bus where device sits, or base address (register content) of the device, if device is memory mapped.
![image](https://github.com/user-attachments/assets/179060dd-0ef9-4516-bfa0-1b6430dd7c5e)
![image](https://github.com/user-attachments/assets/3b668dcf-bd8d-4a58-b2ca-454255d72dcb)
![image](https://github.com/user-attachments/assets/eb9baea8-3044-4a4b-9130-06c64d0f5ec6)
![image](https://github.com/user-attachments/assets/c8ae5f31-f984-44e8-8975-f353816aef81)

this board device tree explains, i2c0 and i2c1 controller
![image](https://github.com/user-attachments/assets/00cd225b-5196-47dc-a882-f9cf5606c987)

node name is i2c@ADDRESS. as addresses of i2c controllers are different, it's node name will be unique as well.
![image](https://github.com/user-attachments/assets/f9af80f0-25d2-40e1-8b9e-102cbf0975d5)

for this controller, 1st register in memory map is start at this reg property specified address.
base, size of memory map are given as below.
![image](https://github.com/user-attachments/assets/075919db-8a16-40cb-9156-cd4216f18279)
Check TRM(Technical reference manual of soc) to check base memory mapped address start/base for this controller.
![image](https://github.com/user-attachments/assets/510591cd-ab3c-4d49-8f56-60876696eb5a)
![image](https://github.com/user-attachments/assets/abd761fe-d2b5-457d-b2cc-0995658afb0c)
![image](https://github.com/user-attachments/assets/4361574d-7e81-4eb8-b13b-a606d0968836)
so reg property should be used for creating node-name by using as unit-address.
for ease, simply use alias/lable
![image](https://github.com/user-attachments/assets/28e97b35-e99b-4d73-8555-2d753692e6d9)
![image](https://github.com/user-attachments/assets/4577c9b6-f6c4-44a1-9c64-68ce3c0fe8d0)
![image](https://github.com/user-attachments/assets/1878fbd1-f2bc-4393-8e5c-2c95bad27aca)
remember reg property will only comes into picture when device has memory mapping or device addressing.
in case of absence of reg property, omit unit address.

Parent Child relationship
![image](https://github.com/user-attachments/assets/14baf700-aaf4-4462-8538-97fc979ca559)
![image](https://github.com/user-attachments/assets/b78f5192-9179-49cc-939e-9cdf1a37c601)
check BB black common dtsi, where amending of status ('disabled' to 'okay') and adding of children is done.
![image](https://github.com/user-attachments/assets/8ddb712c-3c36-47b6-be53-e3c2f820fc80)

2 child nodes. i2c is referenced and changes are amended.
![image](https://github.com/user-attachments/assets/3a65b0cf-7e6b-4dba-a88c-71980de060a6)
reg property explains i2c address, as it is not on-chip device and not memory mapped, but an external hardware on BB Black HW.
communicates with soc over i2c, and hence it has separate address.
![image](https://github.com/user-attachments/assets/35973cd7-8be0-48ca-8da3-83a771042113)
![image](https://github.com/user-attachments/assets/05780edb-20c3-471e-8af5-15f6f21faa70)
One more childnode of eeprom to explain memory section. this is optional one.
![image](https://github.com/user-attachments/assets/e9d878b8-1f5b-40d5-9620-869f8761e952)


Standard property (device-driver binding doc or by speicifications) vs non-standard/custom properties(non-specific or vendor/org specific properties).
![image](https://github.com/user-attachments/assets/8c17ceb1-1b1f-45e3-ab08-e52d6b7f25b5)
![image](https://github.com/user-attachments/assets/ff97c90f-0861-4a68-b0e5-1096b5ae6794)
![image](https://github.com/user-attachments/assets/4905a0af-d790-4965-a0d9-4e05516d8cee)
Non-standard property name convention. it's prepended by some org specific ticker followed by coma and then property name.
![image](https://github.com/user-attachments/assets/b345612b-30fc-4519-aebc-3331a632a0c4)
![image](https://github.com/user-attachments/assets/68b99ba8-d3d4-4d38-825c-c02e57067577)

## Properties
'compatible'
![image](https://github.com/user-attachments/assets/9f9958dc-eb92-4d99-8ead-6d678b1c0743)
property values
![image](https://github.com/user-attachments/assets/1bbd56cb-17e8-4cb8-b264-c105f974ec9c)
![image](https://github.com/user-attachments/assets/809ce4e4-fba8-42a2-89eb-847969337235)
client program -- here linux, uses this to define driver.
![image](https://github.com/user-attachments/assets/fd27cc07-bf1e-4276-9e39-25875fbcf381)
This is like, these set of or family of devices are compatible to specific driver. just like, we had device family details in platform pcd device-driver emample, and kernel used name of this to see compatibility with respective driver.

When kernel sees this compatible string, it will try to find the driver supporting the exact string.(more specific compatible driver), kernel load driver, and probe is called. if not located this, then go to next string match.
![image](https://github.com/user-attachments/assets/0775a851-9193-41cc-a008-282e59a0577f)


We are going to change our PCD driver implementation by using device tree method, and pass device private data as properties to the driver.
![image](https://github.com/user-attachments/assets/41e5b34b-5656-478e-aba4-5371392a1d62)

exmaple
![image](https://github.com/user-attachments/assets/b4bcb4d2-c17a-4038-aecc-a934328c86b2)
![image](https://github.com/user-attachments/assets/45673627-bc4e-434c-a003-bbfc0ba0da3f)
Checking goes, most specific to more general
![image](https://github.com/user-attachments/assets/9944fbe0-e337-416b-9400-a7f2896924ca)
if not matching found, then use machine identification fails
![image](https://github.com/user-attachments/assets/6bc81ec8-57cf-4de0-8f07-4cec0ed6d563)

Usecase of 'compatible' property
![image](https://github.com/user-attachments/assets/39701e4a-744e-45bf-b8db-43e18e81815b)

How to track supported list of SoCs?
suppose we have dtsi
![image](https://github.com/user-attachments/assets/91446594-bfbb-4aaa-8a38-ce428b6cdc90)
check compatible field. we get driver details. goto/drivers/i2c/ and find i2c driver of soc family omap.
![image](https://github.com/user-attachments/assets/cfe6041c-400e-4c8e-b9c3-e2f5bd389ab3)
![image](https://github.com/user-attachments/assets/1c9c1bf0-fcdf-4aee-a6a3-a3e439a108b3)
go at the end, and check which platform driver is getting registered.
![image](https://github.com/user-attachments/assets/bbd594f5-5dbe-49bf-858b-03eb4b3cd7e8)
goto that driver structure
![image](https://github.com/user-attachments/assets/765fd208-fed1-434c-8447-d3c22f98e0c5)
goto, open firmware match table
![image](https://github.com/user-attachments/assets/4f1c5d09-55be-41a0-ac1e-90acd5a4565a)
so this driver supports i2c controller/peripheral for all these SoCs.
so, the compatible name which we have kept in our i2c dts, is matching with one of the entry of this driver supporeted soc in driver structure's of_match_table. if status is "okay" in dtsi, then that driver's probe function is getting called.

observe, there's no driver for this tsp device, because, there's no compatible property mention, so no driver to load
![image](https://github.com/user-attachments/assets/3e569987-bcdb-40f6-9edc-6d4c1b68bd4d)

for second device, as it has compatible property, that driver will get loaded for this device node.
![image](https://github.com/user-attachments/assets/9e867cc3-6022-434a-a8c1-3f49b5e4bd0c)
![image](https://github.com/user-attachments/assets/8a30cafd-6e9e-46d3-a87d-a02c1463d11c)


But How does one know, which properties to mention, and from where to refer?
![image](https://github.com/user-attachments/assets/66f91b4f-2597-4b74-a538-cc2c83054c6a)
![image](https://github.com/user-attachments/assets/e3b94703-fd2b-4bb9-8aa7-8025a1fdf702)
device driver writter is responsible to provide this details. e.g. device tree binding document
![image](https://github.com/user-attachments/assets/922146c6-adce-4de2-ae2b-739869d714b2)
device binding properties are in devicetree bindings document
![image](https://github.com/user-attachments/assets/3e987823-8bb6-44d3-8ace-c454f1de000c)
![image](https://github.com/user-attachments/assets/39fff948-5ad6-4a91-b246-0a617648bcd0)
required, recommended and optional, these are types of properties.
![image](https://github.com/user-attachments/assets/6494080f-7297-4dc5-98d6-61a69d55e6f0)

How it comes to kernel
![image](https://github.com/user-attachments/assets/17901864-c8b4-47dc-85cb-94a54589c76a)
Client programs like OS and drivers defines compatible strings and properties and add in binding document, and then shared with DT writer to refer from  
![image](https://github.com/user-attachments/assets/c337d2e2-59e4-4b3b-8d4c-8718758052d4)

Cases when driver is part of kernel, and not part of kernel
![image](https://github.com/user-attachments/assets/dc00b866-a3c6-4832-be8f-3852a2030aab)
binding document for lm75
![image](https://github.com/user-attachments/assets/6d3fbc5c-5b55-4c33-9d40-5e6b20f1f0e6)
driver for lm75
![image](https://github.com/user-attachments/assets/e0d1de3a-d20e-4d12-992c-9b29677bf22f)

for mpu6050
![image](https://github.com/user-attachments/assets/99475133-cc69-4583-9c11-f80b6f191b12)

refer here:
![image](https://github.com/user-attachments/assets/729ddc10-ef13-4319-9c7c-411773372d6d)

Device tree writting style
![image](https://github.com/user-attachments/assets/8ac3587c-568e-4840-8f5a-8b3bb805a83b)

## Rewritting pcd driver, and instantiating devices from the dts.
![image](https://github.com/user-attachments/assets/8a2aec0a-8851-4672-a727-1a93e8366ac9)

## steps to compile kernel
![image](https://github.com/user-attachments/assets/f84ee0fe-3607-4bbe-ad8b-ba7ca6d766e4)
1. defconfig
2. kernel compilation
3. module compilaiton
4. module install

## upading BB black board
- plug SD card.
- copy uImage from /arm/arch/boot
- ![image](https://github.com/user-attachments/assets/922020c2-f52e-4dba-8023-e5966cccf85c)
- cd dts/
- ![image](https://github.com/user-attachments/assets/3002a73e-8d6f-41ec-a49b-2aa33d3c34bc)
- if module install is already done, then
- ![image](https://github.com/user-attachments/assets/65e76a29-5eaf-4669-928e-1ef42a772ea4)
- connect SD card to HW BB. and power on.
- booting
- ![image](https://github.com/user-attachments/assets/f7672bd2-48f2-4a31-9299-7a3815f8fbe7)
- uname -r
- ifconfig, now look for usb interfaces as those should be there, if not then reobot
- ![image](https://github.com/user-attachments/assets/d039b148-374c-44ce-a17c-2a84b91a61a9)
- required for ssh connection
- ![image](https://github.com/user-attachments/assets/1fd02b73-0ac6-4303-baf6-e89e378980a5)


## DTB creation, compilation, sending
![image](https://github.com/user-attachments/assets/42a44b59-6e2a-40fd-9d4d-bf34e27caf51)
send to board, add command to makefile
![image](https://github.com/user-attachments/assets/701a8a98-7912-4cc6-a524-db3bd85fbc99)
![image](https://github.com/user-attachments/assets/6c2e5d3e-62da-4828-928f-5604779c1af5)
transfer driver
![image](https://github.com/user-attachments/assets/b1274c9c-5db7-4eab-8bdf-823d9d1c51d3)
![image](https://github.com/user-attachments/assets/e1d0af32-7065-4bb0-8a5c-94904908197f)

login to termianl of bbb
minicom command
![image](https://github.com/user-attachments/assets/3f1f883c-8c66-40eb-879b-b8389bf651f2)
![image](https://github.com/user-attachments/assets/05b8c7f7-00c6-470e-b5df-f3886b9029bd)

Send dtb to boot partition
![image](https://github.com/user-attachments/assets/d7cce441-5d81-46ff-90c4-18fac3ddd5c3)
![image](https://github.com/user-attachments/assets/9ae1719b-c150-419c-8dd9-fd51eef1aca3)
remove old dtb as its 4.14
![image](https://github.com/user-attachments/assets/130f3343-ded9-4e29-8d26-9f36fe64e2e1)
![image](https://github.com/user-attachments/assets/5b185d40-1bbb-46db-958c-5249caa259e4)
![image](https://github.com/user-attachments/assets/ace621ff-586f-417f-b0f0-5e594e4d754a)
Now reboot, so this uboot supply new dtb to kernel
![image](https://github.com/user-attachments/assets/227e3701-a59e-4bb9-8a5e-d8e6bd102b9d)
![image](https://github.com/user-attachments/assets/0634b545-1b4c-43a4-a47e-7c915f455148)

Check added devices
![image](https://github.com/user-attachments/assets/1c16154c-461d-4a51-8395-3398cc1e9ff2)
![image](https://github.com/user-attachments/assets/5f074d73-3d57-4171-a109-908f10e7230a)
of_node shows dt property

Load driver
![image](https://github.com/user-attachments/assets/17766784-cd5c-4622-8f2b-1011202588e1)
![image](https://github.com/user-attachments/assets/1cd0dfe7-01dc-4cbe-b839-3f7d89428bb3)
See, probe executed.
removing driver
![image](https://github.com/user-attachments/assets/7a54ca4b-ed02-4ff6-89b7-79c1cb6164ec)
and hence matching finishes device node and driver matching done.

2 kind of methods we have seen to call probe.
1. manual way of registering device and probe gets called using device setup method
2. device tree method, where without any device registration, probe gets called.

In probe, one need to decide if probe instantiated from device setup code or due to device tree node.
and based on that, of.h helper apis can be used.

![image](https://github.com/user-attachments/assets/5b7ae143-8a0e-4186-874a-b9764c028c5b)
![image](https://github.com/user-attachments/assets/d84be416-519e-4c23-970f-b13e202afdac)

if pdata is null, then check if setupcode called this probe. and if that also fails, then message, no platform data available.
![image](https://github.com/user-attachments/assets/b17bf0dc-6e9b-485a-91ab-842f3c08c6c1)

