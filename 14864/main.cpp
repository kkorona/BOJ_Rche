#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N,M;

int main()
{
    cin >> N >> M;
    vector < int > P(N,0);
    vector < int > Q(N,0);
    vector < int > ans(N,0);

    for(int i=0; i<M; i++) {
        static int u,v;
        cin >> u >> v;
        Q[u-1]++;
        P[v-1]++;
    }

    for(int i=0; i<N; i++) {
        ans[i] = i - P[i] + Q[i];
    }
    bool flag = true;
    vector <int> temp(ans);
    sort(temp.begin(),temp.end());
    for(int i=0; i<N; i++)
        if(i != temp[i]) flag = false;

    if(flag)
        for(int v : ans) cout << v+1 << " ";
    else
        cout << -1;
    return 0;
}
