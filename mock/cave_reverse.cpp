#include<stdio.h>
#include<stdlib.h>
 
int main(){
    unsigned long long max_value = ~0ULL;
    int size=1010;

    unsigned long long*** dp = (unsigned long long***)malloc(2 * (sizeof(unsigned long long**)));
    for(int i=0;i<2;i++){
        dp[i] = (unsigned long long**)malloc(size * (sizeof(unsigned long long*)));
        for(int j=0;j<size;j++){
            dp[i][j] = (unsigned long long*)malloc(size * (sizeof(unsigned long long)));
        }
    }

    int** A = (int**)malloc(size * (sizeof(int*)));
    for(int i=0;i<size;i++){
        A[i] = (int*)malloc(size * (sizeof(int)));
    }

    int** map = (int**)malloc(size * (sizeof(int*)));
    for(int i=0;i<size;i++){
        map[i] = (int*)malloc(size * (sizeof(int)));
    }
    
    int*** reachable = (int***)malloc(2 * (sizeof(int**)));
    for(int i=0;i<2;i++){
        reachable[i] = (int**)malloc(size * (sizeof(int*)));
        for(int j=0;j<size;j++){
            reachable[i][j] = (int*)malloc(size * (sizeof(int)));
        }
    }
 
    int n, m, h, p;
 
    scanf("%d %d", &n, &m);
    for(int i=n;i>=1;i--){
        for(int j=m;j>=1;j--){
            scanf("%d", &A[i][j]);
        }
    }
    
 
    scanf("%d", &h);
    for(int i=0;i<h;i++){
        int x, y;
        scanf("%d %d", &x, &y);
        map[n-x+1][m-y+1]=1; //陷阱
    }
 
    scanf("%d", &p);
    for(int i=0;i<p;i++){
        int x, y;
        scanf("%d %d", &x, &y);
        map[n-x+1][m-y+1]=-1; //防具
    }


    for(int j=0;j<=m;j++){
        for(int k=0;k<h+1;k++){
            reachable[0][j][k]=-4; //从没到过
            reachable[1][j][k]=-4;
            dp[0][j][k]=max_value;
            dp[1][j][k]=max_value;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){

            if(i==1 && j==1){
                dp[1][j][0]=A[i][j];
                reachable[1][j][0]=0;
                continue;
            }

            for(int k=0;k<h+1;k++){
                int target_h;
                if(map[i][j]==1){ //陷阱
                    if(k==0){
                        reachable[1][j][k]=-2;
                        continue;
                    }
                    target_h=k-1;
                }else if(map[i][j]==-1){
                    //如果k是0的话，也可以来自k
                    if(k==0){
                        target_h=k;
                        if(reachable[0][j][target_h]==0){
                            if(dp[1][j][k]>dp[0][j][target_h]+A[i][j]){
                                dp[1][j][k]=dp[0][j][target_h]+A[i][j];
                                reachable[1][j][k]=0;
                            }
                        }
                        if(reachable[1][j-1][target_h]==0){
                            if(dp[1][j][k]>dp[1][j-1][target_h]+A[i][j]){
                                dp[1][j][k]=dp[1][j-1][target_h]+A[i][j];
                                reachable[1][j][k]=0;
                            }
                        }
                        
                        if(!(reachable[0][j][target_h]==0 || reachable[1][j-1][target_h]==0)){
                            if(reachable[1][j][k]==-4){
                                reachable[1][j][k]=-2;
                            }
                        }
                    }
                    target_h=k+1;
                    if(target_h>h){
                        target_h=h; //TODO ?
                    }
                }else{
                    target_h=k;
                }


                if(reachable[0][j][target_h]==0){
                    if(dp[1][j][k]>dp[0][j][target_h]+A[i][j]){
                        dp[1][j][k]=dp[0][j][target_h]+A[i][j];
                        reachable[1][j][k]=0;
                    }
                }
                if(reachable[1][j-1][target_h]==0){
                    if(dp[1][j][k]>dp[1][j-1][target_h]+A[i][j]){
                        dp[1][j][k]=dp[1][j-1][target_h]+A[i][j];
                        reachable[1][j][k]=0;
                    }
                }
                
                //printf("--a:%d %d\n", reachable[0][j][target_h], reachable[1][j-1][target_h]);
                if(!(reachable[0][j][target_h]==0 || reachable[1][j-1][target_h]==0)){
                    //printf("--in\n");
                    if(reachable[1][j][k]==-4){
                        reachable[1][j][k]=-2;
                    }
                }

                //printf("x=%d y=%d k=%d target_k=%d dp=%d a=%d\n", i, j, k, target_h, dp[1][j][k], reachable[1][j][k]);

            }

        }

        //初始化都是-2！！！
        if(i==n){
            break;
        }
        for(int j=0;j<=m;j++){
            for(int k=0;k<h+1;k++){
                dp[0][j][k]=dp[1][j][k];
                reachable[0][j][k]=reachable[1][j][k];
                reachable[1][j][k]=-4;
                dp[1][j][k]=max_value;
            }
        }
    }


    if(reachable[1][m][0]!=0){
        printf("failed\n");
    }else{
        printf("%lld\n", dp[1][m][0]);
    }
}