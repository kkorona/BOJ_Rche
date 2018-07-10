#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector < int > dp(N+1,10000);
    dp[3]=1;
    dp[5]=1;
    for(int i=3; i<=N; i++) {
        if(i+3 <= N) dp[i+3]=min(dp[i+3],dp[i]+1);
        if(i+5 <= N) dp[i+5]=min(dp[i+5],dp[i]+1);
    }
    if(dp[N] == 10000) cout << -1;
    else cout << dp[N];
    return 0;
}
