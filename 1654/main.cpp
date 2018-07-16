#include <cstdio>

using namespace std;

int LAN[10005],N,K;

int main()
{
    long long lo=0,hi=4294967296LL,ans;
    scanf("%d %d",&K,&N);

    for(int i=0; i<K; i++)
        scanf("%d",&LAN[i]);

    while(lo <= hi) {
        long long mid=(lo+hi)/2;
        int cutted=0;
        for(int i=0; i<K; i++)
            cutted+=LAN[i]/mid;

        if(cutted < N) hi=mid-1;
        else if(cutted >= N) {
            ans=mid;
            lo=mid+1;
        }
    }

    printf("%d",ans);

    return 0;
}
