#include <stdio.h>

typedef struct STT {
	int y;
	int x;
	int n;
	int d;
	int a;
}STT;
typedef struct SML {
	int n;
	int k;
}SML;
STT SRK[401];
SML MAP[20][20];
int dir[5][2] = { {-1, -1}, {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int PRT[401][4][4];
int main(void) {
	int N, M, K, I, D, EF;

	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			scanf("%d", &I);
			if (I) {
				SRK[I].y = i;
				SRK[I].x = j;
				SRK[I].n = I;
				SRK[I].a = 1;
				MAP[i][j].n = I;
				MAP[i][j].k = K;
			}
			else {
				MAP[i][j].n = 0;
				MAP[i][j].k = 0;
			}
		}
	for (int i = 1; i <= M; i++)
		scanf("%d", &SRK[i].d);
	for (int s = 1; s <= M; s++)
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				scanf("%d", &PRT[s][i][j]);

	for (int t = 1; t <= 1000; t++) {
		for (int s = 1; s <= M; s++) {
			if (!SRK[s].a)
				continue;
			int FLG = 0;
			for (int d = 0; d < 4; d++) {
				int NY = SRK[s].y + dir[PRT[s][SRK[s].d - 1][d]][0];
				int NX = SRK[s].x + dir[PRT[s][SRK[s].d - 1][d]][1];

				if (0 <= NY && NY <= N - 1 && 0 <= NX && NX <= N - 1 && !MAP[NY][NX].n) {
					FLG = 1;
					SRK[s].y = NY;
					SRK[s].x = NX;
					SRK[s].d = PRT[s][SRK[s].d - 1][d];
					break;
				}
			}
			if (!FLG)
				for (int d = 0; d < 4; d++) {
					int NY = SRK[s].y + dir[PRT[s][SRK[s].d - 1][d]][0];
					int NX = SRK[s].x + dir[PRT[s][SRK[s].d - 1][d]][1];

					if (0 <= NY && NY <= N - 1 && 0 <= NX && NX <= N - 1 && MAP[NY][NX].n == SRK[s].n) {
						SRK[s].y = NY;
						SRK[s].x = NX;
						SRK[s].d = PRT[s][SRK[s].d - 1][d];
						break;
					}
				}
		}

		for (int i = 1; i < M; i++)
			for (int j = i + 1; j <= M; j++)
				if (SRK[i].a && SRK[j].a && SRK[i].y == SRK[j].y && SRK[i].x == SRK[j].x)
					if (i < j)
						SRK[j].a = 0;
					else
						SRK[i].a = 0;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (MAP[i][j].n)
					if (!--MAP[i][j].k)
						MAP[i][j].n = 0;

		for (int s = 1; s <= M; s++)
			if (SRK[s].a) {
				MAP[SRK[s].y][SRK[s].x].n = s;
				MAP[SRK[s].y][SRK[s].x].k = K;
			}

		EF = 0;
		for (int i = 2; i <= M; i++)
			if (SRK[i].a)
				EF = 1;
		if (!EF) {
			printf("%d\n", t);
			break;
		}
	}
	if (EF)
		printf("-1\n");

	return 0;
}
