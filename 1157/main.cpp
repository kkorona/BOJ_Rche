#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    string input;
    cin >> input;
    map <char,int> freq;
    for(char c : input) {
        if('A' <= c && c <= 'Z') freq[c]++;
        else freq[c-32]++;
    }
    bool multi = false;
    int curMax = 0;
    char ans;
    for(auto const& c : freq) {
        if(c.second > curMax) {
            curMax = c.second;
            multi = false;
            ans = c.first;
        }
        else if(c.second == curMax) {
            multi = true;
        }
    }
    if(multi) cout << "?";
    else cout << ans;
    return 0;
}
