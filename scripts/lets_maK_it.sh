#!/bin/bash
#used to insert the memory addresses of:
#sys_call_table

KERN=$(uname -r)
IN="template.c"
OUT="maK_it.c"

BREAK="----------------------------"

echo "Finding Kernel System Call Table Address..."
echo $BREAK
GET_SC_TABLE=$(grep sys_call_table /boot/System.map-$KERN | (awk '{print $1}'))
SYSCALL_TABLE="SYSCALL_TABLE 0x"$GET_SC_TABLE
echo $SYSCALL_TABLE

#Templates to be replaced
SCT="SYSCALL_TABLE_TEMPLATE"

echo $BREAK
echo "Building '$OUT' File..."
sed -e "s/$SCT/$SYSCALL_TABLE/g;" < $IN  > $OUT
echo "Done."

