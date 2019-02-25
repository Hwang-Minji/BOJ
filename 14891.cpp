/* 14891번: 톱니바퀴 */

#include <cstdio>
using namespace std;

#define S '1'
#define right(int) (int + 2) % 8
#define left(int) (int - 2 + 8) % 8

char list[4][8];
int N, ans = 0;
int pos[4] = { 0, };

void run(int n, int d, bool bl, bool br) {
	if (n < 0 || n >= 4) return;

	if (n + 1 < 4 && !br) 
		if (list[n][right(pos[n])] != list[n + 1][left(pos[n + 1])]) 
			run(n + 1, d * -1, true, false);
	
	if (n - 1 >= 0 && !bl) 
		if (list[n - 1][right(pos[n - 1])] != list[n][left(pos[n])]) 
			run(n - 1, d * -1, false, true);

	pos[n] = (pos[n] + (d * -1) + 8) % 8;
}

int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) 
			scanf(" %c", &list[i][j]);
	}

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int n, d;
		scanf("%d %d", &n, &d);
		run(n - 1, d, false, false);
	}

	for (int i = 0; i < 4; i++)
		if (list[i][pos[i]] == S)
			ans += 1 << i;

	printf("%d\n", ans);

	return 0;
}
