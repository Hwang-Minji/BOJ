/* 15684번: 사다리 조작 */

#include <cstdio>
#include <vector>
using namespace std;

#define pi pair<int, int>
#define pb pair<bool, bool>
#define N 12
#define H 32

pb map[H][N];
int n, h, m, MIN = 4;

bool run(int s, int r ,int c) {
	if (r > h) {
		if (s == c) return true;
		else return false;
	}
	if (map[r][c].first) run(s, r + 1, c - 1);
	else if (map[r][c].second) run(s, r + 1, c + 1);
	else run(s, r + 1, c);
}

void dfs(int cnt, int r, int c) {
	if (cnt >= MIN || MIN == 0) return;

	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (!run(i, 1, i)) break; 
		else count++;
	}
	if (count == n) {
		MIN = cnt;
		return;
	}
	
	int j = c;
	for (int i = r; i <= h; i++) {
		while (j < n) {
			if (map[i][j].first || map[i][j].second || map[i][j + 1].second) {
				j++; 
                continue;
			}
			pi temp = { i, j };

			map[i][j].second = true;
			map[i][j + 1].first = true;
			dfs(cnt + 1, i, j + 2);
            
			map[temp.first][temp.second].second = false;
			map[temp.first][temp.second + 1].first = false;
			j++;
		}

		j = 1;
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &h);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		map[a][b].second = true;
		map[a][b + 1].first = true;
	}
	
	dfs(0, 1, 1);
	if (MIN == 4) printf("-1\n");
	else printf("%d\n", MIN);

	return 0;
}
