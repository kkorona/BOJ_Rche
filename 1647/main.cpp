#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge {
public:
    int u,v,c;
    Edge(int _u=0,int _v=0,int _c=0) : u(_u), v(_v), c(_c) {};
    bool operator < (const Edge& rhs) const {
        return c < rhs.c;
    }
};

void init(vector <int>& djs) {
    for(int i=1, _size = djs.size(); i<_size; i++)
        djs[i] = i;
}

int Find(vector <int>& djs, int x) {
    return (djs[x] == x) ? x : djs[x] = Find(djs,djs[x]);
}

void Union(vector <int>& djs, int u,int v) {
    int p = Find(djs,u), q = Find(djs,v);
    djs[p] = q;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    vector <Edge> E;
    int N,M;
    int pick = 0;
    cin >> N >> M;
    E.resize(M);
    for(int i=0; i<M; i++) {
        int u,v,c;
        cin >> u >> v >> c;
        E[i] = Edge(u,v,c);
    }
    sort(E.begin(),E.end());

    int ans = 0;
    int cutEdge = 0;

    vector <int> djs(N+1,0);
    init(djs);
    for(Edge e : E) {
        if(pick == N-1) break;
        if(Find(djs,e.u) == Find(djs,e.v)) continue;
        ans += e.c;
        Union(djs,e.u,e.v);
        pick++;
        cutEdge = max(cutEdge,e.c);
    }

    cout << ans - cutEdge;

    return 0;
}
