#include<stdio.h>
int main(){
    int a[1001];

    int n;
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    int temp;
    int flag=0;//交换为1
    for(int x=0;x<n;x++){ //计次
        flag=0;

        for(int y=0;y<n-1-x;y++){

            if(a[y]>a[y+1]){ //把大的放在后面
                temp=a[y];
                a[y]=a[y+1];
                a[y+1]=temp;
                flag=1;
            }
        }

        if(flag==0){
            break;
        }

    }

    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
}