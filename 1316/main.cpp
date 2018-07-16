#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    int T;
    cin >> T;
    int ans = 0;
    while(T--) {
        string input;
        cin >> input;
        map <char,int> freq;
        bool flag = true;
        int prev = ' ';
        for(char c : input) {
            if(c != prev) {
                prev = c;
                if(freq[prev] != 0) {
                    flag = false;
                    break;
                }
                freq[prev]++;
            }
        }
        if(flag) ans++;
    }
    cout << ans;
    return 0;
}
