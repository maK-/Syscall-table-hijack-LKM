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

OUTPUT
==========
insmod maK_it.ko
Message from syslogd@localhost at Nov 25 17:36:13 ...
 kernel:Syscall Table old address: c08532b0

Message from syslogd@localhost at Nov 25 17:36:13 ...
 kernel:Syscall Table new address: f7e87000


rmmod maK_it
Message from syslogd@localhost at Nov 25 17:37:49 ...
 kernel:Module exited cleanly
