#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>

//default param
static int mod_arg = 42;

// setting arg expectation
module_param(mod_arg, int, S_IRUGO);
MODULE_PARM_DESC(mod_arg, "regular int param!");

static int __init mymodule_init(void){
	printk("loaded mymodule module with arg %d\n", mod_arg);
	return 0;
}

static void __exit mymodule_exit(void){
	printk("unloading mymodule\n");
	return;
}

module_init(mymodule_init);
module_exit(mymodule_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Rajkumar Patel");

