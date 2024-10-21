#include<stdio.h>

int f(int n){
    if(n==0) return 1;
    if(n==1) return 3;
    return (4*f(n-1))-f(n-2);
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", f(n));
}