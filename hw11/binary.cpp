#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
    //(a+b)%p = (a%p + b%p)%p

	unsigned long long dp[200][2];
	int n;

	scanf("%d", &n);

	dp[1][0] = 0;
	dp[1][1] = 0;

	dp[2][0] = 0;
	dp[2][1] = 1;

	unsigned long long pow = 2;
	unsigned long long mod = 1000000007;

	for (int i = 3; i <= n; i++) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1])%mod;
		dp[i][1] = (dp[i - 1][0] + pow)%mod;

		//i=3时，pow是2的1次方
		pow = (pow * 2)%mod;
	}

	printf("%lld\n", (dp[n][0] + dp[n][1])%mod);
}
