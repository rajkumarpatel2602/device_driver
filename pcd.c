//pseudo character driver implementation

#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/export.h>
#include <linux/device.h>
#include <linux/kdev_t.h> /* for major and minor */

#define DEV_MEM_SIZE 512

#undef pr_fmt
#define pr_fmt(fmt) "%s :" fmt, __func__

/* Pseudo-Device memory buffer */
char device_buffer[DEV_MEM_SIZE];

/* This holds device number */
dev_t device_number;

loff_t pcd_llseek(struct file *filp, loff_t offset, int whence){
	pr_info("lseek requested");
	return 0;
}

ssize_t pcd_read(struct file *filp, char __user *buff, size_t count, loff_t *f_ops){
	pr_info("read requested");
	return 0;
}

ssize_t pcd_write(struct file *filp, const char __user *buff, size_t count, loff_t *f_ops){
	pr_info("write requested");
	return 0;
}

int pcd_open(struct inode *inode, struct file *filp){
	pr_info("open requested");
	return 0;
}

int pcd_release(struct inode *inode, struct file *filp){
	pr_info("release requested");
	return 0;
}

/* character driver variable */ // N vars for N devices. e.g. 1 here.
cdev pcd_cdev;


/* file operations. in kerenl driver development we do init here only. */
struct file_operations pcd_fops = {
	.open = pcd_open,
	.lseek = pcd_lseek,
	.read = pcd_read,
	.write = pcd_write
	.release = pcd_release,
	.owner = THIS_MODULE
};

/* device class */
struct class *class_pcd = NULL;

/* device pointer */
struct device_pcd;

static int __init pcd_driver_init(void) {

	/* 1. Dynamically allocate device number */ // using kernel apis for this. ignore error handling.
	alloc_chrdev_region(&device_number, 0 /* base starts with 0 */, 1 /* just one device instance */, "pseudo-devices");

	pr_info("Device number <major>:<minor> = %u:%u", MAJOR(device_number), MINOR(device_number));

	/* 2. Character device registration with VFS */ // N call for cdev_ for N device. e.g. 1 here
	cdev_init(&pcd_cdev, &pcd_fops);
	/* cdev struct is memset to zero in init, and hence now set owner */
	pcd_dev.owner = THIS_MODULE;

	/*Register cdev structure with VFS. Useful for mapping fops. */
	cdev_add(&pcd_cdev, device_number, 1); /* device instance count which we want to register */

	/* Note.
	 * when we say open() and fd is return, that fd is actually reference 
	 * to file object which is in kernel memory. subsequent calls uses this same reference.
	 * 
	 * flow is, inod object hold cdev struct, which has f_ops, which is getting maped to file object f_op and drive
	 * methods are called later.
	 */

	/* 3. Add device file. export major-minor number to sysfs. so that udev can refer to dev file in sysfs/class/ */
	
	/* Create class under /sys/class. e.g. ls -lah /sys/class/pcd_class. $cat dev and uevent. has MINOR, MAJOR, DEVICE */
	/* this info will be used by udevd to populdate /dev/pcd on next call */
	class_pcd = class_create(THIS_MODULE, "pcd_class");
	
	/* device file creation or populdate sysfs (/dev/pcd) with device information. ls /dev/pcd after insmod */
	device_create(class_pcd, NULL /* parent device */, device_number, NULL /* extra info */, "pcd" /* device file name */);

	pr_info()

	return 0;
}

/* mandatory */
static void __exit pcd_driver_cleanup(void) {
	
	/* in reverse order */
	
	device_destroy(pcd_class, device_number);
	class_destroy(pcd_class);
	
	cdev_del(&pcd_cdev);
	
	unregister_chrdev_region(device_number, 1/* number of device numbers to unreg, in our case minor number */);
	
	pr_info("pcd module unloaded.");
	
	return;
}

module_init(pcd_driver_init);
module_exit(pcd_driver_cleanup);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("RAJKUMAR");
MODULE_DESCRIPTION("pseudo-device character driver");
