#include<stdio.h>
int main(){
    char word[2][100];

    int alaphabat[2][26]={0};

    scanf("%s", word[0]);
    scanf("%s", word[1]);

    for(int n=0;n<2;n++){
        for(int i=0;i<100;i++){
            if(word[n][i]=='\0'){
                break;
            }
            if(word[n][i]>'a'&&word[n][i]<'z'){
                alaphabat[n][word[n][i]-'a']++;
            }else if(word[n][i]>'A'&&word[n][i]<'Z'){
                alaphabat[n][word[n][i]-'A']++;
            }
        }
    }

    for(int i=0;i<26;i++){
        if(alaphabat[0][i]!=alaphabat[1][i]){
            printf("no\n");
            return 0;
        }
    }

    printf("yes\n");
}