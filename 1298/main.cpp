#include <bits/stdc++.h>

using namespace std;

vector <int> aMatch;
vector <int> bMatch;
vector <int> visit;

vector < vector < int > > adjList;

int visitCnt = 1;
int N,M;

int dfs(int a) {
    if(visit[a] == visitCnt) return 0;
    visit[a] = visitCnt;
    for(auto b : adjList[a]) {
        if(bMatch[b] == -1 || dfs(bMatch[b])) {
            aMatch[a] = b;
            bMatch[b] = a;
            return 1;
        }
    }
    return 0;
}

int bipartiteMatching() {
    int _size = 0;
    aMatch = vector<int>(N+1, -1);
    bMatch = vector<int>(M+1, -1);
    visit = vector<int>(N+1,0);
    for(int i=1; i<=N; i++) {
        _size += dfs(i);
        visitCnt++;
    }
    return _size;
}

int main()
{

    scanf("%d %d",&N,&M);

    adjList.resize(N+1);
    for(int i=0; i<M; i++) {
        int u,v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }

    printf("%d",bipartiteMatching());
    return 0;
}
