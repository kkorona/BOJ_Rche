#include <cstdio>

using namespace std;

long long X,Y;
long long rate;
bool decide(long long m) {
    long long p = ((Y+m)*100)/(X+m);
    //printf("%lld : %lld\n",m,p);
    return rate < p;
}

long long Optimize() {
    long long lo=1,hi=2e9;
    while(lo < hi) {
        //printf("%lld %lld\n",lo,hi);
        long long mid = (lo+hi)/2;
        if(decide(mid)) hi=mid;
        else lo=mid+1;
    }
    return lo;
}

int main()
{
    while(scanf("%lld%lld",&X,&Y) != EOF) {
        rate=(Y*100)/X;
        if(rate >= 99) printf("-1\n");
        else printf("%lld\n",Optimize());
    }


    return 0;
}
