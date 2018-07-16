#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int DP[301],Score[301];
    int N;
    cin >> N;
    for(int i=1; i<=N; i++)
        cin >> Score[i];
    DP[0]=0;
    DP[1] = Score[1];
    if(N>2) DP[2] = Score[1]+Score[2];
    for(int i=3; i<=N; i++) {
        DP[i] = max({DP[i-2]+Score[i], DP[i-3]+Score[i-1]+Score[i]});
    }

    cout << DP[N];
    return 0;
}
