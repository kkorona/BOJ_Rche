#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector < vector <int> > dp(N+1,vector<int>(10,INF));
    vector < vector < pair<int,int> > > via(N+1,vector < pair <int,int > >(10));

    vector <int> init(N+1,0);
    vector <int> target(N+1,0);
    string ini,tar;
    cin >> ini;
    cin >> tar;
    for(int i=0; i<N; i++)
        init[i+1] = (int)ini[i] - '0';
    for(int i=0; i<N; i++)
        target[i+1] = (int)tar[i] - '0';

    for(int i=0; i<10; i++)
        dp[0][i] = 0;
    for(int i=2; i<=N; i++) {
        for(int j=0; j<10; j++) {
            for(int k=0; k<10; k++) {
                if(dp[i][j] > dp[i-1][k])
            }
        }
    }

    return 0;
}
