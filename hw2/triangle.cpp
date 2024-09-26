#include<stdio.h>
#include<math.h>
int main(){
    double a,b,c;

    scanf("%lf %lf %lf",&a,&b,&c);

    double m;

    m=a>b?a:b;
    m=m>c?m:c;

    if(a+b+c-m>m){ //所有边减去最大边就是剩余的两边
        double p=(a+b+c)/2;
        double s=sqrt(p*(p-a)*(p-b)*(p-c));

        printf("%.6lf\n",(2*s)/m);
    }else{
        printf("NO\n");
    }
}