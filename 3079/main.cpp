#include <cstdio>
#include <algorithm>

using namespace std;
int N;
long long M;

long long T[100000];

const long long INF = 1000000000;

bool Decide(long long t) {
    long long ret=M;
    for(int i=0; i<N && ret > 0; i++) {
        ret-=t/T[i];
    }
    //printf("Dec %lld : %lld\n",t,ret);
    if(ret > 0) return false;
    return true;
}

long long Optimize() {
    long long lo=1,hi= INF * INF;
    long long ans=0;
    while(lo <= hi) {
        //printf("%lld %lld\n",lo,hi);
        long long mid=(lo+hi)/2;
        if(Decide(mid)) {
            ans=mid;
            hi=mid-1;
        }
        else lo=mid+1;
    }
    return ans;
}

int main()
{

    scanf("%d%lld",&N,&M);

    for(int i=0; i<N; i++)
        scanf("%lld",&T[i]);

    sort(T,T+N);

    printf("%lld",Optimize());
    return 0;
}
