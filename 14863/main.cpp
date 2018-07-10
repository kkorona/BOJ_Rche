#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    int N,K;
    cin >> N >> K;
    vector < int > T(K+1,0);
    vector < pair < int,int > > walk(N+1);
    vector < pair < int,int > > bicycle(N+1);
    for(int i=1; i<=N; i++) {
        cin >> walk[i].first >> walk[i].second >> bicycle[i].first >> bicycle[i].second;
    }
    for(int i=1; i<=N; i++) {
        for(int j=K; j>=0; j--) {
            T[j] = -1e9-200;
            if(j - walk[i].first >= 0 && T[j] < T[j-walk[i].first] + walk[i].second)
                T[j] = T[j-walk[i].first] + walk[i].second;
            if(j - bicycle[i].first >= 0 && T[j] < T[j-bicycle[i].first] + bicycle[i].second)
                T[j] = T[j-bicycle[i].first] + bicycle[i].second;
        }
    }
    cout << T[K];
    return 0;
}
