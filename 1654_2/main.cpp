#include <cstdio>

using namespace std;

int LAN[10000],N,K;

bool Decide(long long d) {
    int ret=0;
    for(int i=0; i<K; i++)
        ret+=LAN[i]/d;
    return ret >= N;
}

long long Optimize() {
    long long lo=1, hi=4294967296LL;
    long long ans;
    while(lo <= hi) {
        //printf("%d %d\n",lo,hi);
        long long mid=(lo+hi)/2;
        if(Decide(mid)) {
            ans=mid;
            lo=mid+1;
        }
        else hi=mid-1;
    }
    return ans;
}

int main()
{

    scanf("%d%d",&K,&N);
    for(int i=0; i<K; i++)
        scanf("%d",&LAN[i]);

    printf("%lld",Optimize());

    return 0;
}
