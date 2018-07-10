#include <cstdio>
#include <queue>

using namespace std;

class loc{
    public:
        int x,y,z;

        loc(int px,int py,int pz) {
            x=px; y=py; z=pz;
        }
};
int Box[101][101][101],visited[101][101][101],N,M,H,ans=0;

queue <loc > Q;

bool overrange(int p,int limit) {
    if(p<0) return true;
    if(p>=limit) return true;
    return false;
}

void BFS() {
    int xx[6]={-1,1,0,0,0,0},yy[6]={0,0,-1,1,0,0},zz[6]={0,0,0,0,-1,1};
    while(!Q.empty()) {
        int x=Q.front().x,y=Q.front().y,z=Q.front().z;
        Q.pop();
        visited[x][y][z]=1;
        if(Box[x][y][z] > ans) ans=Box[x][y][z];

        for(int i=0; i<6; i++) {
            int X=x+xx[i],Y=y+yy[i],Z=z+zz[i];
            if(overrange(X,H) || overrange(Y,N) || overrange(Z,M)) continue;
            if(Box[X][Y][Z] == 0 && visited[X][Y][Z] == 0) {
                Box[X][Y][Z]=Box[x][y][z]+1;
                Q.push(loc(X,Y,Z));
            }
        }
    }
}

int main()
{

    scanf("%d %d %d",&M,&N,&H);
    for(int i=0; i<H; i++)
        for(int j=0; j<N; j++)
            for(int k=0; k<M; k++) {
                scanf("%d",&Box[i][j][k]);
                if(Box[i][j][k] == 1) {
                    Q.push(loc(i,j,k));
                }
                if(Box[i][j][k] == -1) visited[i][j][k]=1;
            }

    BFS();

    for(int i=0; i<H; i++)
        for(int j=0; j<N; j++)
            for(int k=0; k<M; k++)
                if(Box[i][j][k] == 0) ans=0;

    printf("%d",ans-1);

    return 0;
}

/*
2 2 1
1 1
1 1

*/
