#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    vector <int> cnt(10001,0);
    int N;
    cin >> N;
    int x;
    while(N--) {
        cin >> x;
        cnt[x]++;
    }
    for(int i=0; i<=10000; i++) {
        for(int j=0; j<cnt[i]; j++)
            cout << i << "\n";
    }
    return 0;
}
