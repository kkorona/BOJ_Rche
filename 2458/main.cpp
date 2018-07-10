#include <iostream>
#include <vector>
using namespace std;

const int INF = 10000;

int main()
{
    int N,M;
    cin >> N >> M;
    vector < vector < int > > T(N+1,vector<int>(N+1,INF));
    while(M--) {
        static int u,v;
        cin >> u >> v;
        T[v][u] = 1;
    }

    for(int k=1; k<=N; k++) {
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=N; j++) {
                T[i][j] = min(T[i][j], T[i][k] + T[k][j]);
            }
        }
    }
    int ans = 0;
    for(int i=1; i<=N; i++) {
        static int cnt;
        cnt = 0;
        for(int j=1; j<=N; j++) {
            if(T[i][j] != INF || T[j][i] != INF) cnt++;
        }
        if(cnt == N-1) ans++;
    }
    cout << ans;
    return 0;
}
