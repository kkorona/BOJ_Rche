#include <iostream>

using namespace std;

int main()
{
    int K;
    cin >> K;
    int a[5];
    int ans=0;
    for(int i=0; i<5; i++) {
        cin >> a[i];
        if(a[i] == K%10) ans++;
    }
    cout <<ans;
    return 0;
}
