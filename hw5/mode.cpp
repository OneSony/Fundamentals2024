#include<stdio.h>
int main(){
    int n;
    int a[100];

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    int count=1;
    int max_count=1;
    int max_member=a[0];

    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]){
            count++;
        }else{
            count=1;
        }

        if(count>max_count){
            max_count=count;
            max_member=a[i];
        }
    }

    printf("%d\n",max_member);
}