#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int Graph[252][252];
int Map[52][52];
int Wall[52][52];
int visit[52][52];
int Area[252];

const int dif[4] = { 1, 2, 4, 8 };
const int dy[4] = { 0, -1, 0,  1 };
const int dx[4] = { -1, 0, 1, 0 };

int N, M;

inline bool bchk(int lo, int tar, int hi) {
	return lo <= tar && tar < hi;
}

int bfs(int sy, int sx,int piv) {
	queue < pair <int, int> > Q;
	Q.push(make_pair(sy,sx));
	visit[sy][sx] = 1;
	int area = 0;

	while (!Q.empty()) {

		area++;
		pair <int, int> index = Q.front();
		Q.pop();

		int y = index.first;
		int x = index.second;

		Map[y][x] = piv;
		for (int i = 0; i < 4; i++) {
			if ((Wall[y][x] & dif[i]) == 0) {
				int Y = y + dy[i];
				int X = x + dx[i];
				if (bchk(0, Y, N) && bchk(0, X, M) && visit[Y][X] == 0) {
					visit[Y][X] = 1;
					Q.push(make_pair(Y, X));
				}
			}
		}

	}
	return area;
}

int main() {

	scanf("%d %d",&M,&N);


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &Wall[i][j]);
		}
	}

	int cnt = 1, MaxArea = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (visit[y][x] == 0) {
				Area[cnt] = bfs(y, x, cnt);
				MaxArea = max(MaxArea, Area[cnt]);
				cnt++;
			}
		}
	}

	printf("%d\n%d\n", cnt-1, MaxArea);

	int MaxMerge = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			for (int i = 0; i < 4; i++) {
				int Y = y + dy[i], X = x + dx[i];
				if (bchk(0, Y, N) && bchk(0, X, N) && Map[Y][X] != Map[y][x]) {
                    MaxMerge=max(MaxMerge,Area[Map[Y][X]]+Area[Map[y][x]]);
				}
			}
		}
	}

	printf("%d\n", MaxMerge);

	return 0;
}
