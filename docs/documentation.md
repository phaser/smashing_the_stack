## Bash run objdump to obtain hex dump of program

```bash
for i in $(objdump -d shellcode |grep "^ " |cut -f2); do echo -n '\x'$i; done;
```

## Links

  * [Linux 64bit Smashing the stack](https://blog.techorganic.com/2015/04/10/64-bit-linux-stack-smashing-tutorial-part-1/)
  * [Minimal example of shellcode](https://systemoverlord.com/2014/06/05/minimal-x86-64-shellcode-for-binsh/)
