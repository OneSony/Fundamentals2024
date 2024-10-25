#include<stdio.h>
int main(){
    char str[30];
    char ch;

    fgets(str,30,stdin);

    scanf("%c",&ch);

    for(int i=0;;i++){
        if(str[i]=='\0'){
            break;
        }

        if(str[i]!=ch){
            printf("%c",str[i]);
        }
    }
}