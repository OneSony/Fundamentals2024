#include<stdio.h>
#include<string.h>


int main(){
    char num[10];
    int flag[10]={0};

    scanf("%s", num);

    int ptr=0;

    for(int count=0;count<strlen(num);count++){
        ptr=(ptr+(num[ptr]-'0'))%strlen(num);
        //printf("%d\n", ptr);
        flag[ptr]=1;
    }

    for(int i=0;i<strlen(num);i++){
        if(flag[i]==0){
            printf("no\n");
            return 0;
        }
    }

    if(ptr!=0){
        printf("no\n");
        return 0;
    }

    printf("yes\n");
}