#include <cstdio>

using namespace std;

int Graph[201][201],Plan[1001],p[201];
int N,M;

void init() {
    for(int i=1; i<=N; i++) p[i]=i;
}

int Find(int x) {
    return (p[x] == x) ? x : (p[x]=Find(p[x]));
}

void Union(int u,int v) {
    u=Find(u);
    v=Find(v);
    p[u]=v;
}

bool sameGroup(int u,int v) {
    u=Find(u);
    v=Find(v);
    if(u == v) return true;
    return false;
}

int main()
{
    scanf("%d%d",&N,&M);
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            scanf("%d",&Graph[i][j]);

    for(int i=0; i<M; i++)
        scanf("%d",&Plan[i]);

    init();

    for(int i=1; i<=N; i++) {
        for(int j=i; j<=N; j++)
            if(Graph[i][j] == 1) {
                Union(i,j);
            }
    }
    bool ans=true;
    for(int i=1; i<M; i++) {
        if(!sameGroup(Plan[i],Plan[i-1]))
            ans=false;
    }

    printf("%s",ans?"YES":"NO");

    return 0;
}
