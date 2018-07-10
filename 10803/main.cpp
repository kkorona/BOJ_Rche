#include <cstdio>
#include <algorithm>
using namespace std;
int W, H;
int R[10005][105];
int main() {

	scanf("%d %d", &W, &H);
	if(W < H) swap(W, H);

	for(int i = 1; i <= W; i++)
		for(int j = 1; j <= H; j++){
			R[i][j] = 1e9;

			if(i == j) R[i][j] = 1;
			else if (3 * i >= j*j) R[i][j] = R[i-j][j] + 1;
			else{
				for(int k = 1; k < i; k++) R[i][j] = min(R[i][j], R[k][j] + R[i-k][j]);
				for(int k = 1; k < j; k++) R[i][j] = min(R[i][j], R[i][k] + R[i][j-k]);
			}
		}

	printf("%d\n", R[W][H]);

	return 0;
}
