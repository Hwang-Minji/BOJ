/* 4963번: 섬의 개수 */

#include <cstdio>
using namespace std;

#define N 52

bool map[N][N];
int n, m, cnt;
int dr[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dc[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void dfs(int r, int c) {
	map[r][c] = false;

	for (int i = 0; i < 8; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (map[nr][nc]) dfs(nr, nc);
	}
}

int main() {
	while (true) {
		scanf("%d %d", &m, &n);
		if (m == 0 && n == 0) break;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) 
				scanf("%d", &map[i][j]);
		}
		cnt = 0;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (map[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}

	return 0;
}
