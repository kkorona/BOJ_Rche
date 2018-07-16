#include <bits/stdc++.h>

using namespace std;

int main()
{
    string input;
    cin >> input;
    int _n = input.size();
    int ans = 0;
    for(int i=0; i<_n; i++) {
        char cur = input[i];
        char next = '.';
        if(i<_n-1) next = input[i+1];
        ans++;
        if(cur == 'c' && next == '=') i++;
        else if(cur == 'c' && next == '-') i++;
        else if(cur == 'd' && next == 'z' && i+2<_n && input[i+2] == '=') i+=2;
        else if(cur == 'd' && next == '-') i++;
        else if(cur == 'l' && next == 'j') i++;
        else if(cur == 'n' && next == 'j') i++;
        else if(cur == 's' && next == '=') i++;
        else if(cur == 's' && next == '=') i++;
        else if(cur == 'z' && next == '=') i++;
    }
    cout << ans;
    return 0;
}
