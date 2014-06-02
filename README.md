Syscall-table-hijack-LKM
========================

This demonstrates the hijacking of the "write" system call and how to set the 
System Call table to read/write mode via modifying the correct cr0 bit.

To run simply run "make" in the folder with the Makefile.

Then install with 
insmod maK_it.ko

Remove with 
rmmod maK_it

Building towards development of a rootkit...
You can read more at the blog post here http://r00tkit.me/?p=46

OUTPUT
==========
insmod maK_it.ko
Message from syslogd@localhost at Nov 25 17:36:13 ...
 kernel:Syscall Table Address: c08532b0

Message from syslogd@localhost at Nov 25 17:36:13 ...
 kernel:Syscall Table old write address: c0537520

Message from syslogd@localhost at Nov 25 17:36:13 ...
 kernel:Syscall Table new write address: f7e58000

rmmod maK_it
Message from syslogd@localhost at Nov 25 17:37:49 ...
 kernel:Module exited cleanly

Techniques from here http://memset.wordpress.com/2010/12/03/syscall-hijacking-kernel-2-6-systems/
