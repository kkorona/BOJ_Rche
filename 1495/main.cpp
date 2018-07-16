#include <cstdio>
#include <vector>
using namespace std;

bool bchk(int lo,int tar, int hi) {
    return lo <= tar && tar < hi;
}

int main()
{

    int N,S,M;

    scanf("%d%d%d",&N,&S,&M);
    vector < vector <int> > dp(N+1);
    vector < int > Loudness(N+1);

    for(int i=0; i<=N; i++) dp[i].resize(M+1,0);

    for(int i=1; i<=N; i++) scanf("%d",&Loudness[i]);

    dp[0][S]=1;

    for(int i=1; i<=N; i++) {
        for(int j=0; j<=M; j++) {
            if(bchk(0,j-Loudness[i],M+1) && dp[i-1][j-Loudness[i]] == 1)
                dp[i][j]=1;
            if(bchk(0,j+Loudness[i],M+1) && dp[i-1][j+Loudness[i]] == 1)
                dp[i][j]=1;
        }
    }
    /*
    for(int i=0; i<=N; i++) {
        for(int j=0; j<=M; j++) {
                printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    */

    int ans=-1;
    for(int i=M; i>=0; i--) {
        if(dp[N][i] == 1) {
            ans=i;
            break;
        }
    }


    printf("%d",ans);

    return 0;
}
