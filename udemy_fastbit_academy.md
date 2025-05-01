![image](https://github.com/user-attachments/assets/8fde6e27-dc33-4e5b-ad97-d3eb2a355c34)![image](https://github.com/user-attachments/assets/43b861fc-cf9d-4d41-8435-11f34b30a5c4)![image](https://github.com/user-attachments/assets/0c3c1add-d47e-405c-8ad0-8ab495dd8385)

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

platform.h to contain platform data.
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



