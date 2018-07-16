#include <iostream>

using namespace std;

int main()
{
    int K,N,M;
    cin >>K >> N >> M;
    int ans=0;
    if(M < K*N) ans = K*N-M;
    cout << ans;
    return 0;
}
