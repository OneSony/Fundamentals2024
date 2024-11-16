#include<stdio.h>
#include<string.h>

int expression(char* s){
    int result=0;
    int offset;
    char* ptr=s;

    sscanf(s, "%d%n", &result, &offset);//先读取第一个数
    ptr+=offset;

    for(;;){
        char op;
        sscanf(ptr,"%c", &op);
        ptr++;

        if(op=='='){
            return result;
        }

        int n;
        sscanf(ptr, "%d%n", &n, &offset);
        ptr+=offset;

        if(op=='+'){
            result+=n;
        }else{
            result-=n;
        }
    }
}

int main(){
    char s[120];
    scanf("%s", s);
    printf("%d\n", expression(s));
}