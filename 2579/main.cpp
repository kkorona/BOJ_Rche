#include <cstdio>

using namespace std;

#define Max(a,b) (((a)>(b))?(a):(b))

int main()
{
    int D[301][2],Score[301]; // D[i][0] : i-1번째 계단에서 오는 최댓값 D[i][1] : i-2번째 계단에서 오는 최댓값
    int n;

    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&Score[i]);
    D[0][1]=0; D[0][0]=0;
    D[1][0]=0; D[1][1]=Score[1];
    for(int i=2; i<=n; i++) {
        D[i][0]=D[i-1][1]+Score[i];
        D[i][1]=Max(D[i-2][0],D[i-2][1])+Score[i];
    }
    printf("%d",Max(D[n][0],D[n][1]));
    return 0;
}
