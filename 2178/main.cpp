#include <cstdio>
#include <queue>

#define rchk(n,lim) (n < lim && n >= 0)

using namespace std;

queue <pair<int,int > > Q;

char Map[105][105];
int cost[105][105];
int visit[105][105];
int N,M;

void bfs(int y,int x) {
    int yy[4]={-1,1,0,0},xx[4]={0,0,-1,1};
    cost[y][x]=1;
    visit[y][x]=1;
    Q.push(make_pair(y,x));

    while(!Q.empty()) {
        pair <int,int > index=Q.front();
        for(int i=0; i<4; i++) {
            int X=index.second+xx[i],Y=index.first+yy[i];
            if(rchk(X,M) && rchk(Y,N) && visit[Y][X] == 0 && Map[Y][X] == '1') {
                Q.push(make_pair(Y,X));
                visit[Y][X]=1;
                cost[Y][X]=cost[index.first][index.second]+1;
            }
        }
        Q.pop();
    }
}

int main()
{
    char temp[400];

    scanf("%d %d",&N,&M);

    for(int i=0; i<N; i++) scanf("%s",Map[i]);

    bfs(0,0);

    printf("%d",cost[N-1][M-1]);

    return 0;
}
