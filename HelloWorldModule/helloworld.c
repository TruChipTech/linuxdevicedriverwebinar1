#include <linux/module.h> /* Needed by all modules */ 
#include <linux/kernel.h> /* Needed for KERN_ALERT */ 
#include <linux/init.h>   /* Needed for macros */

int __init example1_init(void);
void __exit example1_stop(void);

int __init example1_init(void) {
  printk(KERN_ALERT "Hello World Entry\n"); 
  return 0; 
} 

void __exit example1_stop(void) { 
//void __exit cleanup_module(void) {
  printk(KERN_ALERT "Exiting Testing 1\n"); 
} 

module_init (example1_init);
module_exit (example1_stop);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("truchip");
MODULE_DESCRIPTION("Hello World Program");
MODULE_INFO(example1_initfunc,"Entry function");
MODULE_INFO(example1_stopfunc,"Exit fuction");
