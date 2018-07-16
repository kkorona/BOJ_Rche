#include <cstdio>

using namespace std;

#define Min(a,b) (((a)>(b))?(b):(a))

int main()
{
    int D[1001][3]; //D[i][j] : i번째 집을 j번째 색으로 칠할때 최소 비용
    int n,Cost[1001][3]; // D[i][j] = Min(D[i-1][(j+1)%3],D[i-1][(j+2)%3])+Cost[i][j];

    scanf("%d",&n);
    for(int i=0; i<n; i++)
        for(int j=0; j<3; j++)
            scanf("%d",&Cost[i][j]);

    for(int i=0; i<3; i++)
        D[0][i]=Cost[0][i];
    for(int i=1; i<n; i++)
        for(int j=0; j<3; j++) {
            //printf("%d -> %d %d\n",j,(j+1)%3,(j+2)%3);
            D[i][j] = Min(D[i-1][(j+1)%3],D[i-1][(j+2)%3])+Cost[i][j];
        }

   /* for(int i=0; i<n; i++) {
        for(int j=0; j<3; j++)
            printf("%d ",D[i][j]);
        printf("\n");
    }*/

    int ans=0x7ffffff;
    for(int i=0; i<3; i++)
        ans=Min(ans,D[n-1][i]);

    printf("%d",ans);


    return 0;
}
