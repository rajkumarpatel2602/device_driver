#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/platform_device.h>

// Define probe and remove functions for the driver
static int my_driver_probe(struct platform_device *pdev) {
    printk(KERN_INFO "my_driver: Probe function called\n");
    // Device initialization code here
    return 0; // Return 0 if successful
}

static int my_driver_remove(struct platform_device *pdev) {
    printk(KERN_INFO "my_driver: Remove function called\n");
    // Device cleanup code here
    return 0; // Return 0 if successful
}

// Define driver structure
static struct platform_driver my_driver = {
    .probe  = my_driver_probe,
    .remove = my_driver_remove,
    .driver = {
        .name = "my_driver",
        .owner = THIS_MODULE,
    },
};

// Use the module_driver() macro
module_driver(my_driver, platform_driver_register, platform_driver_unregister);

// Module information
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Rajkumar Patel");
MODULE_DESCRIPTION("A simple platform driver");
MODULE_VERSION("1.0");

