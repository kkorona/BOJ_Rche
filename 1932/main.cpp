#include <cstdio>

using namespace std;

#define Max(a,b) ((a)>(b) ? (a) : (b))

int n,Data[501][501],D[501][501];
int main()
{

    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=i; j++)
        scanf("%d",&Data[i][j]);
    D[1][1]=Data[1][1];
    for(int i=2; i<=n; i++)
        for(int j=1; j<=i; j++)
            D[i][j]=Max(D[i-1][j-1],D[i-1][j])+Data[i][j];
    int ans=-0x7fffffff;
    for(int i=1; i<=n; i++)
        ans=Max(ans,D[n][i]);
    printf("%d",ans);
    return 0;
}
