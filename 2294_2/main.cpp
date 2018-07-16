#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int main()
{
    const int INF=numeric_limits<int>::max();
    int n,k;

    scanf("%d%d",&n,&k);

    vector < int > T(k+1,INF), Coins(n+1,0);

    for(int i=1; i<=n; i++)
        scanf("%d",&Coins[i]);

    sort(Coins.begin(),Coins.end());

    T[0]=0;

    for(int i=1; i<=n; i++) {
        if(Coins[i] > k) continue;

        for(int j=0; j+Coins[i] <= k; j++) {
            if(T[j] != INF && T[j+Coins[i]] > T[j]+1)
                T[j+Coins[i]]=T[j]+1;
        }

    }

    printf("%d",T[k] == INF ? -1 : T[k]);
    return 0;
}
