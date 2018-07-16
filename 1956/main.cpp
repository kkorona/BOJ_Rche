#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector < vector < int > > adjMatrix;
vector < vector < int > > T;
int N,M;
const int INF = 1e9;
int main()
{
    cin >> N >> M;
    T.resize(N+1,vector<int>(N+1,INF));
    adjMatrix.resize(N+1,vector<int>(N+1,INF));
    while(M--) {
        int u,v,c;
        cin >> u >> v >> c;
        adjMatrix[u][v] = min(adjMatrix[u][v],c);
    }

    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            T[i][j] = adjMatrix[i][j];

    for(int k=1; k<=N; k++) {
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=N; j++) {
                T[i][j] = min(T[i][j],T[i][k]+T[k][j]);
            }
        }
    }

    int ans = INF;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++) {
            ans = min(ans,T[i][j]+adjMatrix[j][i]);
        }

    if(ans == INF) ans = -1;
    cout << ans;
    return 0;
}
