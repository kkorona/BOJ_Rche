#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N=5,ans=0;
    while(N--) {
        int x;
        cin >> x;
        ans += max(x,40);
    }
    cout << ans/5;
    return 0;
}
