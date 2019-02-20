/* 15988번: 1, 2, 3 더하기 3 */

#include <cstdio>
using namespace std;

#define N 1000001
#define D 1000000009
#define ll long long

ll d[N];
int n;

int main() {
	int tc;
	scanf("%d", &tc);
	d[1] = 1, d[2] = 2, d[3] = 4;

	for (int i = 4; i < N; i++)
		d[i] = (d[i - 1] + d[i - 2] + d[i - 3]) % D;
	
	for (int T = 1; T <= tc; T++) {
		scanf("%d", &n);
		printf("%lld\n", d[n]);
	}

	return 0;
}
