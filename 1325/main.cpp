#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N,M;
vector < int > result;
vector < vector < int > > adj;
void BFS(int start) {
    vector <int> visit(N+1,0);
    visit[start]=1;
    queue <int> Q;
    Q.push(start);
    while(!Q.empty()) {
        int index = Q.front();
        Q.pop();
        result[index]++;
        for(int v : adj[index]) {
            if(!visit[v]) {
                visit[v]=1;
                Q.push(v);
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    adj.resize(N+1);
    result.resize(N+1,0);

    for(int i=0; i<M; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for(int i=1; i<=N; i++) {
        BFS(i);
    }
    vector <int> ret;
    int maxval = 0;
    for(int i=1; i<=N; i++) {
        if(result[i] > maxval) {
            ret.clear();
            ret.push_back(i);
            maxval = result[i];
        }
        else if(result[i] == maxval) {
            ret.push_back(i);
        }
    }
    for(int v : ret) cout << v << " ";
    return 0;
}
