#include <bits/stdc++.h>
using namespace std;

const int TMAX = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    int T[101][101];
    int n,m;
    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            T[i][j] = TMAX;
        }
    }

    for(int i=0; i<m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        T[u][v] = min(T[u][v],w);
    }

    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                T[i][j] = min(T[i][j], T[i][k] + T[k][j]);
            }
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(T[i][j] == TMAX || i == j) T[i][j] = 0;
            cout << T[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
