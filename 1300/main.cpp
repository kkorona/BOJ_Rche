#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long N,k;
    cin >> N >> k;

    long long lo = 1, hi = 1e9;

    while(lo <= hi) {
        long long mid = (lo+hi)/2;
        long long cnt = 0;
        for(long long i=1; i<=N; i++) {
            if(i * N < mid) cnt += N;
            else cnt += mid/i;
        }
        if(cnt < k) lo = mid+1;
        else hi = mid-1;
    }
    cout << lo << endl;
    return 0;
}
