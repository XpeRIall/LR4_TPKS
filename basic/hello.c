#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/errno.h>

MODULE_LICENSE("Dual BSD/GPL");

static uint howmany = 1;
module_param(howmany, uint, S_IRUGO);
MODULE_PARM_DESC(howmany, "A parameter that defines a number of output strings");

static int __init hello_init(void)
{
    if (howmany > 10)
    {
        printk(KERN_ERR "Error: the parameter cannot be greater than 10\n");
        return -EINVAL;
    }

    if (!howmany || (howmany >= 5 && howmany <= 10))
        printk(KERN_WARNING "Warning: the parameter is set to %u\n", howmany);

    uint i;
    for (i = 0; i < howmany; ++i)
        printk(KERN_NOTICE "Hello, world\n");

    return 0;
}
module_init(hello_init);

static void __exit hello_exit(void)
{
    printk(KERN_NOTICE "Goodbye, cruel world\n");
}
module_exit(hello_exit);
