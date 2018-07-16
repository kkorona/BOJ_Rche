#include <iostream>

using namespace std;

int main()
{
    int N=5;
    int x;
    int ans = 0;
    while(N--) {
        cin >> x;
        ans += x;
    }
    cout << ans;
    return 0;
}
