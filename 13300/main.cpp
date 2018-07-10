#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    int N,K,ans=0;
    cin >> N >> K;
    int Room[7][2] = {0,};
    for(int i=0; i<N; i++) {
        int Y,S;
        cin >> S >> Y;
        Room[Y][S] ++;
    }
    for(int i=1; i<=6; i++) {
        for(int j=0; j<2; j++) {
            ans += ceil((double)Room[i][j]/K);
        }
    }
    cout << ans;
    return 0;
}
