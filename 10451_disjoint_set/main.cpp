#include <cstdio>

using namespace std;

#define MAXX 1001

int p[MAXX], N;

void init() {
    for(int i=1; i<=N; i++)
        p[i]=i;
}

int Find(int x) {
    return (p[x] == x) ? x : (p[x]=Find(p[x]));
}

void Union(int u,int v) {
    u=Find(u);
    v=Find(v);
    p[u]=v;
}

int Check[MAXX];

int main()
{

    int T;
    scanf("%d",&T);
    for(;T>0; T--) {
        scanf("%d",&N);
        init();

        for(int i=1; i<=N; i++) {
            int k;
            scanf("%d",&k);
            int u=Find(i);
            int v=Find(k);
            p[u]=v;
        }

        int ans=0;
        for(int i=1; i<=N; i++) {
            int k=Find(i);
            if(i == k) {
                ans++;
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}
