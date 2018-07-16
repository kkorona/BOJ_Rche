#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int Map[100][100];
int visit[100][100];
int yy[4] = { -1,1,0,0 }, xx[4] = { 0,0,-1,1 };

bool bchk(int lo, int tar, int hi) {
	return lo <= tar && tar<hi;
}

void fill_bfs(int sy, int sx, int piv) {
	queue < pair < int, int > > Q;
	Q.push(make_pair(sy, sx));
	visit[sy][sx] = 1;

	while (!Q.empty()) {
		pair <int, int> index = Q.front();
		Q.pop();

		int y = index.first;
		int x = index.second;
		Map[y][x] = piv;
		
		for (int i = 0; i < 4; i++) {
			int Y = y + yy[i];
			int X = x + xx[i];
			if (bchk(0, Y, N) && bchk(0, X, N)) {
				if (Map[Y][X] == 1 && visit[Y][X] == 0) {
					visit[Y][X] = 1;
					Q.push(make_pair(Y, X));
				}
			}
		}
	}
}

int main() {

	scanf("%d", &N);

	for (int i = 0; i<N; i++)
		for (int j = 0; j<N; j++)
			scanf("%d", &Map[i][j]);

	int cnt = 2;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (Map[y][x] == 1) {
				fill_bfs(y,x,cnt++);
			}
		}
	}

	int ans = 987654321;

	for (int sy = 0; sy < N; sy++) {
		for (int sx = 0; sx < N; sx++) {
			for (int fy = sy; fy < N; fy++) {
				for (int fx = sx; fx < N; fx++) {
					if (bchk(2, Map[sy][sx], 999) && bchk(2, Map[fy][fx], 999) && Map[sy][sx] != Map[fy][fx])
						ans = min(ans, (fy - sy) + (fx - sx) - 1);
				}
			}
		}
	}

	printf("%d\n", ans);

}
