#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector< long long >Liq(N);
    for(long long& v : Liq)
        cin >> v;
    sort(Liq.begin(),Liq.end());
    long long ans = 1e15;
    long long ans1,ans2;
    int l=0, r=N-1;
    while(l < r) {
        if(ans > abs(Liq[l] + Liq[r])) {
            ans = abs(Liq[l] + Liq[r]);
            ans1 = min(Liq[l], Liq[r]);
            ans2 = max(Liq[l], Liq[r]);
        }
        if(Liq[l] + Liq[r] < 0)
            l++;
        else
            r--;
    }
    cout << ans1 << " " << ans2;
}
