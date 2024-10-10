#include<stdio.h>
int is_prime(int num){
    if(num<=2){
        return 1; //true
    }
    for(int i=2; i*i<=num; i++){
        if(num%i==0){
            return 0; //false
        }
    }
    return 1;
}

int main(){
    int n;
    scanf("%d", &n);

    long long result=0;

    for(int i=2, count=1;count<=n;i++){
        if(is_prime(i)){
            result+=i;
            count++;
        }
    }

    printf("%lld\n", result);
}