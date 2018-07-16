#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector < vector < int > > lsync,rsync;
vector < vector < int > > adj;
vector <int> aMatch,bMatch;
vector <int> visit;
int visitCnt;
int N;

bool dfs(int a) {
    if(visit[a] == visitCnt)
        return false;
    visit[a] = visitCnt;
    for(int next : adj[a]) {
        if(bMatch[next] == -1 || dfs(bMatch[next])) {
            aMatch[a]=next;
            bMatch[next]=a;
            return true;
        }
    }
    return false;
}

int matching() {
    N=2*N-1;
    aMatch.resize(N+1,-1);
    bMatch.resize(N+1,-1);
    int _size = 0;
    for(int a=1; a<=N; a++) {
        visitCnt++;
        _size += dfs(a);
    }
    return _size;
}

int main() {

    cin >> N;

    lsync.resize(N+1,vector<int>(N+1,0));
    rsync.resize(N+1,vector<int>(N+1,0));
    adj.resize(2*N+1);
    visit.resize(2*N+1,0);

    for(int i=1; i<=2*N-1; i++) {
        for(int y=1, x=i; x>0; y++,x--) {
            if(x > N || y > N || x < 1 || y < 1) continue;
            lsync[y][x]=i;
        }
    }
    for(int i=1; i<=2*N-1; i++) {
        for(int y=N, x=i; x>0; y--,x--) {
            if(x < 1|| y < 1 || x > N || y > N) continue;
            rsync[y][x]=i;
        }
    }

    for(int i=1; i<=N; i++) {
        static int x;
        for(int j=1; j<=N; j++) {
            cin >> x;
            if(x) {
                adj[lsync[i][j]].push_back(rsync[i][j]);
            }
        }
    }
    cout << matching();

    return 0;
}
