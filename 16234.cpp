/* 16234번: 인구 이동 */

#include <cstdio>
#include <math.h>
using namespace std;

#define N 101

int n, L, R;
int map[N][N];
int vst[N][N];
int average[N*N];
int cnt = 0;

int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { 1, 0, -1, 0 };

void numbering(int r, int c, int num) {
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
			if (vst[nr][nc] > 0) continue;
			int gap = abs(map[r][c] - map[nr][nc]);

			if (gap >= L && gap <= R) {
				cnt++, average[num] += map[nr][nc];
				vst[nr][nc] = num;
				numbering(nr, nc, num);
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &L, &R);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) 
			scanf("%d", &map[i][j]);
	}

	int ans = 0;

	while (1) {
		int num = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) 
				vst[i][j] = 0;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {

				if (vst[i][j] == 0) {
					for (int k = 0; k < 4; k++) {
						int nr = i + dr[k];
						int nc = j + dc[k];

						if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
							int gap = abs(map[i][j] - map[nr][nc]);

							if (gap >= L && gap <= R) {
								num++, cnt = 1, average[num] = map[i][j];
								vst[i][j] = num;
								numbering(i, j, num); /* 연합그룹 찾기 */
								average[num] = average[num] / cnt;

								break;
							}
						}
					}
				}
			}
		}

		if (num == 0) break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (vst[i][j] > 0) 
					map[i][j] = average[vst[i][j]];
			}
		}
		ans++;
	}

	printf("%d\n", ans);

	return 0;
}
