#include<stdio.h>
int main(){
    int type;
    double income;

    scanf("%d %lf", &type, &income);

    double levels[5]={0, 17850, 23900, 29750, 14875}; // 0占位

    
    double basic_part=(income>=levels[type]?levels[type]:income);
    double exceeded_part=income-basic_part;

    printf("%.6lf\n",basic_part*0.15+exceeded_part*0.28);
    

}