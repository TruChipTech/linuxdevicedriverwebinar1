#include <linux/module.h>
#include <linux/init.h>
#include <linux/mod_devicetable.h>
#include <linux/property.h>
#include <linux/platform_device.h>
#include <linux/of_device.h>

/* Meta Information */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("truchip");
MODULE_DESCRIPTION("Platform driver example");

/* Declate the probe and remove functions */
static int platformdev_probe(struct platform_device *pdev);
static void platformdev_remove(struct platform_device *pdev);

static struct of_device_id platformdev_ids[] = {
	{
		.compatible = "platformdev",
	}, { /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, platformdev_ids);

static struct platform_driver platformdev_driver = {
	.probe = platformdev_probe,
	.remove = platformdev_remove,
	.driver = {
		.name = "platformdev_driver",
		.of_match_table = platformdev_ids,
	},
};

/**
 * @brief This function is called on loading the driver 
 */
static int platformdev_probe(struct platform_device *pdev) {
	printk("platformdev_probe - Now I am in the probe function!\n");

	return 0;
}

/**
 * @brief This function is called on unloading the driver 
 */
static void platformdev_remove(struct platform_device *pdev) {
	printk("platformdev_probe - Now I am in the remove function\n");
}

/**
 * @brief This function is called, when the module is loaded into the kernel
 */
static int __init platformdev_init(void) {
	printk("platformdev_probe - Loading the driver...\n");
	if(platform_driver_register(&platformdev_driver)) {
		printk("platformdev_init - Error! Could not load driver\n");
		return -1;
	}
	return 0;
}

/**
 * @brief This function is called, when the module is removed from the kernel
 */
static void __exit platformdev_exit(void) {
	printk("platformdev_exit - Unload driver");
	platform_driver_unregister(&platformdev_driver);
}

module_init(platformdev_init);
module_exit(platformdev_exit);


