#include<stdio.h>
#include<string.h>

void sort(char *str){ //原位

    for(int i=0;i<strlen(str);i++){ //计次
        for(int j=0;j<strlen(str)-1;j++){ //每次将最大的放到最后
            if(str[j+1]<str[j]){
                char temp = str[j];
                str[j] = str[j+1];
                str[j+1] = temp;
            }
        }
    }
}

int main(){
    char str[200];

    fgets(str, 200, stdin);


    char bigger[200];
    char smaller[200];

    char c=str[0];
    int bigger_ptr = 0;
    int smaller_ptr = 0;
    for(int i = 1; i < strlen(str)-1; i++){ //去掉换行符
        if(str[i] > c){
            bigger[bigger_ptr++] = str[i];
        }else{
            smaller[smaller_ptr++] = str[i];
        }
    }

    bigger[bigger_ptr] = '\0';
    smaller[smaller_ptr] = '\0';

    sort(smaller);

    printf("%s%c%s\n", bigger, c, smaller);

}