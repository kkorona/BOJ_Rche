#include <bits/stdc++.h>

using namespace std;

int main()
{
    string input;
    cin >> input;
    for(char c='a'; c<='z'; c++) {
        int ret = input.find_first_of(c);
        if(ret == string::npos) ret = -1;
        cout << ret << " ";
    }

    return 0;
}
