#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;


int main()
{
    string input;
    map <char,int> M;
    cin >> input;
    int checkSum = 0;
    for(char v : input) {
        M[v]++;
        checkSum += (int)(v-'0');
        checkSum %= 3;
    }
    if(checkSum != 0 || M['0'] == 0) {
        cout << -1;
    }
    else {
        sort(input.begin(),input.end());
        reverse(input.begin(),input.end());
        cout << input;
    }
    return 0;
}
