/* 2606번: 바이러스 */

#include <cstdio>
using namespace std;

#define N 101
int n, m, cnt = 0;
bool adj[N][N];
bool vst[N];

void dfs(int node) {
	for (int i = 1; i <= n; i++) {
		if (adj[node][i] && !vst[i]) {
			vst[i] = true;
			cnt++;
			dfs(i);
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);

		adj[u][v] = true;
		adj[v][u] = true;
	}

	vst[1] = true;
	dfs(1);
	printf("%d\n", cnt);

	return 0;
}
