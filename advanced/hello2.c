#include "hello1.h"

#include <linux/moduleparam.h>

static uint howmany = 1;
module_param(howmany, uint, S_IRUGO);
MODULE_PARM_DESC(howmany, "A parameter that defines a number of output strings");

extern int print_hello(uint n);

static int __init hello2_init(void)
{
    return print_hello(howmany);
}
module_init(hello2_init);

static void __exit hello2_exit(void)
{
    pr_info("Good bye, cruel world.\n");
}
module_exit(hello2_exit);
