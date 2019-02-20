/* 9095번: 1, 2, 3 더하기 */

#include <cstdio>
using namespace std;

#define N 12
int n;


int main() {
	int tc;
	scanf("%d", &tc);
	
	for (int T = 1; T <= tc; T++) {
		scanf("%d", &n);
		int d[N] = { 0, };

		for (int i = 1; i <= n; i++) {
			if (i > 1) d[i] = d[i - 1];
			if (i > 2) d[i] += d[i - 2];
			if (i > 3) d[i] += d[i - 3];
			if (i <= 3) d[i]++;
		}
		printf("%d\n", d[n]);
	}

	return 0;
}
