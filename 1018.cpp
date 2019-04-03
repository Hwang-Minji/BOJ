/* 1018번: 체스판 다시 칠하기 */

#include <cstdio>
#include <queue>
using namespace std;

#define INF 2e9
#define N 51
#define M 8
#define W 0
#define B 1

struct pos {
	int r, c;
	int color;
};

int map[N][N];
int chess[M][M];
bool vst[M][M];
int n, m, sr, sc;
int MAX = -INF, MIN = INF;

int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };

void bfs() {
	int cnt = 0;
	queue<pos> q;

	vst[0][0] = true;
	chess[0][0] = map[sr][sc];
	q.push({ 0, 0, map[sr][sc] });

	while (!q.empty()) {
		int nr = q.front().r;
		int nc = q.front().c;
		int ncolor = q.front().color;

		q.pop();

		for (int i = 0; i < 4; i++) {
			nr = nr + dr[i];
			nc = nc + dc[i];
			ncolor = (ncolor + 1) % 2;

			if (nr < 0 || nr >= M || nc < 0 || nc >= M) continue;
			if (vst[nr][nc]) continue;
			if (sr + nr < 0 || sr + nr >= n || sc + nc < 0 || sc + nc >= m) continue;

			vst[nr][nc] = true;

			if (ncolor != map[sr + nr][sc + nc]) cnt++;
			chess[nr][nc] = ncolor;
			q.push({nr, nc, ncolor});
		}
	}

	if (cnt > MAX || cnt < MIN) {
		int subCnt = M*M - cnt;

		if (subCnt < cnt) MIN = subCnt, MAX = cnt;
		else MIN = cnt, MAX = subCnt;
	}
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char temp;
			scanf(" %c", &temp);

			if (temp == 'W') map[i][j] = W;
			else map[i][j] = B;
		}
	}

	for (int i = 0; i <= n - M; i++) {
		for (int j = 0; j <= m - M; j++) {
			sr = i, sc = j;

			for (int i = 0; i < M; i++) 
				for (int j = 0; j < M; j++) 
					vst[i][j] = false;
			
			bfs();
		}
	}

	printf("%d\n", MIN);

	return 0;
}
