/* 1182번: 부분집합의 합 */

#include <cstdio>
using namespace std;

#define N 21
int n, s, cnt = 0;
int num[N];

void dfs(int k, int sum) {
	if (sum == s) cnt++;
	for (int i = k + 1; i < n; i++) 
		dfs(i, sum + num[i]);
}

int main() {
	scanf("%d %d", &n, &s);
    
	for (int i = 0; i < n; i++) 
		scanf("%d", &num[i]);

	for (int i = 0; i < n; i++) 
		dfs(i, num[i]);
	
	printf("%d\n", cnt);

	return 0;
}
