#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    int N;
    cin >> N;
    while(N--) {
        string input;
        cin >> input;
        int ans = 0, cnt=0;
        for(char c : input) {
            if(c == 'O') cnt++;
            else cnt=0;
            ans += cnt;
        }
        cout << ans << "\n";
    }
    return 0;
}
