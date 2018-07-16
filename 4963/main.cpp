#include <cstdio>
#include <cstring>
#include <queue>
#define rchk(n,lim) (n>=0 && n<lim)

using namespace std;

int T,w,h,isle;
int Map[55][55],visit[55][55];

queue <pair<int, int > > Q;

void bfs(int y,int x) {
    Q.push(make_pair(y,x));
    visit[y][x]=1;
    int yy[8]={-1,-1,-1,0,0,1,1,1},xx[8]={-1,0,1,-1,1,-1,0,1};
    while(!Q.empty()) {
        pair <int,int > index=Q.front();
        for(int i=0; i<8; i++) {
            int Y=index.first+yy[i],X=index.second+xx[i];
            if(rchk(Y,h) && rchk(X,w) && visit[Y][X] == 0 && Map[Y][X] == 1) {
                visit[Y][X]=1;
                Q.push(make_pair(Y,X));
            }
        }
        Q.pop();
    }
}

int main()
{



    while(1) {
        scanf("%d %d",&w,&h);
        isle=0;
        if(w == 0 && h == 0) break;
        memset(visit,0,sizeof(visit));
        for(int i=0; i<h; i++)
            for(int j=0; j<w; j++) {
                scanf("%d",&Map[i][j]);
                if(Map[i][j] == 0)
                    visit[i][j]=1;
            }
        for(int i=0; i<h; i++)
            for(int j=0; j<w; j++) {
                if(Map[i][j] == 1 && visit[i][j] == 0) {
                    bfs(i,j);
                    isle++;
                }
            }
        printf("%d\n",isle);
    }

    return 0;
}
