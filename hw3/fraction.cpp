#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);

    if(n==1){
        printf("2.00\n");
        return 0;
    }


    int seq[3];
    seq[0]=1;
    seq[1]=2;
    seq[2]=seq[0]+seq[1];

    double result=2/1;
    
    for(int i=2; i<=n; i++){
        result+=double(seq[2])/double(seq[1]);
        //printf("i: %d, %d/%d\n", i, seq[2], seq[1]);
        seq[0]=seq[1];
        seq[1]=seq[2];
        seq[2]=seq[0]+seq[1];
    }

    printf("%.2lf\n", result);
}