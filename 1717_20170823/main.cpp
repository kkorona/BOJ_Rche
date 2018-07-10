#include <cstdio>

using namespace std;

int Set[1000001];
int n,m;

int Find(int p) {
    return (Set[p]==p) ? p:Set[p]=Find(Set[p]);
}

int Union(int u, int v) {
    int fu=Find(u);
    int fv=Find(v);
    Set[fu]=fv;
}

int main()
{
    scanf("%d%d",&n,&m);

    for(int i=1; i<=n; i++)
        Set[i]=i;

    for(int i=0; i<m; i++) {
        int order,a,b;
        scanf("%d%d%d",&order,&a,&b);
        if(order == 1) {
            if(Find(a) == Find(b)) printf("YES");
            else printf("NO");
            printf("\n");
        }
        else {
            Union(a,b);
        }
    }

    return 0;
}
