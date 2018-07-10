#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string paren;
    cin >> paren;
    int N = paren.length();
    int ans = 0;
    vector <int> val(N,0);
    stack <int> parVal;
    bool illegal = false;
    for(int i=0; i<N; i++) {
        if(paren[i] == '(' || paren[i] == '[') {
            parVal.push(i);
        }
        else if(paren[i] == ')') {
            if(parVal.empty() || paren[parVal.top()] != '(') {
                illegal = true;
                break;
            }
            if(val[parVal.top()] == 0) {
                int temp = parVal.top();
                parVal.pop();
                if(parVal.empty()) ans += 2;
                else val[parVal.top()] += 2;
            }
            else {
                int temp = parVal.top();
                parVal.pop();
                if(parVal.empty()) ans += val[temp] * 2;
                else val[parVal.top()] += val[temp] * 2;
            }
        }
        else if(paren[i] == ']') {
            if(parVal.empty() || paren[parVal.top()] != '[') {
                illegal = true;
                break;
            }
            if(val[parVal.top()] == 0) {
                int temp = parVal.top();
                parVal.pop();
                if(parVal.empty()) ans += 3;
                else val[parVal.top()] += 3;
            }
            else {
                int temp = parVal.top();
                parVal.pop();
                if(parVal.empty()) ans += val[temp] * 3;
                else val[parVal.top()] += val[temp] * 3;
            }
        }
    }
    if(!parVal.empty()) illegal = true;
    if(illegal) {
        cout << 0;
    }
    else cout << ans;
    return 0;
}
