#include <iostream>

using namespace std;

int main()
{
    int x,ans=0;
    for(int i=0; i<5; i++) {
        cin >> x;
        ans+=(x*x);
    }
    cout << ans%10;
    return 0;
}
