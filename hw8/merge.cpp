#include<stdio.h>
void merge(int *a, int *b , int m, int n, int *result){
    int a_ptr=0, b_ptr=0, result_ptr=0;

    for(;;){
        if(a_ptr==m || b_ptr==n){
            break;
        }

        if(a[a_ptr]<b[b_ptr]){
            result[result_ptr]=a[a_ptr];
            result_ptr++;
            a_ptr++;
        }else{
            result[result_ptr]=b[b_ptr];
            result_ptr++;
            b_ptr++;
        }
    }

    for(;a_ptr<m;){
        result[result_ptr]=a[a_ptr];
        result_ptr++;
        a_ptr++;
    }

    for(;b_ptr<n;){
        result[result_ptr]=b[b_ptr];
        result_ptr++;
        b_ptr++;
    }
}

int main(){
    int m,n;
    int a[40],b[40];

    scanf("%d", &m);
    for(int i=0;i<m;i++){
        scanf("%d", &a[i]);
    }

    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &b[i]);
    }

    int result[80];

    merge(a,b,m,n,result);
    for(int i=0;i<m+n;i++){
        printf("%d ", result[i]);
    }

    printf("\n");
}