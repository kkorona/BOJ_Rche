#include <bits/stdc++.h>

using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false);
    cin.tie();

    int n,c;
    cin >> n >> c;
    vector < long long > a;
    vector < long long > sum(n);
    for(int i=0; i<n; i++) {
        long long x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    sum[0]=a[0];
    for(int i=1; i<n; i++) sum[i] = sum[i-1] + a[i];

    long long ans = sum[n-1];
    for(int i=n-1; i>=0; i++) {
        cout << ans << "\n";
        if(i < c) continue;
        ans = min(ans, sum[i] - sum[i/c-1]);
    }

    cout << ans;

    return 0;
}
