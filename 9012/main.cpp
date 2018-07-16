#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    int N;
    cin >> N;
    while(N--) {
        bool iswrong=false;
        string input;
        stack <char> S;
        cin >> input;
        for(char v:input) {
            if(v == '(')
                S.push(v);
            else {
                if(S.empty()) iswrong = true;
                else S.pop();
            }
        }
        if(!S.empty()) iswrong = true;
        if(iswrong) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}
