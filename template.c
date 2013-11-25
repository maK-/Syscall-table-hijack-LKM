/*
 * This is the template file used to build a system
 * specific kernel module.
*/

#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/errno.h>
#include<linux/types.h>
#include<linux/unistd.h>
#include<asm/current.h>
#include<linux/sched.h>
#include<linux/syscalls.h>
#include<asm/system.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("maK");

#define SYSCALL_TABLE_TEMPLATE

unsigned long *sys_call_table = (unsigned long *) SYSCALL_TABLE;

asmlinkage int (*original_write)(unsigned int, const char __user *, size_t);

asmlinkage int new_write(unsigned int fd, const char __user *buf, size_t count){	
	//Hijacked write function here
	return (*original_write)(fd, buf, count);
}

static int init_mod(void){
	printk(KERN_EMERG "Syscall Table old address: %x\n", SYSCALL_TABLE);
	
	//Changing control bit to allow write	
	write_cr0 (read_cr0 () & (~ 0x10000));

	original_write = (void *)sys_call_table[__NR_write];
	sys_call_table[__NR_write] = new_write;
	printk(KERN_EMERG "Syscall Table new address: %x\n", new_write);
	//Changing control bit back
	write_cr0 (read_cr0 () | 0x10000);
	return 0;
}

static void exit_mod(void){
	//Cleanup
	write_cr0 (read_cr0 () & (~ 0x10000));
	sys_call_table[__NR_write] = original_write;
	write_cr0 (read_cr0 () | 0x10000);
	printk(KERN_EMERG "Module exited cleanly");
	return;
}

module_init(init_mod);
module_exit(exit_mod);
