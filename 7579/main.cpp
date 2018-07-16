#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e8;

bool bchk(int lo,int tar,int hi) {
    return lo <= tar && tar < hi;
}

int main()
{
    vector < int > dp[2] = { vector<int>(10001,0), vector<int>(10001,0) };
    vector < int > apps(101,0);
    vector < int > costs(101,0);
    int N,M;
    cin >> N >> M;
    for(int i=1; i<=N; i++)
        cin >> apps[i];
    for(int i=1; i<=N; i++)
        cin >> costs[i];

    for(int i=1; i<=N; i++) {
        for(int j=0; j<=10000; j++) {
            dp[i%2][j]=dp[1-i%2][j];
            if(bchk(0,j-costs[i],10001)) dp[i%2][j] = max(dp[i%2][j],dp[1-i%2][j-costs[i]]+apps[i]);
        }
    }
    for(int i=0; i<=10000; i++) {
        if(dp[N%2][i] >= M) {
            cout << i;
            return 0;
        }
    }
    return 0;
}
