#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

const long long INF = numeric_limits< long long >::max();

long long solve(int st,int ed, vector< vector < long long > >& T, vector < long long >& Sum, vector < long long >& Data) {

    if(T[st][ed] != INF) return T[st][ed];
    if(st == ed) {
        T[st][ed]=0;
        return 0;
    }

    if(st+1 == ed) {
        T[st][ed]=Data[st]+Data[ed];
        return T[st][ed];
    }

    long long ret = INF;

    for(int i=st; i<ed; i++) {
        long long Q = solve(st,i,T,Sum,Data) + solve(i+1,ed,T,Sum,Data) + Sum[ed]-Sum[st-1];
        ret = min(ret,Q);
    }

    T[st][ed]=ret;

    return ret;

}

int main()
{
    int T;

    scanf("%d",&T);

    while(T--) {

        int n;
        scanf("%d",&n);

        vector < long long > Data(n+1,0);
        vector < long long > Sum(n+1,0);
        vector < vector <long long > > T(n+1);

        for(int i=0; i<=n; i++)
            T[i].resize(n+1,INF);

        for(int i=1; i<=n; i++) {
            scanf("%lld",&Data[i]);
            Sum[i]=Sum[i-1]+Data[i];
        }

        printf("%d\n",solve(1,n,T,Sum,Data));
    }
    return 0;
}
