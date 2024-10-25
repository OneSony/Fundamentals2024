#include<stdio.h>
int main(){
    //Ax=b

    double a[20][20]; //行列
    double b[20];

    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%lf", &a[i][j]);
        }
    }

    for(int i=0; i<n; i++){
        scanf("%lf", &b[i]);
    }

    //确保对角线上的元素尽量不为0
    for(int i=0;i<n;i++){
        if(a[i][i]==0){
            for(int j=i+1;j<n;j++){
                if(a[j][i]!=0){
                    for(int k=0;k<n;k++){//交换两行
                        double temp = a[i][k];
                        a[i][k] = a[j][k];
                        a[j][k] = temp;
                    }

                    //交换b
                    double temp = b[i];
                    b[i] = b[j];
                    b[j] = temp;
                    break;
                }
            }
        }
    }

    //高斯消去法
    for(int i=0;i<n;i++){ //第几行
        for(int j=0;j<i;j++){ //消掉前几列
            double m = a[i][j]/a[j][j];
            for(int k=0;k<n;k++){ //
                a[i][k] -= m*a[j][k];
            }

            b[i] -= m*b[j];
        }
    }

    //找解，已经是尽量上三角
    double x[20];

    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<n;j++){
            b[i] -= a[i][j]*x[j];
        }

        if(a[i][i]==0){
            printf("Error\n");
            return 0;
        }

        x[i] = b[i]/a[i][i];
    }

    for(int i=0;i<n;i++){
        printf("%.2lf\n", x[i]);
    }
}