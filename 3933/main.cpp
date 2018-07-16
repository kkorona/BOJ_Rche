#include <cstdio>
#include <vector>

using namespace std;

const int lim = (1 << 15);

int main()
{
    vector < vector < int > > dp(5);
    vector < int > Squares;
    for(int i=0; i<=4; i++)
        dp[i].resize(lim+1,0);


    for(int i=1; i*i <= lim; i++) {
        Squares.push_back(i*i);
    }


    int n=Squares.size();


    for(int i=0; i<n; i++) {
        int target = Squares[i];
        dp[1][target]++;
        for(int j=2; j<=4; j++) {
            for(int k=1; k<=lim; k++) {
                if(k+target <= lim && dp[j-1][k] != 0) dp[j][k+target]+=dp[j-1][k];
            }
        }
    }

    int x;
    scanf("%d",&x);
    while(x != 0) {
        int ans=0;
        for(int i=1; i<=4; i++) {
            ans+=dp[i][x];
        }
        printf("%d\n",ans);
        scanf("%d",&x);
    }
    return 0;
}
