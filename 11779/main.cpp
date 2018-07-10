#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector < int > T;
vector < int > LastVisit;
vector < vector <int> > adjMatrix;
int N,M;
const int INF = 1e9;
int main()
{
    cin >> N >> M;
    adjMatrix.resize(N+1,vector<int>(N+1,INF));
    LastVisit.resize(N+1,0);
    T.resize(N+1,INF);
    while(M--) {
        int u,v,c;
        cin >> u >> v >> c;
        adjMatrix[u][v] = min(adjMatrix[u][v],c);
    }

    int start,dest;
    cin >> start >> dest;

    for(int i=1; i<=N; i++) adjMatrix[i][i] = 0;
    T[start] = 0;
    LastVisit[start] = 0;

    queue <int> Q;

    Q.push(start);
    while(!Q.empty()) {
        int index = Q.front();
        Q.pop();
        for(int i=1; i<=N; i++) {
            if(T[i] > T[index] + adjMatrix[index][i]) {
                T[i] = T[index] + adjMatrix[index][i];
                LastVisit[i] = index;
                Q.push(i);
            }
        }
    }

    vector < int > path;
    path.push_back(dest);
    int index = dest;
    while(LastVisit[index] != 0) {
        index = LastVisit[index];
        path.push_back(index);
    }
    reverse(path.begin(),path.end());
    cout << T[dest] << endl << path.size() << endl;
    for(int v : path) cout << v << " ";

    return 0;
}
