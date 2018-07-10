#include <cstdio>
#include <algorithm>

using namespace std;

const int INF = 1000000000;

long long X[200000];
int N,C;

bool Decide(long long d) {
    int cams=0;
    long long Lim=0;
    for(int i=0; i<N; i++) {
        if(Lim <= X[i]) {
            cams++;
            Lim=X[i]+d;
        }
    }
    return cams >= C;
}

long long Optimize() {
    long long lo=1,hi=INF;
    long long ans=-1;

    while(lo <= hi) {
        long long mid = (lo+hi)/2;
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

    scanf("%d%d",&N,&C);
    for(int i=0; i<N; i++)
        scanf("%lld",&X[i]);

    sort(X,X+N);

    printf("%lld",Optimize());

    return 0;
}
