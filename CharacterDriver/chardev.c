#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/version.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>

int chardev_open(struct inode * inode, struct file * filp);
int chardev_release(struct inode * inode, struct file * filp);
ssize_t chardev_read (struct file *filp, char __user * buf, size_t count,
                                loff_t * offset);
ssize_t chardev_write(struct file * filp, const char __user * buf, size_t count,
                                loff_t * offset);

static unsigned int major; 
static struct class *chardev_class;
static struct cdev chardev_cdev;

// Corrected devnode function with const struct device
static char *chardev_devnode(const struct device *dev, umode_t *mode)
{
    if (mode)
        *mode = 0666;
    return NULL;
}

int chardev_open(struct inode * inode, struct file * filp)
{
    pr_info("chardev_open\n");
    return 0;
}

int chardev_release(struct inode * inode, struct file * filp)
{
    pr_info("chardev_release\n");
    return 0;
}

ssize_t chardev_read(struct file *filp, char __user * buf, size_t count,
                                loff_t * offset)
{
    pr_info("chardev_read\n");
    return 0;
}

ssize_t chardev_write(struct file * filp, const char __user * buf, size_t count,
                                loff_t * offset)
{
    pr_info("chardev_write\n");
    return count;
}

struct file_operations chardev_fops = {
    .owner = THIS_MODULE,
    .open = chardev_open,
    .release = chardev_release,
    .read = chardev_read,
    .write = chardev_write,
};

static int __init chardev_char_init_module(void)
{
    struct device *chardev_device;
    int error;
    dev_t devt = 0;

    /* Get a range of minor numbers (starting with 0) to work with */
    error = alloc_chrdev_region(&devt, 0, 1, "chardev_char");
    if (error < 0) {
        pr_err("Can't get major number\n");
        return error;
    }
    major = MAJOR(devt);
    pr_info("chardev_char major number = %d\n", major);

    /* Create device class, visible in /sys/class */
    chardev_class = class_create("chardev_char");
    if (IS_ERR(chardev_class)) {
        pr_err("Error creating chardev char class.\n");
        unregister_chrdev_region(MKDEV(major, 0), 1);
        return PTR_ERR(chardev_class);
    }

    /* Set the device permissions */
    chardev_class->devnode = chardev_devnode;

    /* Initialize the char device and tie a file_operations to it */
    cdev_init(&chardev_cdev, &chardev_fops);
    chardev_cdev.owner = THIS_MODULE;
    
    /* Now make the device live for the users to access */
    error = cdev_add(&chardev_cdev, devt, 1);
    if (error) {
        pr_err("Error adding chardev char device.\n");
        class_destroy(chardev_class);
        unregister_chrdev_region(devt, 1);
        return error;
    }

    chardev_device = device_create(chardev_class,
                                NULL,   /* no parent device */
                                devt,    /* associated dev_t */
                                NULL,   /* no additional data */
                                "chardev_char");  /* device name */

    if (IS_ERR(chardev_device)) {
        pr_err("Error creating chardev char device.\n");
        cdev_del(&chardev_cdev);
        class_destroy(chardev_class);
        unregister_chrdev_region(devt, 1);
        return PTR_ERR(chardev_device);
    }

    pr_info("chardev char module loaded\n");
    return 0;
}

static void __exit chardev_char_cleanup_module(void)
{
    device_destroy(chardev_class, MKDEV(major, 0));
    cdev_del(&chardev_cdev);
    class_destroy(chardev_class);
    unregister_chrdev_region(MKDEV(major, 0), 1);
    pr_info("chardev char module Unloaded\n");
}

module_init(chardev_char_init_module);
module_exit(chardev_char_cleanup_module);

MODULE_AUTHOR("truchip");
MODULE_DESCRIPTION("chardev character driver");
MODULE_LICENSE("GPL");