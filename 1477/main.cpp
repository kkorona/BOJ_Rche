#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N,M,L;
vector < int > V;

int valid(int k) {
    int ret = 0;
    for(int i=1; i<N+2; i++) {
        ret += (V[i] - V[i-1] - 1)/k;
    }
    return ret;
}

int main()
{
    cin >> N >> M >> L;
    V.resize(N,0);
    for(int i=0; i<N; i++) {
        cin >> V[i];
    }
    V.push_back(0);
    V.push_back(L);
    sort(V.begin(),V.end());

    int lo = 0, hi = 1000;

    while(lo <= hi) {
        int mid = (lo+hi)/2;
        if(valid(mid) > M) lo = mid+1;
        else hi=mid-1;
    }

    cout << lo;

    return 0;
}
