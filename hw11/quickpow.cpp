#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
unsigned long long mod;
unsigned long long quickpow(unsigned long long base, unsigned long long exp) {

	if (exp == 1) {
		return base % mod;
	}

	if (exp == 0) {
		return 1;
	}

	unsigned long long half = quickpow(base, exp/2);

	unsigned long long remain = 1;
	if (exp % 2 == 0) {
		remain = 1;
	}
	else {
		remain = base % mod;
	}
	
	return (half * half * remain) % mod;
}

int main() {
	unsigned long long base, exp;

	mod = 10007;

	scanf("%lld %lld", &base, &exp);

	printf("%lld\n", quickpow(base, exp));
}