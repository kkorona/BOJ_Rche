#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    long long n,k,A,B;
    cin >> n >> k >> A >> B;

    long long x = n;
    long long ans = 0;
    while(1) {
        long long mod = x - (k * x / k);
        if(k > x) {
            ans += (x-1) * A;
            break;
        }
        if(x % k == 0) {

        }
    }

    cout << ans;

    return 0;
}
