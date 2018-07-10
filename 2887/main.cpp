#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXX 100001

class Edge {
    public :
        int u,v,cost;
        Edge () {}
        Edge(int pu,int pv,int pcost) {
            u=pu; v=pv; cost=pcost;
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

int p[MAXX],V;

vector <Edge > List;

int E;

void init() {
    for(int i=0; i<=E; i++)
        p[i]=i;
}

int par(int x) {
    return (x == p[x]) ? x : (p[x]=par(p[x]));
}

long long kruskal() {
    sort(List.begin(),List.end());
    long long ret = 0;
    for(int i=0; i < E; i++ ) {
        int u=par(List[i].u);
        int v=par(List[i].v);
        if(u == v) continue;
        ret+=List[i].cost;
        p[u]=v;
    }
    return ret;
}

int main()
{

    scanf("%d %d",&V,&E);

    init();
    for(int i=0; i<E; i++) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        Edge temp(a,b,c);
        List.push_back(temp);
    }
    printf("%lld",kruskal());


    return 0;
}
