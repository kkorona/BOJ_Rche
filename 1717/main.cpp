#include <cstdio>

using namespace std;

#define MAXX 1000001

int p[MAXX], N,M;

void Dump(int arr[],int len) {
    for(int i=0; i<=N; i++)
        printf("%d ",arr[i]);
    printf("\n");
}

void init() {
    for(int i=0; i<=N; i++)
        p[i]=i;
}

int Find(int x) {
    if(x == p[x]) return x;
    return p[x]=Find(p[x]);
}

void Union(int u,int v) {
    u=Find(u);
    v=Find(v);
    p[u]=v;
}

bool some_Func(int u,int v) {
    u=Find(u);
    v=Find(v);
    if(u == v) {
        return true;
    }
    else {
        return false;
    }
}

int main()
{

    scanf("%d %d",&N,&M);
    init();

    for(int i=0; i<M; i++) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(a == 0) {
            Union(b,c);
        }
        else {
            //printf("%d %d : ",Find(b),Find(c));
            printf("%s\n",(some_Func(b,c)) ? "YES":"NO");
        }
        //Dump(p,N);
    }

    return 0;
}
