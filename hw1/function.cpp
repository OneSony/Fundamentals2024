#include<stdio.h>
#include<math.h>

int main(){
    double a, b, c;

    scanf("%lf %lf %lf", &a, &b, &c);

    double delta;

    delta=b*b-4*a*c;

    if(delta>0){
        printf("%.6lf\n%.6lf\n", (-b+sqrt(delta))/(2*a), (-b-sqrt(delta))/(2*a));
    }else if(delta==0){
        printf("%.6lf\n", (-b+sqrt(delta))/(2*a));
    }else{
        printf("Error\n");
    }
}