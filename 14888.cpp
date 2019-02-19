/* 14888번: 연산자 끼워넣기 */

#include <cstdio>
using namespace std;

#define N 101
#define INF 2e9

int n;
int num[N], oper[N];
int MAX = -INF, MIN = INF;

void dfs(int cnt, int sum) {
	if (cnt == n) {
		MAX = sum > MAX ? sum : MAX;
		MIN = sum < MIN ? sum : MIN;
		return;
	}

	for (int i = 1; i <= 4; i++) {
		if (oper[i] > 0) {
			oper[i]--;

			if (i == 1) dfs(cnt + 1, sum + num[cnt]);
			else if (i == 2) dfs(cnt + 1, sum - num[cnt]);
			else if (i == 3) dfs(cnt + 1, sum * num[cnt]);
			else dfs(cnt + 1, sum / num[cnt]);

			oper[i]++;
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &num[i]);
	for (int i = 1; i <= 4; i++) scanf("%d", &oper[i]);
	
	dfs(1, num[0]);
	printf("%d\n%d\n", MAX, MIN);
	return 0;
}
