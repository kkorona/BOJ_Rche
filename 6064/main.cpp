#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    int T;
    cin >> T;
    while(T--) {
        int N,M,x,y;
        cin >> N >> M >> x >> y;
        int k = x;
        bool flag = false;
        for(;k<=N*M; k+=N) {
            if(k % M == y % M) {
                flag = true;
                break;
            }
        }
        if(flag) cout << k << "\n";
        else cout << "-1\n";
    }
    return 0;
}
