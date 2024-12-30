#include<stdio.h>
#include<string.h>

int main() {
    char str[200];

    // 输入字符串
    scanf("%s", str);

    int dp[200][200] = { 0 }; //只能初始化成0
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++) {
            dp[i][j] = 200;
            if (i == j) {
                dp[i][j] = 0;
            }
        }
    }

    //扫过去

    for (int gap = 1; gap < strlen(str); gap++){
        for (int i = 0; i < strlen(str) - gap; i++) {
            if (str[i] == str[i + gap]) {
                if (gap == 1) {
                    dp[i][i + gap] = 0;
                }
                else {
                    dp[i][i + gap] = dp[i + 1][i + gap - 1];
                }
            }
            else {
                if (gap == 1) {
                    dp[i][i + gap] = 1;
                }
                else {
                    //printf("-%d %d %d %d\n", dp[i][i + gap], dp[i + 1][i + gap - 1] + 1, dp[i + 1][i + gap]+1, dp[i][i + gap - 1] + 1);
                    if (dp[i][i + gap] > dp[i + 1][i + gap - 1] + 1) {
                        dp[i][i + gap] = dp[i + 1][i + gap - 1] + 1;
                    }
                    if (dp[i][i + gap] > dp[i + 1][i + gap] + 1) {
                        dp[i][i + gap] = dp[i + 1][i + gap] + 1;
                    }
                    if (dp[i][i + gap] > dp[i][i + gap - 1] + 1) {
                        dp[i][i + gap] = dp[i][i + gap - 1] + 1;
                    }
                }
            }
            //printf("%c %c %d\n", str[i], str[i + gap], dp[i][i+gap]);
        }
    }

    printf("%d\n", dp[0][strlen(str) - 1]);
}
