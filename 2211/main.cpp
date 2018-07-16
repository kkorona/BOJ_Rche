#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector < pair <int,int> > ans;
vector < vector < int > > adjMatrix;
vector < vector < int > > used;

int N,M;
const int INF = 1e9;

int main() {

    cin >> N >> M;

    adjMatrix.resize(N+1,vector<int>(N+1,INF));
    used.resize(N+1,vector<int>(N+1,0));
    for(int i=0; i<M; i++) {
        int u,v,c;
        cin >> u >> v >> c;
        adjMatrix[u][v] = c;
        adjMatrix[v][u] = c;
    }

    vector <int> via(N+1,0);
    vector <int> T(N+1,INF);
    queue <int> Q;
    Q.push(1);
    T[1]=0;
    while(!Q.empty()) {
        int index = Q.front();
        Q.pop();
        for(int i=1; i<=N; i++) {
            if(T[i] > T[index] + adjMatrix[index][i]) {
                T[i] = T[index] + adjMatrix[index][i];
                Q.push(i);
                via[i] = index;
            }
        }
    }

    int j;
    for(int i=1; i<=N; i++) {
        j = i;
        while(via[j] != 0) {
            used[j][via[j]] = 1;
            used[via[j]][j] = 1;
            j = via[j];
        }
    }

    for(int i=1; i<N; i++) {
        for(int j=i+1; j<=N; j++) {
            if(used[i][j]) ans.push_back(make_pair(i,j));
        }
    }

    cout << ans.size() << endl;
    for(auto a : ans) cout << a.first << " " << a.second << endl;

    return 0;
}
