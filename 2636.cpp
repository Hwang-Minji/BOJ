/* 2636번: 치즈 */

#include <cstdio>
#include <vector>
using namespace std;

#define N 102
#define pi pair<int, int>

bool vst[N][N];
int map[N][N];
int n, m;
int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { 1, 0, -1, 0 };
int ans[N];
int cnt = 0;

void initVst() {
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= m + 1; j++) 
			vst[i][j] = false;
	}
}

void edgeCheck(int r, int c) {
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		
		if (map[nr][nc] == 1 && !vst[nr][nc]) {
			vst[nr][nc] = true;

			for (int j = 0; j < 4; j++) {
				int nnr = nr + dr[j];
				int nnc = nc + dc[j];

				if (map[nnr][nnc] == 3) {
					map[nr][nc] = 4;
					edgeCheck(nr, nc);
					break;
				}
			}
		}
	}
}

void dfs(int r, int c) {
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr >= 0 && nr <= n + 1 && nc >= 0 && nc <= m + 1) {
			if (map[nr][nc] != 1 && !vst[nr][nc]) {
				vst[nr][nc] = true;
				map[nr][nc] = 3;
				dfs(nr, nc);
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) cnt++;
		}
	}
	ans[0] = cnt;

	int s = 0;
	map[0][0] = 3;

	while (true) {
		initVst();
        vst[0][0] = true;
		dfs(0, 0);
	
		initVst();
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (map[i][j] == 1 && !vst[i][j]) {
					vst[i][j] = true;

					for (int k = 0; k < 4; k++) {
						if (map[i + dr[k]][j + dc[k]] == 3) {
							map[i][j] = 4;
							edgeCheck(i, j);
							break;
						}
					}
				}
			}
		}

		s++;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (map[i][j] == 4) {
					map[i][j] = 3;
					cnt--;
				}
			}
		}
		ans[s] = cnt;
		if (cnt <= 0) break;
	}

	printf("%d\n%d\n", s, ans[s - 1]);

	return 0;
}
