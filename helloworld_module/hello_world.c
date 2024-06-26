#include <linux/module.h>
#include <linux/init.h>

static int __init my_init(void){
	printk("Hello: module loaded at 0x%p\n", my_init);
	return 0;
}

static void __exit my_exit(void){
	printk("Hello: module unloaded from 0x%p\n", my_exit);
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("Rajkumar Patel");
MODULE_LICENSE("GPL v2");

