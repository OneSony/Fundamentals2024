#include<stdio.h>

int main(){
    double sale, rate;

    scanf("%lf %lf", &sale, &rate);
    printf("%.2lf\n", sale*rate);
}