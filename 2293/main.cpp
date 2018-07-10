#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool bchk(int lo,int tar,int hi) {
    return lo<=tar && tar < hi;
}

int main() {

    int n,k;

    scanf("%d%d",&n,&k);

    vector < vector < int > > T(n+1);
    vector < int > Coins(n+1,0);

    for(int i=0; i<=n; i++)
        T[i].resize(k+1, 0);
    for(int i=1; i<=n; i++)
        scanf("%d",&Coins[i]);

    sort(Coins.begin(),Coins.end());

    for(int i=1; i<=n; i++) {

        for(int j=1; j<=k; j++)
            T[i][j]=T[i-1][j];

        if(Coins[i] > k) continue;

        T[i][Coins[i]]++;

        for(int j=1; j<=k; j++) {

            if(bchk(0,j+Coins[i],k+1) && T[i][j] > 0) {
                T[i][j+Coins[i]]+=T[i][j];
            }
        }
    }

    /*
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=k; j++)
            printf("%d ",T[i][j]);
        printf("\n");
    }
    */

    printf("%d",T[n][k]);

    return 0;
}
