#include<stdio.h>
int main(){
    unsigned int n;

    scanf("%u", &n);

    unsigned high_mask = 0xFFFF0000;
    unsigned low_mask = 0x0000FFFF;

    unsigned int high = n & high_mask;
    unsigned int low = n & low_mask;

    high = high >> 16;
    low = low << 16;

    unsigned int result = high + low;

    printf("%u\n", result);
}