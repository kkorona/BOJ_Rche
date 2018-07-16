#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    int T;
    cin >> T;
    while(T--) {
        long long d;
        long long x,y;
        cin >> x >> y;
        d = y-x;
        double nn = (sqrt(1.0+4*d)-1)/2;
        //cout << nn << endl;
        long long n = ceil(nn);
        long long st = (n-1)*(n-1)+(n-1);
        long long ed = n*n+n;
        long long mid = (st+ed)/2;
        if(d <= mid) cout << 2*n-1;
        else cout << 2*n;
        cout << "\n";
    }
    return 0;
}
