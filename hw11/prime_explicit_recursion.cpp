#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// DFS

int n;
int prime_flag[41];
int is_printed=0;

// 判断是否为质数
int is_prime(int num) {
    if (prime_flag[num] == 1) {
        return 1;
    }
    if (prime_flag[num] == -1) {
        return 0;
    }
    if (num == 1) {
        prime_flag[num] = -1;
        return 0;
    }
    if (num == 2) {
        prime_flag[num] = 1;
        return 1;  // yes
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            prime_flag[num] = -1;
            return 0;
        }
    }
    prime_flag[num] = 1;
    return 1;
}

// 显式递归栈实现DFS
int DFS() {
    int stuck[21];
    int flag[21] = {0};
    int top_ptr=0;
    int status[21][21] = {0};

    stuck[top_ptr] = 1;
    top_ptr++;
    flag[1] = 1;

    while(1){

        //清空top_str上部的status
        for(int i=top_ptr+1;i<top_ptr+2;i++){
            for(int j=0;j<=n;j++){
                status[i][j] = 0;
            }
        }


        /*printf("top_ptr=%d\n", top_ptr);
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                printf("%d ", status[i][j]);
            }
            printf("\n");
        }

        printf("stuck:");
        for(int i=0;i<top_ptr;i++){
            printf("%d ", stuck[i]);
        }
        printf("\n");*/

        int found_flag=0;
        for(int i=2;i<=n;i++){
            if(flag[i]!=0){
                continue;
            }
            if(status[top_ptr][i]==1){
                continue;
            }//要清空
            status[top_ptr][i] = 1;
            if(is_prime(i+stuck[top_ptr-1])==1){
                found_flag=1;
                stuck[top_ptr] = i;
                top_ptr++;
                flag[i] = 1;
                if(top_ptr==n){
                    //找到了一个
                    if(is_prime(stuck[top_ptr-1]+1)==0){
                        //不是质数
                        top_ptr--;
                        flag[stuck[top_ptr]] = 0;
                        continue;
                    }
                    for(int i=0;i<n;i++){
                        printf("%d ", stuck[i]);
                    }
                    printf("\n");
                    is_printed = 1;
                    top_ptr--;
                    flag[stuck[top_ptr]] = 0;
                    continue;
                }
                break;
            }
        }
        if(found_flag==0){
            //printf("no\n");
            //没有找到
            top_ptr--;
            flag[stuck[top_ptr]] = 0;
            if(top_ptr==0){
                return 0;
            }
        }
    }
}

int main() {
    scanf("%d", &n);

    DFS();

    if(is_printed==0){
        printf("No Answer\n");
    }

    return 0;
}
