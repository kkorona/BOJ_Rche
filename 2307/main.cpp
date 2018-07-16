#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct edge {
    int u,v,c;
    edge(int u=0,int v=0,int c=0) : u(u), v(v), c(c) {}
};

vector < vector < int > > adj;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    int N,M;
    cin >> N >> M;
    adj.resize(N+1,vector<int>(N+1,1e9));
    for(int i=0; i < M; i++) {
        int u,v,c;
        cin >> u >> v >> c;
        adj[u][v] = adj[v][u] = c;
    }

    vector < edge > sp;

    vector < int > T(N+1,1e9);
    vector < int > via(N+1,0);
    T[1] = 0;
    priority_queue < pair <int, int> > Q;
    Q.push(make_pair(0,1));
    while(!Q.empty()) {
        int index = Q.top().second;
        Q.pop();
        for(int i=1; i<=N; i++) {
            if(T[i] > T[index] + adj[index][i]) {
                T[i] = T[index] + adj[index][i];
                via[i] = index;
                Q.push(make_pair(-T[i],i));
            }
        }
    }

    int normal = T[N], ans = 0;
    int cur = N;
    while(via[cur] != 0) {
        sp.push_back(edge(via[cur],cur,adj[via[cur]][cur]));
        cur = via[cur];
    }

    for(edge e : sp) {
        adj[e.u][e.v] = 1e9;
        adj[e.v][e.u] = 1e9;
        for(int& v : T) v = 1e9;
        T[1] = 0;
        Q.push(make_pair(0,1));
        while(!Q.empty()) {
            int index = Q.top().second;
            Q.pop();
            for(int i=1; i<=N; i++) {
                if(T[i] > T[index] + adj[index][i]) {
                    T[i] = T[index] + adj[index][i];
                    Q.push(make_pair(-T[i],i));
                }
            }
        }
        ans = max(ans,T[N]);
        adj[e.u][e.v] = e.c;
        adj[e.v][e.u] = e.c;
    }

    if(ans == 1e9) cout << -1;
    else cout << ans - normal;

    return 0;
}


