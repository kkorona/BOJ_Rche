#include <cstdio>

using namespace std;

const int MAXX = 1e6 + 1;

int p[MAXX];
int P,G;

void init() {
    for(int i=0; i<MAXX; i++)
        p[i]=i;
}

int Find(int u) {
    return (p[u] == u) ? u : p[u]=Find(p[u]);
}

void Union(int u,int v) {
    int fu=Find(u);
    int fv=Find(v);
    p[fu]=fv;
}

int main()
{

    scanf("%d%d",&G,&P);

    int ans=0;
    init();
    for(int i=0; i<P; i++) {
        int x;
        scanf("%d",&x);
        int q=Find(x);
        if(q == 0) break;
        p[q]=q-1;
        ans++;
    }

    printf("%d",ans);

    return 0;
}
