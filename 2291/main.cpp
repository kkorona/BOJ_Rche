#include <bits/stdc++.h>

using namespace std;

vector < vector < int > > dp;

int N,M,K;

int main()
{
    cin >> N >> M >> K;
    dp.resize(N+1,vector<int>(M+1,0));
    dp[0][0]=1;
    for(int i=1; i<=N; i++) {
        for(int j=i; j<=M; j++) {
            dp[i][j] = dp[i-1][j-1] + dp[i][j-i];
        }
    }
    for(int i=1; N--,M--;) {
        for(;K>dp[N][M];i++) {
            K-=dp[N][M], M-=N+1;
        }
        cout << i << " ";
    }

    return 0;
}
