#include<stdio.h>
int main(){
    char num[10000];

    scanf("%s", num);

    int len=0;
    for(len=0;;len++){
        if(num[len]=='\0'){
            break;
        }
    }

    //num[len]=='\0'

    for(int i=len-1;i>=0;i--){
        printf("%c",num[i]);
    }
    printf("\n");
}