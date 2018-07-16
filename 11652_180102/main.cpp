#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    int N, ans=0;
    long long idx;
    map <long long,int> P;
    scanf("%d",&N);
    while(N--) {
        long long x;
        scanf("%lld",&x);
        P[x]++;
        if(P[x] > ans) {
            ans = P[x];
            idx = x;
        }
        else if(P[x] == ans && idx > x) idx = x;
    }
    printf("%lld",idx);

    return 0;
}
