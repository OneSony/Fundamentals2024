#include<stdio.h>

unsigned int alpha(unsigned int n){
    if(n<10){
        return n;
    }
    unsigned int result=1;

    unsigned int temp;

    while(n>0){
        temp=n%10;
        if(temp!=0){
            result *= temp;
        }
        n/=10;
    }

    return alpha(result);

}

int main(){
    unsigned int n;
    scanf("%u", &n);

    printf("%u\n", alpha(n));
}