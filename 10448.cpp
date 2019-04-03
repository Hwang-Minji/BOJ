/* 10448번: 유레카 이론 */

#include <cstdio>
using namespace std;

#define N 1001
#define M 3

int n, l, cnt;
int num[N];
bool check[N];

void init() {
	num[1] = 1;

	for (int i = 2; i < N ; i++) {
		int temp = num[i - 1] + i;
		if (temp >= N) return;

		num[i] = temp;
		l = i;
	}
}

void cal(int cnt, int sum) {
	if (sum >= N) return;
	if (cnt == M) {
		check[sum] = true;
		return;
	}

	for (int i = 1; i <= l; i++) {
		cal(cnt + 1, sum + num[i]);
	}
}

int main() {
	int tc;
	scanf("%d", &tc);

	init();
	cal(0, 0);

	for (int T = 1; T <= tc; T++) {
		scanf("%d", &n);
		printf("%d\n", check[n]);
	}

	return 0;
}
