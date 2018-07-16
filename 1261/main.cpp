#include <cstdio>
#include <queue>

using namespace std;

#define MAXX (10*125*125)
#define rchk(n,lim) (n>=0 && n<lim)

typedef pair<int, int > Point;

queue <Point> Q;

int Cost[125][125], N,M;
char Map[125][125];

void bfs() {
    Cost[0][0]=0;
    int yy[4]={-1,1,0,0},xx[4]={0,0,-1,1};
    Q.push(make_pair(0,0));
    while(!Q.empty()) {
        Point index=Q.front();
        int y=index.first,x=index.second;
        for(int i=0; i<4; i++) {
            int Y=y+yy[i],X=x+xx[i];
            if(rchk(Y,N) && rchk(X,M) && Cost[Y][X] > Cost[y][x] + (Map[Y][X]-'0')) {
                Cost[Y][X]=Cost[y][x]+(Map[Y][X]-'0');
                Q.push(make_pair(Y,X));
            }
        }
        Q.pop();
    }
}

int main()
{
    int cnt=1;
    scanf("%d%d",&M,&N);

    for(int i=0; i<N; i++) {
        scanf("%s",Map[i]);
        for(int j=0; j<M; j++) {
            Cost[i][j]=MAXX;
        }
    }

    bfs();

    printf("%d",Cost[N-1][M-1]);
    return 0;
}
