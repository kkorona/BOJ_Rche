#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const long long DIV = 1000000007;

long long dp[101][101][101];

int main()
{

    int N,L,R;

    scanf("%d%d%d",&N,&L,&R);

    dp[1][1][1]=1;
    dp[2][1][2]=1; dp[2][2][1]=1;

    for(int i=3; i<=N; i++) {
        dp[i][1][i]=dp[i][i][1]=1;
        for(int j=1; j<=i; j++) {
            for(int k=1; k<=i; k++) {
                long long& ret=dp[i][j][k];
                ret=dp[i-1][j][k]*(i-2);
                ret=(ret+dp[i-1][j-1][k])%DIV;
                ret=(ret+dp[i-1][j][k-1])%DIV;

            }
        }
    }

    printf("%lld",dp[N][L][R]);

    return 0;
}
