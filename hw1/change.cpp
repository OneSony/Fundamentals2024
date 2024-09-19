#include<stdio.h>

int main(){

    char c[4];

    scanf("%s", c);

    int num=0;

    int weight=1;

    for(int i=2;i>=0;i--){
        if(c[i]>='A'&&c[i]<='E'){
            num+=(c[i]-'A'+10)*weight;
        }else{
            num+=(c[i]-'0')*weight;
        }

        weight*=15; //15进制
    }


    char result[5];
    result[4]='\0';
    
    int tmp=num;

    for(int i=3;i>=0;i--){
        result[i]=tmp%7+'0';
        tmp=tmp/7;
        //printf("%d %d %d\n",num, result[i]-'0', tmp);
    }


    printf("%s\n", result);
}