#include<stdio.h>
#include<string.h>

int my_strcmp(char* s1, char* s2){
    //int min_len=strlen(s1)<strlen(s2)?strlen(s1):strlen(s2);

    int ptr=0;

    for(ptr=0;;ptr++){
        if(ptr==strlen(s1) || ptr==strlen(s2) ||s1[ptr]!=s2[ptr]){//s1先到终点
            break;
        }
    }

    return s1[ptr]-s2[ptr];
}

int main(){
    char s1[2000];
    char s2[2000];

    fgets(s1,1000,stdin);
    fgets(s2,1000,stdin);
    //scanf("%s %s",s1,s2);

    printf("%d\n",my_strcmp(s1,s2));
}