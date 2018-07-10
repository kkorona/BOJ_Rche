#include <cstdio>

using namespace std;

const int INF = 100000000;

long long M;
int N;
long long require[10000];

bool Decide(long long budget) {
    long long ret=0;
    for(int i=0; i<N; i++) {
        if(require[i] <= budget) ret+=require[i];
        else ret+=budget;
    }
    return ret <= M;
}

long long Optimize() {
    long long lo=1, hi=INF;
    long long ans;
    while(lo<=hi) {
        //printf("%lld %lld\n",lo,hi);
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
    scanf("%d",&N);
    for(int i=0; i<N; i++)
        scanf("%lld",&require[i]);
    scanf("%lld",&M);

    long long budget=0, Max=0;
    for(int i=0; i<N; i++) {
        budget+=require[i];
        if(Max < require[i]) Max=require[i];
    }

    if(budget <= M) printf("%lld",Max);

    else printf("%lld",Optimize());

    return 0;
}
