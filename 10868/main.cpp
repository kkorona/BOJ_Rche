#include <cstdio>
#include <algorithm>
using namespace std;

int Tree[400005];
int Data[100005];
int n,m;

void build(int id,int lo,int hi) {
    if(lo == hi) {
        Tree[id]=Data[lo];
        return;
    }

    int mid=(lo+hi)>>1;
    build(id<<1,lo,mid);
    build(id<<1|1,mid+1,hi);
    Tree[id]=min(Tree[id<<1],Tree[id<<1|1]);
}

int Query(int x,int y,int id,int lo,int hi) {
    if(y < lo ||x > hi) return 1e9;
    if(x <= lo && hi <= y) return Tree[id];


    int mid=(lo+hi)>>1;
    return min(Query(x,y,id<<1,lo,mid),Query(x,y,id<<1|1,mid+1,hi));
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++) scanf("%d",&Data[i]);
    build(1,1,n);

    for(int i=0; i<m; i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",Query(x,y,1,1,n));
    }

    return 0;
}
