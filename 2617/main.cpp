#include <cstdio>
#include <cstring>

using namespace std;

int N,M;
int Graph[105][105];
int visit[105],ans=0;

int dfs(const int node,const int key) {

    int ret=0;
    bool term_check=true;

    for(int i=1; i<=N; i++)
        if(visit[i] == 0 && Graph[node][i] == key) {
            visit[i]=1;
            ret+=dfs(i,key);
        }

    return ++ret;

}

int main()
{

    scanf("%d%d",&N,&M);
    for(int i=0; i<M; i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        Graph[a][b]=1;
        Graph[b][a]=-1;
    }

    for(int i=1; i<=N; i++) {
        memset(visit,0,sizeof(visit));
        int lar=0,sma=0;
        visit[i]=1;
        for(int j=1; j<=N; j++) {
            if(visit[j] == 0 && Graph[i][j] != 0) {
                visit[j]=1;
                int k=dfs(j,Graph[i][j]);
                if(Graph[i][j] > 0) lar+=k;
                else sma+=k;
            }
        }
        if(lar >= (N+1)/2 || sma>=(N+1)/2) ans++;
    }
    printf("%d",ans);

    return 0;
}
