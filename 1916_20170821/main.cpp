#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int n,m;
long long Graph[1001][1001];
long long adj[1001];
const int LLINF = 1e18;

void dijkstra(int node) {
    queue <int> Q;
    Q.push(node);
    while(!Q.empty()) {
        int index=Q.front();
        Q.pop();
        for(int i=1; i<=n; i++) {
            if(Graph[index][i] !=LLINF && adj[i] > adj[index]+Graph[index][i]) {
                adj[i]=adj[index]+Graph[index][i];
                Q.push(i);
            }
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m);

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            Graph[i][j]=LLINF;
    for(int i=0; i<m; i++) {
        int y,x,val;
        scanf("%d%d%d",&x,&y,&val);
        Graph[x][y]=min(Graph[x][y],(long long int)val);
        //Graph[y][x]=val;
    }
    int st,ed;
    scanf("%d%d",&st,&ed);

    for(int i=1; i<=n; i++)
        adj[i]=LLINF;

    adj[st]=0;

    dijkstra(st);

    /*
    for(int i=1; i<=n; i++)
        printf("%lld ",adj[i]);
    */

    printf("%lld",adj[ed]);
    return 0;
}
