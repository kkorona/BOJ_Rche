#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int Map[100][100];

bool bchk(int lo,int tar,int hi) {
    return lo<=tar && tar<hi;
}

int main() {

    scanf("%d",&N);

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf("%d",&Map[i][j]);

    int yy[4]={-1,1,0,0},xx[4]={0,0,-1,1};

    for(int i=0; i<N; i++)
}
