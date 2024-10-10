#include<stdio.h>
int main(){
    int min, max;
    scanf("%d %d", &min, &max);

    long long result=0;

    for(int i=min; i<=max; i++){
        result+=(i*i);
    }

    printf("%lld\n", result);
}