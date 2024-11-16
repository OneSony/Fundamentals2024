#include<stdio.h>
#include<string.h>
void strcompress(char *s){
    int tbl[30]={0}; //字符计数, 只有小写字母

    int ptr=0;

    for(int i=0;i<strlen(s);i++){
        if(s[i]==' '){
            s[ptr]=s[i];
            ptr++;
            continue;
        }

        tbl[s[i]-'a']++;

        if(tbl[s[i]-'a']==1 || tbl[s[i]-'a']==3 || tbl[s[i]-'a']==6){
            s[ptr]=s[i];
            ptr++;
            continue;
        }

        // 其他的字符不操作
    }

    s[ptr]='\0';

}

int main(){
    char s[1100];

    fgets(s, 1100, stdin);
    strcompress(s);

    printf("%s", s);
}