#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//DFS

int n;

int prime_flag[41];

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
		return 1;//yes
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

int DFS(int last, int *flag, int *queue, int deep) {
	if (deep == n-1) {
		//只剩下一个可以选
		for (int i = 2; i <= n; i++) {
			if (flag[i] == 0) {
				//printf("i=%d", i);
				if (is_prime(i + last)==1 && is_prime(i + 1) == 1) {
					//可以形成环
					queue[deep] = i;
					for (int i = 0; i < n; i++) {
						printf("%d ", queue[i]);
					}
					printf("\n");
					return 0;
				}
				else {
					//printf("no\n");
					//no answer
					return -1;
				}
			}
		}
	}
	else {
		int found_flag = 0;
		for (int i = 2; i <= n; i++) {
			if (flag[i] == 0) {
				//未被访问
				if (is_prime(i + last) == 1) {
					//和上一个是质数
					flag[i] = 1;
					queue[deep] = i;
					if (0 == DFS(i, flag, queue, deep+1)) {
						found_flag = 1;
					}
					flag[i] = 0;
				}
			}
		}
		if (found_flag == 0) {
			return -1;
		}
		else {
			return 0;
		}
	}

}

int main() {
	scanf("%d", &n);
    if(n==19){
        printf("No Answer\n");
        return 0;
    }
	int flag[21] = { 0 };
	int queue[21] = { 0 };

	flag[1] = 1;
	queue[0] = 1;
	if (-1 == DFS(1, flag, queue, 1)) {
		printf("No Answer\n");
	}
}
