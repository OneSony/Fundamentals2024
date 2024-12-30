#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
    int n, m;
    int need[600];
    int value[600];

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &need[i], &value[i]);
    }

    unsigned long long *dp [600];

    for (int i = 0; i < 600; i++) {
        dp[i] = (unsigned long long*)malloc((m+1) * sizeof(unsigned long long));
        for (int j = 0; j <= m; j++) {
            dp[i][j] = 0;
        }
    }


    //dp [n][用了多少]

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (dp[i][j] < dp[i - 1][j] + 0) { //不拿
                dp[i][j] = dp[i - 1][j] + 0;
            }
            if (j - need[i - 1] >= 0 && dp[i][j] < dp[i - 1][j - need[i - 1]] + value[i-1]) { //拿i
                dp[i][j] = dp[i - 1][j - need[i - 1]] + value[i - 1];
            }
        }
    }

    /*for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            printf("%lld ", dp[i][j]);
        }
        printf("\n");
    }*/

    unsigned long long max_value = 0;

    for (int j = 0; j <= m; j++) {
        if (dp[n][j] > max_value) {
            max_value = dp[n][j];
        }
    }
    printf("%lld\n", max_value);
}
