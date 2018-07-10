#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

inline bool rchk(int n,int lim) { return (n>=0 && n<lim); }

queue <pair <int,int > > Q;

int cost[305][305],visit[305][305],N;

void BFS(int y,int x,int ty,int tx) {

    int yy[8]={-2,-2,-1,-1,1,1,2,2},xx[8]={-1,1,-2,2,-2,2,-1,1};
    visit[y][x]=1;
    cost[y][x]=0;
    Q.push(make_pair(y,x));

    while(!Q.empty()) {
        pair <int,int > index=Q.front();
        if(index == make_pair(ty,tx)) break;
        for(int i=0; i<8; i++) {
            int Y=yy[i]+index.first,X=xx[i]+index.second;
            if(rchk(Y,N) && rchk(X,N) && visit[Y][X]==0) {
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
    int y,x,ty,tx,T;
    scanf("%d",&T);
    for(;T>0;T--) {
        scanf("%d",&N);

        memset(visit,0,sizeof(visit));
        memset(cost,0,sizeof(cost));
        while(!Q.empty()) Q.pop();

        scanf("%d%d%d%d",&y,&x,&ty,&tx);
        BFS(y,x,ty,tx);
        printf("%d\n",cost[ty][tx]);
    }
    return 0;
}
