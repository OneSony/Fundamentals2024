#include<stdio.h>
#include<stdlib.h>
//worked
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
 
    int n, m, k, p;
 
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d", &A[i][j]);
        }
    }
 
    scanf("%d", &k);
    for(int i=0;i<k;i++){
        int x, y;
        scanf("%d %d", &x, &y);
        map[x][y]=1; //陷阱
    }
 
    scanf("%d", &p);
    for(int i=0;i<p;i++){
        int x, y;
        scanf("%d %d", &x, &y);
        map[x][y]=-1; //防具
    }

    p=40;

    int cave_num=20;


    for(int j=0;j<=m;j++){
        for(int k=0;k<p+1;k++){
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

            for(int k=0;k<p+1;k++){

                int target_k;
                if(map[i][j]==1){ //陷阱
                    if(k==p){
                        reachable[1][j][k]=-2;
                        continue;
                    }
                    target_k=k+1;
                }else if(map[i][j]==-1){
                    if(k==0){
                        reachable[1][j][k]=-2;
                        continue;
                    }
                    target_k=k-1;
                }else{
                    target_k=k;
                }

                if(target_k>=cave_num){
                    reachable[1][j][k]=-2;
                    continue;
                }

                if(reachable[0][j][target_k]==-4 && reachable[1][j-1][target_k]==-4){
                    //没到过，跳过这个k？
                    break;
                }

                if(reachable[0][j][target_k]==0){
                    if(dp[1][j][k]>dp[0][j][target_k]+A[i][j]){
                        dp[1][j][k]=dp[0][j][target_k]+A[i][j];
                        reachable[1][j][k]=0;
                    }
                }
                if(reachable[1][j-1][target_k]==0){
                    if(dp[1][j][k]>dp[1][j-1][target_k]+A[i][j]){
                        dp[1][j][k]=dp[1][j-1][target_k]+A[i][j];
                        reachable[1][j][k]=0;
                    }
                }
                
                if(!(reachable[0][j][target_k]==0 || reachable[1][j-1][target_k]==0)){
                    reachable[1][j][k]=-2;
                }

                //printf("x=%d y=%d k=%d target_k=%d dp=%d a=%d\n", i, j, k, target_k, dp[1][j][k], reachable[1][j][k]);


                if(k>=cave_num){
                    //额外考虑从隔壁的顶层来的途径
                    if(reachable[0][j][k]==0){
                        if(dp[1][j][k]>dp[0][j][k]+A[i][j]){
                            dp[1][j][k]=dp[0][j][k]+A[i][j];
                            reachable[1][j][k]=0;
                        }
                    }
                    if(reachable[1][j-1][k]==0){
                        if(dp[1][j][k]>dp[1][j-1][k]+A[i][j]){
                            dp[1][j][k]=dp[1][j-1][k]+A[i][j];
                            reachable[1][j][k]=0;
                        }
                    }
                    
                    if(!(reachable[0][j][k]==0 || reachable[1][j-1][k]==0)){
                        if(reachable[1][j][k]==-4){
                            reachable[1][j][k]=-2;
                        }
                    }

                    //printf("--x=%d y=%d k=%d dp=%d a=%d\n", i, j, k, dp[1][j][k], reachable[1][j][k]);

                    break;
                }
            }

        }

        //初始化都是-2！！！
        if(i==n){
            break;
        }
        for(int j=0;j<=m;j++){
            for(int k=0;k<p+1;k++){
                dp[0][j][k]=dp[1][j][k];
                reachable[0][j][k]=reachable[1][j][k];
                reachable[1][j][k]=-4;
                dp[1][j][k]=max_value;
            }
        }
    }

    unsigned long long min_dp=max_value;
    int find_flag=0;

    for(int k=0;k<=cave_num;k++){
        //printf("k=%d dp=%d a=%d\n", k, dp[1][m][k], reachable[1][m][k]);
        if(reachable[1][m][k]==0){
            if(dp[1][m][k]<min_dp){
                min_dp=dp[1][m][k];
                find_flag=1;
            }
        }else if(reachable[1][m][k]==-4){
            break;
        }
    }

    if(find_flag==0){
        printf("failed");
    }else{
        printf("%lld\n", min_dp);
    }
}