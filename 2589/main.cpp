#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

#define rchk(n,lim) (n>=0&&n<lim)

queue <pair<int,int > > Q;

int L,W,ans=0;

char Map[55][55];
int cost[55][55];
bool visit[55][55]={0,};
void bfs(int y,int x) {

    int yy[4]={-1,1,0,0},xx[4]={0,0,-1,1};

    Q.push(make_pair(y,x));
    visit[y][x]=1;
    cost[y][x]=1;
    while(!Q.empty()) {
        pair <int,int > index=Q.front();
        //printf("%d\n",cost[index.first][index.second]-cost[y][x]);
        if(cost[index.first][index.second]-cost[y][x] > ans)
            ans=cost[index.first][index.second]-cost[y][x];
        for(int i=0; i<4; i++) {
            int Y=index.first+yy[i],X=index.second+xx[i];
            if(rchk(Y,L) && rchk(X,W) && Map[Y][X] == 'L' && visit[Y][X] == 0) {
                visit[Y][X]=1;
                cost[Y][X]=cost[index.first][index.second]+1;
                Q.push(make_pair(Y,X));
            }
        }
        Q.pop();
    }
}

int main()
{
    scanf("%d %d\n",&L,&W);

    for(int i=0; i<L; i++)
        scanf("%s",Map[i]);
    for(int i=0; i<L; i++)
        for(int j=0; j<W; j++)
            if(Map[i][j] == 'L') {
                bfs(i,j);
                memset(visit,0,sizeof(visit));
            }

    printf("%d",ans);

    return 0;
}
