#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const long long INF = 100000100;

int n,k;

class point {
    public : long long x,y;

    point(long long _x=0,long long _y=0) : x(_x),y(_y) {}
    bool operator < (const point& rhs) const{
        if( x != rhs.x) return x < rhs.x;
        return false;
    };
};

vector <point > P;

bool Decide(long long m) {
    long long maxy=-INF;
    long long miny=INF;
    int ret=1;
    for(int i=0; i<n; i++) {
        maxy = max(maxy,P[i].y);
        miny = min(miny,P[i].y);
        if(maxy - miny > m) {
            maxy=miny=P[i].y;
            ret++;
        }
    }
    return ret <= k;
}

long long Optimize() {
    long long lo=0, hi=2*INF;
    while(lo < hi) {
        long long mid = (lo+hi)/2;
        if(Decide(mid)) {
            hi=mid;
        }
        else lo=mid+1;
    }
    return lo;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&k);
        for(int i=0; i<n; i++) {
            long long x,y;
            scanf("%lld%lld",&x,&y);
            P.push_back(point(x,y));
        }
        sort(P.begin(),P.end());
        long long ans=Optimize();
        printf("%lld.%lld\n",ans/2,ans%2*5);
        P.erase(P.begin(),P.end());
    }


    return 0;
}
