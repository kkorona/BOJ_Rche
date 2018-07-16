#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector < int > swch(N+1,0);
    vector < int > bulb(N+1,0);
    vector < int > T(N+1,1);
    vector < int > via(N+1,0);
    vector < int > ansPath;

    for(int i=1; i<=N; i++)
        cin >> swch[i];
    int x;
    for(int i=1; i<=N; i++) {
        cin >> x;
        bulb[x] = i;
    }

    int ans = 0,start;

    for(int i=1; i<=N; i++) {
        for(int j=1; j<i; j++) {
            if(bulb[swch[j]] < bulb[swch[i]] && T[i] < T[j]+1) {
                T[i] = T[j]+1;
                via[i] = j;
            }
        }
        if(ans < T[i]) {
            ans = T[i];
            start = i;
        }
    }

    cout << ans << "\n";
    ansPath.push_back(swch[start]);
    while(via[start] != 0) {
        ansPath.push_back(swch[via[start]]);
        start = via[start];
    }

    sort(ansPath.begin(),ansPath.end());
    for(int v : ansPath)
        cout << v << " ";

    return 0;
}
