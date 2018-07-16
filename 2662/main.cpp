#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int B,C;

    scanf("%d%d",&B,&C);

    vector < vector < int > > dp(C+1), Data(C+1);

    for(int i=0; i<=C; i++) {
        dp[i].resize(B+1,0);
        Data[i].resize(B+1,0);
    }

    for(int i=1; i<=B; i++)
        for(int j=0; j<=C; j++)
            scanf("%d",&Data[j][i]);

    for(int i=1; i<=C; i++) {
        for(int j=1; j<=B; j++) {
            for(int k=0; k<=j; k++) {
                dp[i][j]=max(dp[i][j],dp[i-1][k]+Data[i][j-k]);
            }
        }
    }

    printf("%d\n",dp[C][B]);
    vector < int > ans;

    for(int i=C; i>=1; i--) {
        for(int j=B;j>=0; j--) {
            if(dp[i][B] - dp[i-1][j] == Data[i][B-j]) {
                ans.push_back(B-j);
                B=j;
                break;
            }
        }
    }
    for(int i=ans.size()-1; i>=0; i--)
        printf("%d ",ans[i]);

    return 0;
}
