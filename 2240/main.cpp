#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int T,W;
    scanf("%d%d",&T,&W);

    vector < vector < int > > dp1(W+1), dp2(W+1);
    vector < int > jadu1(T+1,0),jadu2(T+2,0);

    for(int i=0; i<=W; i++) {
        dp1[i].resize(T+1,0);
        dp2[i].resize(T+1,0);
    }

    for(int i=1; i<=T; i++) {
        int x;
        jadu1[i]=jadu1[i-1]; jadu2[i]=jadu2[i-1];
        scanf("%d",&x);
        if(x == 1) jadu1[i]++;
        else jadu2[i]++;
    }

    for(int i=1; i<=T; i++) {
        dp1[0][i]=dp1[1][i]=jadu1[i];
        for(int k=1; k<=i; k++)
            dp2[1][i]=max(dp2[1][i],dp1[0][k-1]+jadu2[i]-jadu2[k-1]);
    }
    for(int i=2; i<=W; i++) {
        for(int j=1; j<=T; j++) {
            for(int k=1; k<=j; k++) {
                dp1[i][j]=max(dp1[i][j],dp2[i-1][k-1]+jadu1[j]-jadu1[k-1]);
                dp2[i][j]=max(dp2[i][j],dp1[i-1][k-1]+jadu2[j]-jadu2[k-1]);
            }
        }
    }

    /*
    for(int i=1; i<=W; i++) {
        for(int j=1; j<=T; j++)
            printf("%d ",dp1[i][j]);
        printf("\n");
    }
    printf("\n");
    for(int i=1; i<=W; i++) {
        for(int j=1; j<=T; j++)
            printf("%d ",dp2[i][j]);
        printf("\n");
    }
    */

    printf("%d",max(dp1[W][T],dp2[W][T]));


    return 0;
}
