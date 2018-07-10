#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int N,M;
    cin >> N >> M;
    vector <int> T(N+1,0);
    map <int,int> VIP;
    while(M--) {
        static int x;
        cin >> x;
        VIP[x] = 1;
    }
    T[0] = 1;
    T[1] = 1;
    for(int i=2; i<=N; i++) {
        if(VIP[i] || VIP[i-1]) {
            T[i] = T[i-1];
        }
        else {
            T[i] = T[i-1] + T[i-2];
        }
    }

    cout << T[N];
    return 0;
}
