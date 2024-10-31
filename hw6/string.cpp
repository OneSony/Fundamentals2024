#include<stdio.h>
#include<string.h>
int main(){
    int alaphbat[26+26] = {0};

    char str[200];
    scanf("%s", str);

    for(int i=0; i<strlen(str); i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            alaphbat[str[i]-'a']++;
        }else if(str[i] >= 'A' && str[i] <= 'Z'){
            alaphbat[str[i]-'A'+26]++;
        }
    }

    for(int i=0; i<26; i++){
        if(alaphbat[i]%2==1){
            printf("%c\n", 'a'+i);
            return 0;
        }
    }

    for(int i=26; i<26+26; i++){
        if(alaphbat[i]%2==1){
            printf("%c\n", 'A'+i-26);
            return 0;
        }
    }
}