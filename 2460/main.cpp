#include <iostream>

using namespace std;

int main()
{
    int cur = 0,in,out;
    int ans = 0;
    for(int i=1; i<=10; i++) {
        cin >> out >> in;
        cur += in - out;
        ans = max(ans,cur);
    }
    cout << ans;
    return 0;
}
