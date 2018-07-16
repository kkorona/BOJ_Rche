#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int p[100001];

void init(int v) {
    for(int i=0; i<v; i++)
        p[i]=i;
}

int Find(int v) {
    return (p[v] == v) ? v : p[v]=Find(p[v]);
}

void Union(int u,int v) {
    int pu=Find(u);
    int pv=Find(v);
    p[pu]=pv;
}

class Edge {
public:
    int st,ed,cost;
    Edge(int _st=0, int _ed=0, int _cost=0) : st(_st),ed(_ed),cost(_cost) {}
    bool operator < (const Edge& rhs) const {
        return cost < rhs.cost;
    }
};

int main()
{

    int N;

    scanf("%d",&N);

    vector < pair <int,int> > X(N),Y(N),Z(N);

    init(N);

    for(int i=0; i<N; i++) {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        X[i]=make_pair(x,i);
        Y[i]=make_pair(y,i);
        Z[i]=make_pair(z,i);
    }

    vector < Edge > Tunnel;

    sort(X.begin(),X.end());
    for(int i=0; i<N-1; i++) {
        int p1=X[i].second;
        int p2=X[i+1].second;
        Tunnel.push_back(Edge(p1,p2,X[i+1].first - X[i].first));
    }
    sort(Y.begin(),Y.end());
    for(int i=0; i<N-1; i++) {
        int p1=Y[i].second;
        int p2=Y[i+1].second;
        Tunnel.push_back(Edge(p1,p2,Y[i+1].first - Y[i].first));
    }
    sort(Z.begin(),Z.end());
    for(int i=0; i<N-1; i++) {
        int p1=Z[i].second;
        int p2=Z[i+1].second;
        Tunnel.push_back(Edge(p1,p2,Z[i+1].first - Z[i].first));
    }

    sort(Tunnel.begin(),Tunnel.end());

    long long ans = 0;

    int n=Tunnel.size();
    for(int i=0; i<n; i++) {
        int u=Find(Tunnel[i].st);
        int v=Find(Tunnel[i].ed);
        if(u == v) continue;
        ans+=Tunnel[i].cost;
        Union(Tunnel[i].st,Tunnel[i].ed);
    }

    printf("%lld",ans);

    return 0;
}
