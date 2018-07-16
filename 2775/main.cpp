#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector < vector < long long > > dp(15,vector<long long>(15,0));
    for(int i=0; i<15; i++) {
        dp[0][i] = i;
        dp[i][0] = 0;
    }
    int T;
    cin >> T;

    for(int i=1; i<=14; i++) {
        for(int j=1; j<=14; j++) {
            dp[i][j] = dp[i][j-1] + dp[i-1][j];
        }
    }
    for(int i=1; i<=14; i++) {
        for(int j=1; j<=14; j++) {
            dp[i][j] = dp[i][j-1] + dp[i-1][j];
        }
    }
    while(T--) {
        int k,n;
        cin >> k >> n;
        cout << dp[k][n] << endl;
    }
    return 0;
}
