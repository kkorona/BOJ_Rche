#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    int n;
    cin >> n;
    vector<int> a(n,0);
    for(int& v : a)
        cin >> v;
    string b;
    cin >> b;

    int l = -1e9, r = 1e9;

    for(int i=4; i<n; i++) {
        if(b[i] == '1' && b[i-1] == '0') {
            for(int j=i; j>=i-4; j--) {
                l = max(l,a[j]+1);
            }
        }
        if(b[i] == '0' && b[i-1] == '1') {
            for(int j=i; j>=i-4; j--) {
                r = min(r, a[j]-1);
            }
        }
    }
    cout << l << " " << r;

    return 0;
}
