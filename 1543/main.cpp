#include <iostream>
#include <string>

using namespace std;

int main()
{
    int cnt = 0;
    string input, token;
    getline(cin,input);
    getline(cin, token);
    int prev = 0;
    int _size = input.size();
    int _toksize = token.size();
    for(int i=0; i< _size; i++) {
        if(input.substr(i,_toksize).compare(token) == 0) {
            i += _toksize - 1;
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}
