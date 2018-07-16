#include <cstdio>

using namespace std;

int p[201];
int N,M;

const int MAXX = 201;

void init() {
    for(int i=1; i<=MAXX; i++) {
        p[i]=i;
    }
}

int Find(int u) {
    return (p[u] == u) ? u : p[u]=Find(p[u]);
}

void Union(int u,int v) {
    int fu=Find(u);
    int fv=Find(v);
    p[fu]=fv;
}

bool same_group(int u,int v) {
    int fu=Find(u);
    int fv=Find(v);
    return fu == fv;
}

int Graph[201][201];

int main()
{

    init();
    scanf("%d%d",&N,&M);

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            scanf("%d",&Graph[i][j]);
        }
    }

    for(int i=1; i<=N; i++) {
        for(int j=i; j<=N; j++) {
            if(Graph[i][j]) {
                Union(i,j);
            }
        }
    }

    bool ans=true;
    int prev,cur;
    scanf("%d",&prev);
    for(int i=2; i<=M; i++) {
        scanf("%d",&cur);
        if(!same_group(prev,cur)) ans=false;
    }

    if(ans) printf("YES");
    else printf("NO");

    return 0;
}
