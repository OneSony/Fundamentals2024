#include<stdio.h>

int step(int n){
    if(n < 0){
        return 0;
    }

    if(n == 0){
        return 1;
    }

    return step(n-1)+step(n-2)+step(n-3);
}

int main(){
    int n;
    scanf("%d", &n);

    printf("%d\n", step(n));
}