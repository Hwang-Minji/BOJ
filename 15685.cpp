/* 15685번: 드래곤 커브 */

#include <cstdio>
#include <vector>
using namespace std;

#define N 101

int dr[4] = { 0, -1, 0, 1 };
int dc[4] = { 1, 0, -1, 0 };
int n, r, c, d, g;
bool map[N][N];
vector<int> dist;

void run() {
	for (int k = 1; k <= g; k++) {
		for (int i = dist.size() - 1; i >= 0; i--)
			dist.push_back((dist[i] + 1) % 4);
	}

	map[r][c] = true;
	for (int i = 0; i < dist.size(); i++) {
		r += dr[dist[i]], c += dc[dist[i]];
		if (r < 0 || r>100 || c < 0 || c>100) continue;
		map[r][c] = true;
	}
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &c, &r, &d, &g);
		dist.clear();
		dist.push_back(d);
		run();
	}

	int cnt = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) 
			if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1]) cnt++;
	}

	printf("%d\n", cnt);

	return 0;
}
