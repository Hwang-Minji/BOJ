/* 5373번: 큐빙 */

#include <cstdio>
using namespace std;

#define N 1001
#define U 0
#define D 1
#define B 2
#define F 3
#define L 4
#define R 5

struct Face { char map[3][3]; };
struct Pos { int r, c; };
struct ArrIndex { int cArr, nArr; };

Pos arrIndex[4][3] = { {{0,0}, {0,1}, {0,2}}, {{0,2}, {1,2}, {2,2}}, /* 0: row0, 1: col2, 2: row2, 3:col0 */
			{{2,0}, {2,1}, {2,2}}, {{0,0}, {1,0}, {2,0}} };
char color[7] = { 'w', 'y', 'o', 'r', 'g', 'b' };

Face face[6];
int swapFace[6][6][2] = {{ {U, U}, {U, U}, {L, R}, {R, L}, {F, B}, {B, F} }, 
			 { {D, D}, {D, D}, {R, L}, {L, R}, {B, F}, {F, B} },
			 { {R, L}, {L, R}, {B, B}, {B, B}, {U, D}, {D, U} }, 
			 { {L, R}, {R, L}, {F, F}, {F, F}, {D, U}, {U, D} }, 
			 { {B, F}, {F, B}, {D, U}, {U, D}, {L, L}, {L, L} }, 
			 { {F, B}, {B, F}, {U, D}, {D, U}, {R, R}, {R, R} }};

ArrIndex changeArrIndex[6][6][2] = {{ {{0,0},{0,0}}, {{0,0},{0,0}}, {{0,1},{0,3}}, {{2,3},{2,1}}, {{3,3},{3,1}}, {{1,3},{1,1}} },
				{ {{0,0},{0,0}}, {{0,0},{0,0}}, {{0,1},{0,3}}, {{2,1},{2,3}}, {{1,1},{1,3}}, {{3,1},{3,3}} },
				{ {{0,0},{0,0}}, {{2,2},{2,2}}, {{0,0},{0,0}}, {{0,0},{0,0}}, {{1,3},{1,1}}, {{3,3},{3,1}} },
				{ {{0,0},{0,0}}, {{2,2},{2,2}}, {{0,0},{0,0}}, {{0,0},{0,0}}, {{3,1},{3,3}}, {{1,1},{1,3}} },
				{ {{0,0},{0,0}}, {{2,2},{2,2}}, {{3,0},{3,0}}, {{1,2},{1,2}}, {{0,0},{0,0}}, {{0,0},{0,0}} },
				{ {{0,0},{0,0}}, {{2,2},{2,2}}, {{1,0},{1,0}}, {{3,2},{3,2}}, {{0,0},{0,0}}, {{0,0},{0,0}} }};

bool rCheck[6][6][2] = {{ {0, 0}, {0, 0}, {1, 0}, {0, 1}, {0, 1}, {1, 0} },
			{ {0, 0}, {0, 0}, {0, 1}, {1, 0}, {0, 1}, {1, 0} },
			{ {0, 0}, {0, 0}, {0, 0}, {0, 0}, {1, 0}, {0, 1} },
			{ {0, 0}, {0, 0}, {0, 0}, {0, 0}, {1, 0}, {0, 1} },
			{ {0, 0}, {0, 0}, {1, 1}, {1, 1}, {0, 0}, {0, 0} },
			{ {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0} }};

char tempArr[3];

void faceMapInit() {
	for (int n = 0; n < 6; n++) 
		for (int i = 0; i < 3; i++) 
			for (int j = 0; j < 3; j++) 
				face[n].map[i][j] = color[n];
}

void rotate(int cur, int f, int d, int cnt) {
	if (cnt == 4) return;
	
	Pos curArrPos[3];
	char temp[3];

	for (int i = 0; i < 3; i++) 
		curArrPos[i] = arrIndex[changeArrIndex[cur][f][d].cArr][i];
	
	if (!rCheck[cur][f][d]) {
		for (int i = 0; i < 3; i++) 
			temp[i] = face[cur].map[curArrPos[i].r][curArrPos[i].c];
	}
	else {
		for (int i = 0; i < 3; i++)
			temp[i] = face[cur].map[curArrPos[2 - i].r][curArrPos[2 - i].c];
	}

	for (int i = 0; i < 3; i++) {
		face[cur].map[curArrPos[i].r][curArrPos[i].c] = tempArr[i];
		tempArr[i] = temp[i];
	}
	

	rotate(swapFace[cur][f][d], f, d, cnt + 1);
}

void rotateCurFace(int k, int dir) {
	char temp[3][3];
	temp[1][1] = face[k].map[1][1];

	if (dir == 0) { /* 시계 */
		for (int i = 0; i < 3; i++) {
			temp[0][i] = face[k].map[2 - i][0];
			temp[i][2] = face[k].map[0][i];
			temp[2][i] = face[k].map[2 - i][2];
			temp[i][0] = face[k].map[2][i];
		}
	}
	else {	/* 반시계 */
		for (int i = 0; i < 3; i++) {
			temp[0][i] = face[k].map[i][2];
			temp[i][2] = face[k].map[2][2 - i];
			temp[2][i] = face[k].map[i][0];
			temp[i][0] = face[k].map[0][2 - i];
		}
	}

	for (int i = 0; i < 3; i++) 
		for (int j = 0; j < 3; j++) 
			face[k].map[i][j] = temp[i][j];
}

int main() {
	int tc;
	scanf("%d", &tc);

	for (int T = 1; T <= tc; T++) {
		int n;
		scanf("%d", &n);

		faceMapInit();

		char rFace, dir;
		int f, d;

		for (int i = 0; i < n; i++) {
			scanf(" %c%c", &rFace, &dir);

			if (rFace == 'U') f = U;
			else if (rFace == 'D') f = D;
			else if (rFace == 'B') f = B;
			else if (rFace == 'F') f = F;
			else if (rFace == 'L') f = L;
			else if (rFace == 'R') f = R;

			if (dir == '+') d = 0;
			else if (dir == '-') d = 1;

			for (int j = 0; j < 6; j++) {
				if (swapFace[j][f][d] != j) {
					Pos tempArrIndex[3];

					if (!rCheck[j][f][d]) {
						for (int k = 0; k < 3; k++) {
							tempArrIndex[k] = arrIndex[changeArrIndex[j][f][d].cArr][k];
							tempArr[k] = face[j].map[tempArrIndex[k].r][tempArrIndex[k].c];
						}
					}
					else {
						for (int k = 0; k < 3; k++) {
							tempArrIndex[k] = arrIndex[changeArrIndex[j][f][d].cArr][2 - k];
							tempArr[k] = face[j].map[tempArrIndex[k].r][tempArrIndex[k].c];
						}
					}

					rotate(swapFace[j][f][d], f, d, 0);
					break;
				}
			}
			rotateCurFace(f, d);

		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				printf("%c", face[U].map[i][j]);
			}
			printf("\n");
		}
	}

	return 0;
}
