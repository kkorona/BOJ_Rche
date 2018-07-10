#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N,M,K,ans=0;
    cin >> N >> M >> K;
    for(int i=N-K, j=M; i<=N; i++, j--) {
        ans = max(ans,min(i/2,j));
    }

    cout << ans;
    return 0;
}
