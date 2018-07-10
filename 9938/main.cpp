#include <cstdio>

using namespace std;

const int MAX = 300001;

int p[MAX];
bool c[MAX];
int N,L;

void init() {
    for(int i=0; i<MAX; i++) p[i]=i;
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
    init();

    scanf("%d%d",&N,&L);

    for(int i=0; i<N; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        int fa=Find(a);
        int fb=Find(b);
        if(!c[a]) {
            c[a]=true;
            Union(fa,fb);
        }
        else if(!c[b]) {
            c[b]=true;
            Union(fb,fa);
        }
        else if(!c[fa]) {
            c[fa]=true;
            Union(fa,fb);
        }
        else if(!c[fb]) {
            c[fb]=true;
            Union(fb,fa);
        }
        else {
            printf("SMECE\n");
            continue;
        }
        printf("LADICA\n");
    }
    return 0;
}


