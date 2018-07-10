#include <cstdio>
#include <queue>

using namespace std;

#define MAXX (10*125*125)
#define rchk(n,lim) (n>=0 && n<lim)

typedef pair<int, int > Point;

queue <Point> Q;

int Cost[125][125], Map[125][125], N;

void bfs() {
    Cost[0][0]=Map[0][0];
    int yy[4]={-1,1,0,0},xx[4]={0,0,-1,1};
    Q.push(make_pair(0,0));
    while(!Q.empty()) {
        Point index=Q.front();
        int y=index.first,x=index.second;
        for(int i=0; i<4; i++) {
            int Y=y+yy[i],X=x+xx[i];
            if(rchk(Y,N) && rchk(X,N) && Cost[Y][X] > Cost[y][x] + Map[Y][X]) {
                Cost[Y][X]=Cost[y][x]+Map[Y][X];
                Q.push(make_pair(Y,X));
            }
        }
        Q.pop();
    }
}

int main()
{
    int cnt=1;
    while(1) {
        scanf("%d",&N);

        if(N == 0) break;

        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++) {
                scanf("%d",&Map[i][j]);
                Cost[i][j]=MAXX;
            }

        bfs();

        printf("Problem %d: %d\n",cnt++,Cost[N-1][N-1]);
    }
    return 0;
}
