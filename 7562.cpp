/* 7562번: 나이트의 이동 */

#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define pi pair<int, int>
#define N 302
#define INF 2e9

int n, d[N][N];
int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
queue<pi> q;

void bfs(pi s, pi f) {
	q.push(s);
	d[s.first][s.second] = 0;

	while (!q.empty()) {
		s = q.front();
		int cnt = d[s.first][s.second];
		q.pop();

		for (int i = 0; i < 8; i++) {
			pi ns = { s.first + dx[i], s.second + dy[i] };
			if (ns.first >= 0 && ns.first < n && ns.second >= 0 && ns.second < n && d[ns.first][ns.second] == INF) {
				d[ns.first][ns.second] = cnt + 1;
				q.push(ns);
			}
		}

		if (d[f.first][f.second] != INF) break;
	}
}

int main() {
	int tc;
	scanf("%d", &tc);

	for (int T = 1; T <= tc; T++) {
		int x1, y1, x2, y2;
		scanf("%d", &n);
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		while (!q.empty()) q.pop();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) d[i][j] = INF;

		bfs({ x1, y1 }, { x2, y2 });
		printf("%d\n", d[x2][y2]);
	}

	return 0;
}
