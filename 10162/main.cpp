#include <iostream>

using namespace std;

int main()
{
    int button[3] = {300,60,10};
    int ans[3] = {0,0,0};
    int T;

    cin >> T;
    for(int i=0; i<3; i++) {
        ans[i] = T/button[i];
        T %= button[i];
    }
    if(T != 0) cout << "-1";
    else {
        for(int i=0; i<3; i++) {
            cout << ans[i] << " ";
        }
    }
    return 0;
}
