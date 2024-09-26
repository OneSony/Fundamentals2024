#include<stdio.h>
int main(){
    int space_count=0, return_count=0, other_count=0;

    char c;
    for(;;){
        c=getchar(); 
        if(c=='#'){
            break;
        }else if(c==' '){
            space_count++;
        }else if(c=='\n'){
            return_count++;
        }else{
            other_count++;
        }
    }

    printf("%d %d %d\n", space_count, return_count, other_count);
}