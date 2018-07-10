#include <cstdio>

using namespace std;

int main()
{
    long long x,lo=0,hi=3037000500LL,mid,ans=0;

    scanf("%lld",&x);

    //9223372036854775807

    while(lo<=hi) {
        mid=(lo+hi)/2;
        /*printf("%lld %lld %lld %lld\n",lo,hi,mid,ans);
        printf("%lld %lld\n\n",mid*mid,x);*/
        if(1ULL*mid*mid < 1ULL*x) lo=mid+1;
        else if(1ULL*mid*mid >= 1ULL*x) {
            ans=mid;
            hi=mid-1;
        }
    }


    printf("%lld",ans);

    return 0;
}
