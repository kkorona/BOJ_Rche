#include <cstdio>
#include <queue>

using namespace std;

#define rchk(n,lim) (n>=0&&n<lim)

queue <pair <int,int > > Q;

char Map[105][105];
bool visit[105][105];
int N,M;

int bfs(int y,int x) {
    int res=0,yy[4]={-1,1,0,0},xx[4]={0,0,-1,1};
    Q.push(make_pair(y,x));
    visit[y][x]=1;
    while(!Q.empty()) {
        pair <int,int > index=Q.front();
        res++;
        for(int i=0; i<4; i++) {
            int Y=index.first+yy[i],X=index.second+xx[i];
            if(rchk(Y,M) && rchk(X,N) && visit[Y][X] == 0 && Map[Y][X]==Map[y][x]) {
                visit[Y][X]=1;
                Q.push(make_pair(Y,X));
            }
        }
        Q.pop();
    }
    return res*res;
}


int main()
{
    scanf("%d %d",&N,&M);
    int White=0,Blue=0;

    for(int i=0; i<M; i++)
        scanf("%s",Map[i]);

    for(int i=0; i<M; i++)
        for(int j=0; j<N; j++)
            if(visit[i][j] == 0) {
                if(Map[i][j] == 'W') White+=bfs(i,j);
                else Blue+=bfs(i,j);
            }

    printf("%d %d",White,Blue);

    return 0;
}
