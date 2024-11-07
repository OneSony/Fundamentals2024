#include<stdio.h>

void my_inter(int n,int m,int* a,int* b){
    
    int ptr_a=0;
    int ptr_b=0;

    for(;;){
        if(ptr_a==n||ptr_b==m){
            break;
        }
        if(a[ptr_a]<b[ptr_b]){
            ptr_a++;
        }else if(a[ptr_a]>b[ptr_b]){
            ptr_b++;
        }else{
            printf("%d ",a[ptr_a]);
            ptr_a++;
            ptr_b++;
        }
    }

    printf("\n");
}

void my_union(int n,int m,int* a,int* b){
    
    int ptr_a=0;
    int ptr_b=0;

    for(;;){
        if(ptr_a==n||ptr_b==m){
            break;
        }
        if(a[ptr_a]<b[ptr_b]){
            printf("%d ",a[ptr_a]);
            ptr_a++;
        }else if(a[ptr_a]>b[ptr_b]){
            printf("%d ",b[ptr_b]);
            ptr_b++;
        }else{
            printf("%d ",a[ptr_a]);
            ptr_a++;
            ptr_b++;
        }
    }

    while(ptr_a<n){
        printf("%d ",a[ptr_a]);
        ptr_a++;
    }

    while(ptr_b<m){
        printf("%d ",b[ptr_b]);
        ptr_b++;
    }

    printf("\n");
}

void my_com(int n,int m,int* a,int* b){//A-B，输出A的元素
       
    int ptr_a=0;
    int ptr_b=0;

    for(;;){
        if(ptr_a==n||ptr_b==m){
            break;
        }
        if(a[ptr_a]<b[ptr_b]){
            printf("%d ",a[ptr_a]);
            ptr_a++;
        }else if(a[ptr_a]>b[ptr_b]){
            ptr_b++;
        }else{
            ptr_a++;
            ptr_b++;
        }
    }

    while(ptr_a<n){
        printf("%d ",a[ptr_a]);
        ptr_a++;
    }

    while(ptr_b<m){
        ptr_b++;
    }

    printf("\n");
}

int main(){
    int n,m;
    int a[2000];
    int b[2000];

    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }

    scanf("%d", &m);
    for(int i=0;i<m;i++){
        scanf("%d", &b[i]);
    }

    my_inter(n,m,a,b);

    my_union(n,m,a,b);

    my_com(n,m,a,b);
}