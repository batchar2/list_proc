#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/module.h>

static int __init list_proc_init(void)
{
	struct task_struct *task;
	for_each_process(task){
		printk(KERN_INFO "===$ %s --- [%d] $===\n", task->comm, task->pid);
	}
	return 0;
}

static void __exit list_proc_exit(void)
{
	printk(KERN_INFO "===$ Module exit $===");
}


module_init(list_proc_init);
module_exit(list_proc_exit);


MODULE_AUTHOR("Skokov Stanislav <skokov1992@main.ru>");
MODULE_DESCRIPTION("First");
MODULE_LICENSE("GPL v2");
