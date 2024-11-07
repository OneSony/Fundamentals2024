#include<stdio.h>
#include<string.h>

char* RegularPlural(char* word){
    
    if(word[strlen(word)-1] == 's' || word[strlen(word)-1] == 'x' || word[strlen(word)-1] == 'z' || (word[strlen(word)-2] == 'c' && word[strlen(word)-1] == 'h') || (word[strlen(word)-2] == 's' && word[strlen(word)-1] == 'h')){
        strcat(word, "es");
    }else if(word[strlen(word)-1] == 'y' && (word[strlen(word)-2] != 'a' && word[strlen(word)-2] != 'e' && word[strlen(word)-2] != 'i' && word[strlen(word)-2] != 'o' && word[strlen(word)-2] != 'u')){
        word[strlen(word)-1] = 'i';
        strcat(word, "es");
    }else{
        strcat(word, "s");
    }

    return word;
}

int main(){
    char word[100];
    scanf("%s", word);

    printf("%s\n", RegularPlural(word));
    return 0;
}