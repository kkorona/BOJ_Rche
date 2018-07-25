#include <bits/stdc++.h>

using namespace std;
const int LIMIT = 1000000;

set <int> table;

typedef pair <int,int> pii;

void numMake(int n) {
    table.insert(n);
    if(n*10+4 < LIMIT) numMake(n*10+4);
    if(n*10+7 < LIMIT) numMake(n*10+7);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    int N;
    cin >> N;
    numMake(4);
    numMake(7);
    queue <int> Q;
    Q.push(0);
    vector <pii> dp(N+1,{-1,-1});
    int _size = Q.size();
    for(int i=1; !Q.empty(); i++) {
        int _size = Q.size();
        for(int j=0; j<_size; j++) {
            int idx = Q.front(); Q.pop();
            for(const int& q : table) {
                int iidx = idx + q;
                if(iidx > N) continue;
                if(dp[iidx].first == -1) {
                    dp[iidx].first = i;
                    dp[iidx].second = idx;
                    Q.push(iidx);
                }
                else if(dp[iidx].first > dp[idx].first + 1) {
                    dp[iidx].first = dp[idx].first + 1;
                    dp[iidx].second = idx;
                    Q.push(iidx);
                }
            }
        }
    }
    if(dp[N].first == -1) {
        cout << -1;
        return 0;
    }
    vector <int> ans;
    while(dp[N].second != -1) {
        ans.push_back(N-dp[N].second);
        N = dp[N].second;
    }
    reverse(ans.begin(),ans.end());
    for(int ret : ans) cout << ret << " ";

    return 0;
}
