#include<stdio.h>

int day[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_count(int year){ //目的年份的1月1日距离1998年1月1日的天数
    int count=0;
    for(int i=1998;i<year;i++){
        if(i%4==0 && i%100!=0 || i%400==0){
            count+=366;
        }
        else{
            count+=365;
        }
    }
    //printf("%d\n",count);
    return count;
}

int main() {
    int year;
    scanf("%d", &year);
    int count = day_count(year);

    count+=12;//1月13日

    int leap_sign=0;
    if(year%4==0 && year%100!=0 || year%400==0){
        leap_sign=1;
    }


    for(int i=1;i<=12;i++){ //不可能加到12月, 但是i=12的时候是先输出, 在加和
        //printf("%d\n",count%7);
        if(count%7==1){ //星期五, 相对于1998年1月1日的星期四
            printf("%d-%02d-13\n",year,i);
        }
        count+=day[leap_sign][i];
    }


}