/* 13460번: 구슬 탈출 2 */

#include <cstdio>
#include <vector>
using namespace std;

#define N 11
#define pi pair<int, int>

char map[N][N];
int n, m, MIN = 11;
pi r, b, o;

int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { 1, 0, -1, 0 };

pi run(pi p, int i) {
	while (true) {
		if (map[p.first + dr[i]][p.second + dc[i]] == 'O') 
			return { p.first + dr[i], p.second + dc[i] };
		if (map[p.first + dr[i]][p.second + dc[i]] != '.')
			return { p.first, p.second };
		else
			p.first += dr[i], p.second += dc[i];
	}
}

void setMap(pi s, pi f, char color) {
	map[s.first][s.second] = '.';
	map[f.first][f.second] = color;
}

void dfs(int cnt, int pass, bool flag) {
	if (cnt >= MIN) return;
	if (flag) {
		MIN = cnt;
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (pass == i) continue;
		pi tr = r, tb = b;

		if ((i == 0 && r.second < b.second) ||
			(i == 1 && r.first < b.first) ||
			(i == 2 && r.second > b.second) ||
			(i == 3 && r.first > b.first)) {

			b = run(b, i);
			if (b == o) {
				b = tb;
				continue;
			}

			setMap(tb, b, 'B');
			r = run(r, i);
			if (r == tr && b == tb) continue;

			if (r == o) {
				map[tr.first][tr.second] = '.';
				dfs(cnt + 1, (i + 2) % 4, !flag); //재귀
			}
			else {
				setMap(tr, r, 'R');
				dfs(cnt + 1, (i + 2) % 4, flag); // 재귀
				setMap(r, tr, 'R');
			}
			
			setMap(b, tb, 'B');
			r = tr, b = tb;
		}

		else {
			r = run(r, i);
			if (r == o) map[tr.first][tr.second] = '.';
			else setMap(tr, r, 'R');

			b = run(b, i);

			if (r == tr && b == tb) continue;
			if (b == o) {
				if (r == o) {
					setMap(r, tr, 'R');
					map[o.first][o.second] = 'O';
				}
				else setMap(r, tr, 'R');
				r = tr, b = tb;
				continue;
			}

			setMap(tb, b, 'B');
			if (r == o) {
				dfs(cnt + 1, (i + 2) % 4, !flag); //재귀
				map[o.first][o.second] = 'O';
			}
			else {
				dfs(cnt + 1, (i + 2) % 4, flag); //재귀
				setMap(r, tr, 'R');
			}
			setMap(b, tb, 'B');
			r = tr, b = tb;
		}
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'R') r = { i,j };
			if (map[i][j] == 'B') b = { i,j };
			if (map[i][j] == 'O') o = { i,j };
		}
	}

	dfs(0, 4, false);
	if (MIN == 11) printf("-1\n");
	else printf("%d\n", MIN);

	return 0;
}
