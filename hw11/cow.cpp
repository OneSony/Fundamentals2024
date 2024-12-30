#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//BFS记得减枝！

struct Node {
	int pos;
	int deep;
};

int main() {

	Node* queue = (Node*)malloc(20000000 * sizeof(Node));
	Node* ptr = queue;
	bool flag[210000] = { 0 }; //注意位置可能翻倍！！！！
	unsigned long long len = 0;

	int n, k;
	scanf("%d %d", &n, &k);

	if (n > k) {
		printf("%d\n", n - k);
		return 0;
	}

	ptr->pos = n;
	ptr->deep = 0;
	ptr++;
	flag[n] = 1;

	for (;;) {
		
		//pop
		Node now = queue[0];

		for (Node* p = queue;p!=(ptr-1);p++){
			*p = *(p + 1);
		}
		ptr--;


		if (now.pos == k) {
			printf("%d\n", now.deep);
			break;
		}

		//不能单纯从出来的点判断，因为这个点要走的点可能被别的点走过
        //这个点走过，三种情况的点一定走过
        //这个点没走过，不代表三种情况的点一定没走过，所以每种里面单独判断更好减枝
        //入队之前看一下检查走没走过

		//if (flag[now.pos] == false) {

			//push
			if (now.pos < k && flag[now.pos + 1] == 0) {
				ptr->pos = now.pos + 1;
				ptr->deep = now.deep + 1;
				flag[now.pos + 1] = 1;
				ptr++;
			}

			if (now.pos > 0 && flag[now.pos - 1] == 0) {
				ptr->pos = now.pos - 1;
				ptr->deep = now.deep + 1;
				flag[now.pos - 1] = 1;
				ptr++;
			}

			if (now.pos != 0 && now.pos < k && flag[now.pos * 2] == 0) {
				ptr->pos = now.pos * 2;
				ptr->deep = now.deep + 1;
				flag[now.pos * 2] = 1;
				ptr++;
			}

			//flag[now.pos] = true;
		//}
	}

}
