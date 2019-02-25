/* 14890번: 경사로 */

#include <cstdio>
using namespace std;

#define N 101
int map[N][N], road[N];
int n, l;

bool check() {
	bool vst[N] = { false, };

	for (int i = 0; i < n - 1; i++) {
		if (road[i] > road[i + 1]) {
			if (road[i] - road[i + 1] > 1) return false;

			for (int j = 1; j <= l; j++) {
				if (i + j >= n) return false;
				if (road[i + 1] != road[i + j] || vst[i + j]) return false;
				vst[i + j] = true;
			}
		}
		if (road[n - 2 - i] < road[n - 1 - i]) {
			if (road[n - 1 - i] - road[n - 2 - i] > 1) return false;

			for (int j = 1; j <= l; j++) {
				if (n - 1 - i - j < 0) return false;
				if (road[n - 1 - i - j] != road[n - 2 - i] || vst[n - 1 - i - j]) return false;
				vst[n - 1 - i - j] = true;
			}
		}
	}

	return true;
}

int main() {
	scanf("%d %d", &n, &l);

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			scanf("%d", &map[i][j]);
	
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) road[j] = map[i][j];
		if(check()) cnt++;

		for (int j = 0; j < n; j++) road[j] = map[j][i];
		if(check()) cnt++;
	}

	printf("%d\n", cnt);

	return 0;
}
