#include<stdio.h>
#include<string.h>
int main(){
    char str[110];
    char map[110][110];

    fgets(str, 110, stdin);

    int ptr=0;

    char word[110];
    int size=0;
    int num;
    for(;;){
        if(ptr>=strlen(str)){
            break;
        }
        if(-1==sscanf(str+ptr, "%s", word)){
            break;
        }
        ptr+=strlen(word)+1;
        //printf("::%d\n", ptr);
        //printf("%s\n", word);

        int found=0;
        for(int i=0;i<size;i++){
            if(0==strcmp(word, map[i])){
                found=1;
                break;
            }
        }

        if(!found){
            strcpy(map[size], word);
            size++;
        }

    }

    printf("%d\n", size);
}
