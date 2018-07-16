#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    int N,E;
    cin >> N;
    vector < vector <int> > M(N+1,vector<int>(N+1,0));
    vector < vector <int> > T(N+1,vector<int>(N+1,1001));

    cin >> E;
    while(E--) {
        static int u,v;
        cin >> u >> v;
        M[u][v]=1;
        T[u][v]=1;
    }
    for(int k=1; k<=N; k++) {
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=N; j++) {
                T[i][j] = min(T[i][j],T[i][k]+T[k][j]);
            }
        }
    }
    vector < int > ans(N+1,0);
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            if(T[i][j] == 1001 && T[j][i] == 1001) ans[i]++;

    for(int i=1; i<=N; i++)
        cout << ans[i]-1 << "\n";
    return 0;
}
