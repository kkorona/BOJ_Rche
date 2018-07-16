#include <bits/stdc++.h>

using namespace std;

int main()
{
    string input;
    cin >> input;
    map < char,int > freq;
    for(char c : input) {
        freq[c]++;
    }
    int temp = freq['6'] + freq['9'];
    int ans = 0;
    const string ttemp("01234578");
    for(char c : ttemp) {
        ans = max(ans,freq[c]);
    }
    ans = max(ans, (temp+1)/2);
    cout << ans;
    return 0;
}
