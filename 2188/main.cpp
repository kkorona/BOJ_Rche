#include <cstdio>
#include <vector>

using namespace std;

vector < vector < int > > adjList;
vector < int > aMatch;
vector < int > bMatch;
vector < int > visited;

int N,M;
int visitCnt = 1;

int dfs(int a) {
    if(visited[a] == visitCnt) return false;

    visited[a] = visitCnt;

    for(auto b : adjList[a]) {
        if(bMatch[b] == -1 || dfs(bMatch[b])) {
            aMatch[a] = b;
            bMatch[b] = a;

            return 1;
        }
    }

    return 0;
}

int bipartiteMatch() {
    aMatch = vector<int>(N+1,-1);
    bMatch = vector<int>(M+1,-1);
    visited = vector<int>(N+1, 0);

    int _size = 0;

    for(int start = 1; start <= N; start ++) {
        visitCnt++;
        _size += dfs(start);
    }

    return _size;
}

int main()
{

    scanf("%d %d",&N, &M);
    adjList.resize(N+1);
    for(int i=1; i<=N; i++) {
        static int x;
        scanf("%d",&x);
        while(x--) {
            static int y;
            scanf("%d",&y);
            adjList[i].push_back(y);
        }
    }

    printf("%d",bipartiteMatch());

    return 0;
}
