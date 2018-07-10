#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int turn=1;
    long long ans = 1;
    for(int i=0; i<N; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        ans /= a;
        ans *= b;
        if(c == 1) turn = -turn;
    }
    cout << (turn < 0) << " " << ans;
    return 0;
}
