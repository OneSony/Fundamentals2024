#include<stdio.h>
#include<string.h>

int is_prime(int num){
    if(num==1){
        return 0;
    }
    for(int i=2;i<=num/2;i++){
        if(num%i==0){
            return 0;
        }
    }

    return 1;//是prime
}

int is_palindrome(int num){
    char s[1000];

    sprintf(s,"%d",num);

    for(int i=0;i<strlen(s)/2;i++){
        if(s[i]!=s[strlen(s)-1-i]){
            return 0;
        }
    }

    return 1;//是
}


int main(){
    int min,max;

    scanf("%d %d",&min,&max);

    for(int i=min;i<=max;i++){
        if(is_palindrome(i) && is_prime(i)){ //prime不好判断，回文更少，所以应该先判断回文
            printf("%d ",i);
        }
    }
    printf("\n");
}