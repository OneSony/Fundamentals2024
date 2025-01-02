#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

unsigned long long mod = 10007;

struct matrix {
	unsigned long long a;
	unsigned long long b;
	unsigned long long c;
	unsigned long long d;
};

matrix multiply(matrix a, matrix b) {
	matrix result;

	result.a = (((a.a * b.a) % mod) + (a.b * b.c) % mod) % mod;
	result.b = (((a.a * b.b) % mod) + (a.b * b.d) % mod) % mod;
	result.c = (((a.c * b.a) % mod) + (a.d * b.c) % mod) % mod;
	result.d = (((a.c * b.b) % mod) + (a.d * b.d) % mod) % mod;

	return result;
}

matrix quickpow(matrix base, unsigned long long exp) {

	if (exp == 1) {
		return base; //已mod
	}

	if (exp == 0) {
		matrix m;
		m.a = 1;
		m.b = 0;
		m.c = 0;
		m.d = 1;
		return m;
	}

	matrix half = quickpow(base, exp/2); //已mod

	matrix remain;
	if (exp % 2 == 0) {
		remain.a = 1;
		remain.b = 0;
		remain.c = 0;
		remain.d = 1;
	}
	else {
		remain = base;
	}
	
	return multiply(multiply(half, half), remain);
}

int main() {
	unsigned long long n;

	matrix base;
	base.a = 1;
	base.b = 1;
	base.c = 1;
	base.d = 0;

	scanf("%lld", &n);

	printf("%lld\n", quickpow(base, n-1).a);
}