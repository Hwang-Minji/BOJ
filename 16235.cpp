/* 16235번: 나무 재테크 */

#include <cstdio>
#include <vector>
using namespace std;

#define N 11

struct Tree {
	int age;
	bool dead;
};

struct Block {
	vector<Tree> tree;
	int treeCnt = 0;
	int food = 5;
};

Block map[N][N];
int A[N][N];
int n, m, k;
int totalTreeCnt = 0;

int pFood[N][N];
int pTree[N][N];
bool vst[N][N];

int dr[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dc[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

void spring() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j].treeCnt == 0) {
				map[i][j].food += A[i][j];
				continue;
			}

			for (int k = map[i][j].tree.size() - 1; k >= 0; k--) {
				if (map[i][j].tree[k].dead) break;

				if (map[i][j].food < map[i][j].tree[k].age) {
					map[i][j].tree[k].dead = true;
					pFood[i][j] += map[i][j].tree[k].age / 2;

					map[i][j].treeCnt--;
					totalTreeCnt--;
				}
				else {
					map[i][j].food -= map[i][j].tree[k].age;
					map[i][j].tree[k].age++;

					if (map[i][j].tree[k].age % 5 == 0) {
						for (int l = 0; l < 8; l++) {
							int nr = i + dr[l];
							int nc = j + dc[l];

							if (nr >=0 && nr < n && nc >= 0 && nc < n)
								pTree[nr][nc]++;
						}
					}
				}
			}
			map[i][j].food += pFood[i][j] + A[i][j];
			pFood[i][j] = 0;
		}
	}
}

void fall() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 1; k <= pTree[i][j]; k++) {
				map[i][j].tree.push_back({ 1, false });
				map[i][j].treeCnt++;
				totalTreeCnt++;
			}
			pTree[i][j] = 0;
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &k);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) 
			scanf("%d", &A[i][j]);
	}

	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);

		map[x - 1][y - 1].tree.push_back({ z, false });
		map[x - 1][y - 1].treeCnt++;
		totalTreeCnt++;
	}

	for (int i = 1; i <= k; i++) {
		spring();
		if (totalTreeCnt == 0) break;

		fall();
	}

	printf("%d\n", totalTreeCnt);

	return 0;
}
