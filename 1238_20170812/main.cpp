#include <cstdio>
#include <queue>

using namespace std;

int Graph[1001][1001];
int Forward[1001],Reverse[1001];

const int INF = 1e9;

int n,m;

void dijkstra(int node,const int type) {
    queue <int> Q;
    Q.push(node);
    while(!Q.empty()) {
        int index=Q.front();
        Q.pop();
        for(int i=1; i<=n; i++) {
            if(type && Graph[i][index] > 0 && Forward[i] > Forward[index]+Graph[i][index]) {
                Forward[i] = Forward[index]+Graph[i][index];
                Q.push(i);
            }
            if(!type && Graph[index][i] > 0 && Reverse[i] > Reverse[index]+Graph[index][i]) {
                Reverse[i] = Reverse[index]+Graph[index][i];
                Q.push(i);
            }
        }
    }
}

int main()
{
    int st;
    scanf("%d%d%d",&n,&m,&st);

    for(int i=0; i<m; i++) {
        int x,y,val;
        scanf("%d%d%d",&x,&y,&val);
        Graph[x][y]=val;
    }

    for(int i=1; i<=n; i++) {
        Forward[i]=Reverse[i]=INF;
    }

    Forward[st]=Reverse[st]=0;

    dijkstra(st,0);
    dijkstra(st,1);

    int ans=0;
    for(int i=1; i<=n; i++)
        ans=max(ans,Forward[i]+Reverse[i]);

    printf("%d",ans);

    return 0;
}
