/* 15683번: 감시 */

#include <cstdio>
#include <vector>
using namespace std;

#define pi pair<int, int>
#define N 9

int n, m, MIN = 200;
int map[N][N];
vector<pi> list, pos;
int maxDist[6] = { 0, 4, 2, 4, 4, 1 };
int camera[6][5] = { {0, 0, 0, 0, 0}, {0, 1, 2, 4, 8}, {0, 5, 10, 0 , 0}, {0, 3, 6, 12, 9}, {0, 7, 14, 13, 11}, {0, 15, 0, 0, 0} };
int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { 1, 0, -1, 0 };

void run() {
	bool vst[N][N] = { false, };
	
	for (int i = 0; i < list.size(); i++) {
		for (int j = 0; j < 4; j++) {
			if (camera[list[i].first][list[i].second] & (1 << j)) {
				int r = pos[i].first, c = pos[i].second;

				while (true) {
					if (r < 0 || r > n || c < 0 || c > m) break;
					if (map[r][c] == 6) break;
					vst[r][c] = true;
					r += dr[j], c += dc[j];
				}
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) 
			if (!vst[i][j] && map[i][j] == 0) cnt++;
	}

	if (MIN > cnt) MIN = cnt;
}

void dfs(int cnt) {
	if (cnt == list.size()) {
		run();
		return;
	}

	for (int i = 1; i <= maxDist[list[cnt].first]; i++) {
		list[cnt].second = i;
		dfs(cnt + 1);
	}
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);

			if (map[i][j] >= 1 && map[i][j] <= 5) {
				list.push_back({ map[i][j], 1 });
				pos.push_back({ i,j });
			}
		}
	}

	dfs(0);
	printf("%d\n", MIN);

	return 0;
}
