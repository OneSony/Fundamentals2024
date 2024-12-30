#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {

	char input[500];
	char* input_ptr = input;
	int n;
	int seq[6000];

	fgets(input_ptr, 500, stdin);

	for (int i = 0; i < 200; i++) {
		int char_num;
		char tmp[200];
		sscanf(input_ptr, "%[^ \n]%n", tmp, &char_num);
		sscanf(tmp, "%d", &seq[i]);
		//printf("%d %d %d\n", i, seq[i], char_num);
		input_ptr += char_num;
		if (*input_ptr == '\n') {
			n = i + 1;
			break;
		}
		input_ptr++;//跳过空格
	}

	/*scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &seq[i]);
	}*/


	unsigned long long* dp = (unsigned long long*)malloc(n * sizeof(unsigned long long));

	for (int i = 0; i < n; i++) {
		dp[i] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (seq[i] > seq[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
	}

	//遍历各种结尾的情况，选最大
	unsigned long long max_value = 1;
	for (int i = 0; i < n; i++) {
		if (dp[i] > max_value) {
			max_value = dp[i];
		}
	}
	printf("%lld\n", max_value);
}
