#include <cstdio>

using namespace std;

int Data[100005];

int main()
{
    long long lo=1, hi=2147483647,ans;
    int N,M;
    scanf("%d %d",&N,&M);

    for(int i=0; i<N; i++) scanf("%d",&Data[i]);

    while(lo <= hi) {
        long long mid=(lo+hi)/2,time=0;
        int BD=1,under_limit=0;;
        for(int i=0; i<N; i++) {
            if(Data[i] > mid) {
                under_limit=1;
                break;
            }
            else if(time+Data[i] > mid) {
                time=Data[i]; BD++;
            }
            else time+=Data[i];
        }
        if(BD <= M && !under_limit) {
            ans=mid;
            hi=mid-1;
        }
        else lo=mid+1;
    }

    printf("%lld",ans);

    return 0;
}



/*

1 1
1000000000

*/
