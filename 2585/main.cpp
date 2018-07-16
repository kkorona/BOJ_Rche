#include <bits/stdc++.h>
using namespace std;

class la {
public:
    int x,y;
    la(int x=0,int y=0) : x(x), y(y) {}
};

int N,K;
vector < la > land;

double getdist(la A,la B) {
    return (double)(A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}

bool verify(int curVal) {
    vector < int > dist(N+1,2e9);
    vector < int > q(N+2,0);
    int h,t;
    int val = curVal*10;
    h=t=0;
    dist[0]=0;
    q[t++] = 0;
    while(h!=t) {
        for(int i=1; i<=N; i++) {
            if(dist[i] == 2e9 && getdist(land[i],land[q[h]]) <= val * val ) {
                dist[i]=dist[q[h]]+1;
                q[t]=i;
                t++;
            }
        }
        h++;
    }
    return dist[N] <= K+1;
}

int main() {

    cin >> N >> K;
    land.resize(N+1);

    for(int i=1; i<=N; i++) {
        cin >> land[i].x >> land[i].y;
    }

    land.push_back(la(10000,10000));

    N++;

    int lo = 1, hi = 1415;

    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if(verify(mid)) {
            hi = mid-1;
        }
        else {
            lo = mid+1;
        }
    }

    cout << lo;

    return 0;
}
