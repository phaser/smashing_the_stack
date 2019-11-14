#include <stdio.h>
#include <string.h>
#include <stdint.h>

void function (int a, int b, int c) {
    char buffer1[5];
    uint64_t *ret;
    
    for  (a = 0; a < 40; a++) {
    	ret = (uint64_t*)(buffer1 + a);
    	(*ret) = 0xABCDEF00; 
    }

    // modify the return address to skip x - 1 at line 20
    // so printf will print 0
    ret = (uint64_t*)(buffer1 + 21);
    (*ret) += 7;
}

int main(int argc, char** argv) {
    int x;

    x = 0;
    function(1, 2, 3);
    x = 1;
    printf("%d\n", x);
    return 0;
}
