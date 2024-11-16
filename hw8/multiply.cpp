#include<stdio.h>
#include<string.h>
void multiply(char* s1, char* s2, char* result){

    //倒转s1 s2保证低位是0开始, 方便程序运算
    for(int i=0;i<strlen(s1)/2;i++){
        char c=s1[i];
        s1[i]=s1[strlen(s1)-1-i];
        s1[strlen(s1)-1-i]=c;
    }

    for(int i=0;i<strlen(s2)/2;i++){
        char c=s2[i];
        s2[i]=s2[strlen(s2)-1-i];
        s2[strlen(s2)-1-i]=c;
    }


    int s1_ptr=0;
    int s2_ptr=0;
    for(s1_ptr=0; s1_ptr<strlen(s1); s1_ptr++){
        
        //一个数乘以s2
        char partial_result[100];
        int carry=0;
        for(s2_ptr=0; s2_ptr<strlen(s2); s2_ptr++){

            int n1=s1[s1_ptr]-'0';
            int n2=s2[s2_ptr]-'0';

            int npr=n1*n2+carry; // n partial result
            
            partial_result[s2_ptr]=(npr%10)+'0';
            carry=npr/10;

        }

        if(carry==0){
            partial_result[s2_ptr]='\0';
        }else{
            partial_result[s2_ptr]=carry+'0';
            partial_result[s2_ptr+1]='\0';
        }


        //partial result加到result中
        char* r1=result;
        r1+=s1_ptr; //偏移
        char* r2=partial_result;

        int ptr=0;
        carry=0;
        int max_len=strlen(r1)>strlen(r2)?strlen(r1):strlen(r2);

        for(ptr=0; ptr<max_len; ptr++){
            //超出补零
            int nr=ptr<strlen(r1)?r1[ptr]-'0':0;
            int npr=ptr<strlen(r2)?r2[ptr]-'0':0;

            int add=nr+npr+carry;

            r1[ptr]=(add%10)+'0';
            carry=add/10;
        }

        
        if(carry==0){
            r1[ptr]='\0';
        }else{
            r1[ptr]=carry+'0';
            r1[ptr+1]='\0';
        }
    }

    //倒转result保证人类可读
    for(int i=0;i<strlen(result)/2;i++){
        char c=result[i];
        result[i]=result[strlen(result)-1-i];
        result[strlen(result)-1-i]=c;
    }

}

int main(){
    char s1[50], s2[50];
    char result[100]={0};

    scanf("%s %s", s1, s2);

    multiply(s1, s2, result);

    printf("%s\n", result);
}