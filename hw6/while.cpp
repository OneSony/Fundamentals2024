#include<stdio.h>
#include<string.h>

void rearrange(char* num, int* max, int* min){

    char str[10];
    strcpy(str, num);

    for(int i=0;i<strlen(str);i++){ //计次
        for(int j=0;j<strlen(str)-1;j++){ //每次将最大的放到最后
            if(str[j+1]<str[j]){
                char temp = str[j];
                str[j] = str[j+1];
                str[j+1] = temp;
            }
        }
    }

    sscanf(str, "%d", min);

    for(int i=0;i<strlen(str)/2;i++){ //计次
        char temp = str[i];
        str[i] = str[strlen(str)-1-i];
        str[strlen(str)-1-i] = temp;
    }

    sscanf(str, "%d", max);
}

int main(){
    char str[10];
    scanf("%s", str);

    int max, min, last, current;
    for(;;){
        sscanf(str, "%d", &last);
        rearrange(str, &max, &min);

        int current = max - min;

        if(current == last){
            break;
        }

        sprintf(str, "%d", current);
    }

    printf("%d\n", last);
}