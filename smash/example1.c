#include <stdio.h>
#include <string.h>

void function (int a, int b, int c) {
    char buffer1[5];
    int *ret;

    ret = buffer1 + 17;
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