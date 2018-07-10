#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long lli;

class edge {
public :
    int v,c;
    edge(int v=0,int c=0) : v(v), c(c) {};
    bool operator < (const edge& rhs) const {
        return c < rhs.c;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();


    int N,M,C;
    cin >> N >> M >> C;
    vector < vector < edge > > adj(N+1);
    lli edgeSum = 0;
    while(M--) {
        static int u,v,c;
        cin >> u >> v >> c;
        adj[u].push_back(edge(v,c));
        adj[v].push_back(edge(u,c));
        edgeSum += c;
    }

    vector <int> check(N+1,0);
    priority_queue < pair <lli,int > > pq;
    pq.push(make_pair(0,1));
    lli ans = 1e15;
    while(!pq.empty()) {
        int index = pq.top().second;
        lli cost = -pq.top().first;
        pq.pop();
        if(check[index]) continue;
        check[index] = 1;
        for(edge p : adj[index]) {
            if(check[p.v]) edgeSum -= p.c;
            pq.push(make_pair(-cost-p.c,p.v));
        }
        ans = min(ans, edgeSum + cost * C);
    }

    cout << ans;

    return 0;
}
