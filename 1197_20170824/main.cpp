#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class Edge {
    public :
        int dep,dest,cost;
        Edge () {}
        Edge(int pu,int pv,int pcost) {
            dep=pu; dest=pv; cost=pcost;
        }

        bool operator ==(const Edge &E) const {
            if(cost == E.cost) return true;
            return false;
        }

        bool operator >(const Edge &E) const {
            if(cost != E.cost) return cost > E.cost;
            return false;
        }
        bool operator <=(const Edge &E) const {
            return !(*this > E);
        }
        bool operator >=(const Edge &E) const {
            return (*this > E || *this == E);
        }
        bool operator <(const Edge &E) const {
            return !(*this >= E);
        }
};

int p[100001];

void init(int V) {
    for(int i=1; i<=V; i++)
        p[i]=i;
}

int Find(int u) {
    return (p[u] == u) ? u : p[u]=Find(p[u]);
}

int main()
{

    int V,E;
    scanf("%d%d",&V,&E);
    vector < Edge > Linears(E,Edge(0,0,0));

    init(V);

    for(int i=0; i<E; i++) {
        int dp,dst,cst;
        scanf("%d%d%d",&dp,&dst,&cst);
        Linears[i]=Edge(dp,dst,cst);
    }

    sort(Linears.begin(),Linears.end());

    long long ans=0;
    for(int i=0; i<E; i++) {
        int u=Find(Linears[i].dep);
        int v=Find(Linears[i].dest);
        if(u == v) continue;
        p[u]=v;
        ans+=Linears[i].cost;
    }

    printf("%lld",ans);

    return 0;
}
