![image](https://github.com/user-attachments/assets/43b861fc-cf9d-4d41-8435-11f34b30a5c4)![image](https://github.com/user-attachments/assets/0c3c1add-d47e-405c-8ad0-8ab495dd8385)

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
