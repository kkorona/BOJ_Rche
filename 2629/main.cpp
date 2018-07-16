#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 500*30;

bool bchk(int lo,int tar,int hi) {
    return lo <= tar && tar <= hi;
}

int main()
{
    int N;
    cin >> N;
    vector < int > dp[2]={vector<int>(INF+1,0),vector<int>(INF+1,0)};
    dp[0][0]=1;
    dp[1][0]=1;
    vector < int > W(N,0);
    for(int i=0; i<N; i++)
        cin >> W[i];
    for(int i=0; i<N; i++) {
        for(int j=0; j<=INF; j++) {
            if(bchk(0,j+W[i],INF) && dp[1-i%2][j] == 1) dp[i%2][j+W[i]] = 1;
        }
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<=INF; j++) {
            if(bchk(0,j-W[i],INF) && dp[1-i%2][j] == 1) dp[i%2][j-W[i]] = 1;
        }
    }

    int K;
    cin >> K;
    while(K--) {
        int x;
        cin >> x;
        string ret = (dp[1-N%2][x]  == 1) ? string("YES") : string("NO");
        cout << ret << " ";
    }
    return 0;
}
