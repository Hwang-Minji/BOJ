/* 2309번: 일곱 난쟁이 */

#include <cstdio>
#include <algorithm>
using namespace std;

#define N 9
#define M 100
int arr[N];
int ans[N];
bool flag = false;

void dfs(int cnt, int k, int sum) {
	if (sum > 100) return;
	if (cnt == 7) {
		if (sum == 100) {
			for (int i = 0; i < 7; i++) 
				printf("%d\n", arr[ans[i]]);
			flag = true;
		}
		return;
	}

	for (int i = k + 1; i < N; i++) {
		ans[cnt] = i;
		dfs(cnt + 1, i, sum + arr[i]);
		if (flag) return;
	}
}
int main() {
	for (int i = 0; i < N; i++) 
		scanf("%d", &arr[i]);

	sort(arr, arr + N);
	
	for (int i = 0; i + 7 <= N; i++) {
		dfs(1, i, arr[i]);
		if (flag) return 0;
	}
}
