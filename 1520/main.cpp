#include <cstdio>
#include <vector>
#include <limits>
using namespace std;

vector < vector < int > > Memo;
vector < vector < int > > Map;
int n,m;

bool bchk(int lo,int tar,int hi) {
    return lo<=tar && tar < hi;
}

int solve(int y,int x) {

    if(y == 1 && x == 1) return 1;

    if(Memo[y][x] != -1) return Memo[y][x];

    int yy[4]={-1,0,0,1}, xx[4] = {-0,-1,1,0};

    int ret=0;


    for(int i=0; i<4; i++) {
        int Y=y+yy[i], X=x+xx[i];
        if(!bchk(1,Y,n+1) || !bchk(1,X,m+1)) continue;
        if(Map[Y][X] > Map[y][x]) {
            int p=solve(Y,X);
            if(p != 0) ret+=p;
        }
    }

    Memo[y][x]=ret;

    return Memo[y][x];

}

int main()
{

    scanf("%d%d",&n,&m);

    Memo.resize(n+1);
    Map.resize(n+1);

    for(int i=0; i<=n; i++) {
        Memo[i].resize(m+1,-1);
        Map[i].resize(m+1,0);
    }

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            scanf("%d",&Map[i][j]);

    printf("%d",solve(n,m));

    return 0;
}
