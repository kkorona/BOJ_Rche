#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n,m;

    scanf("%d%d",&n,&m);

    vector < vector < int > > Maze(n+1);
    vector < vector < int > > T(n+1);

    for(int i=0; i<=n; i++) {
        Maze[i].resize(m+1,0);
        T[i].resize(m+1,0);
    }

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            scanf("%d",&Maze[i][j]);

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            T[i][j] = max(T[i-1][j],T[i][j-1]) + Maze[i][j];
        }
    }

    printf("%d",T[n][m]);

    return 0;
}
