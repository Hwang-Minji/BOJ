/* 15686번: 치킨 배달 */

#include <cstdio>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

#define INF 2e9
#define pi pair<int, int>
#define N 51
#define M 14

int n, m, MIN = INF;
vector<pi> h, s;
int d[M][2*N];
int dist[2*N];

void dfs(int cnt, int k, int sum) {
	if (sum < MIN) MIN = sum;
	if (cnt == m) return;
	
	for (int i = k + 1; i < s.size(); i++) {
		bool flag = false;
		int temp[2 * N] = { 0, };
		int tempSum = 0;
 
		for (int j = 0; j < h.size(); j++) temp[j] = dist[j];		
		for (int j = 0; j < h.size(); j++) {
			if (dist[j] > d[i][j]) {
				tempSum += dist[j] - d[i][j];
				dist[j] = d[i][j];
				flag = true;
			}
		}

		if (flag) {
			dfs(cnt + 1, i, sum - tempSum);
			for (int j = 0; j < h.size(); j++) dist[j] = temp[j];
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int num;
			scanf("%d", &num);
			if (num == 1) h.push_back({ i,j });
			else if (num == 2) s.push_back({ i,j });
		}
	}

	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < h.size(); j++) 
			d[i][j] = abs(s[i].first - h[j].first) + abs(s[i].second - h[j].second);
	}

	for (int i = 0; i <= s.size() - m; i++) {
		int sum = 0;
		for (int j = 0; j < h.size(); j++) {
			dist[j] = d[i][j];
			sum += dist[j];
		}
		dfs(1, 0, sum);
	}

	printf("%d\n", MIN);
	return 0;
}
