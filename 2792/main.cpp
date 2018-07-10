#include <cstdio>

using namespace std;

long long N,jewels[300005];

int main()
{

    int M;
    long long lo=1,hi=300000*1000000000,ans,temp;

    scanf("%lld %d",&N,&M);
    for(int i=0; i<M; i++) scanf("%lld",&jewels[i]);
    while(lo <= hi) {
        long long mid=(lo+hi)/2,distrib=0,jealous=0;
        for(int i=0; i<M; i++) {
            distrib+=jewels[i]/mid;
            if(jewels[i]%mid != 0) distrib++;
        }

        if(distrib > N) {
            lo=mid+1;
        }
        else {
            ans=mid;
            hi=mid-1;
        }
    }

    printf("%lld",ans);

    return 0;
}
