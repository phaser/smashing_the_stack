## Bash run objdump to obtain hex dump of program

```bash
for i in $(objdump -d shellcode |grep "^ " |cut -f2); do echo -n '\x'$i; done;
```

## Disable ASLR on linux

```
echo 0 > /proc/sys/kernel/randomize_va_space
```

```
sysctl -w kernel.randomize_va_space=0
```

Permanently disable ASLR
```
echo "" >> /etc/sysctl.conf
echo 'kernel.randomize_va_space = 0' >> /etc/sysctl.conf
```

## Run the exploit

```
./exploit 600 400
./vulnerable
# exit, exit should not exit terminal this showing that we were actually chained to 2 instances of shell
```

## Links

  * [Linux 64bit Smashing the stack](https://blog.techorganic.com/2015/04/10/64-bit-linux-stack-smashing-tutorial-part-1/)
  * [Minimal example of shellcode](https://systemoverlord.com/2014/06/05/minimal-x86-64-shellcode-for-binsh/)
  * [Linux system call table for x86_64](https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/)
