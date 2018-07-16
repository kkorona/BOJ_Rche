#include <cstdio>

using namespace std;

const long long INF = 2000000000;

int N;
int Height[1000000];
long long M;

bool Decide(long long h) {
    long long wood=0;
    for(int i=0; i<N; i++)
        if(Height[i] > h) wood+=Height[i]-h;
    return wood >=   M;
}

long long Optimize() {
    long long lo=0, hi=INF;

    while(lo+1 < hi) {
        //printf("%lld %lld\n",lo,hi);
        long long mid = (lo+hi)/2;
        if(Decide(mid)) lo = mid;
        else hi = mid;
    }
    return lo;
}

int main()
{
    scanf("%d%lld",&N,&M);

    for(int i=0; i<N; i++)
        scanf("%d",&Height[i]);

    printf("%d",Optimize());

    return 0;
}
