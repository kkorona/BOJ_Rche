#include <cstdio>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;

const int MIN = numeric_limits<int>::min();

int Data[110];
int Sum[110];
int T[110][110];
int check[110][110];

int solve(int n, int m) {

    if(m == 0) return 0;
    if(n < 0) return MIN/2;
    if (check[n][m])
        return T[n][m];

    check[n][m] = 1;

    int& r = T[n][m];
    r=solve(n-1,m);

    for(int i=n; i>0; i--)
        r = max(r,solve(i-2,m-1)+Sum[n]-Sum[i-1]);

    return r;
}

int main()
{
    int N,M;
    scanf("%d%d",&N,&M);

    for(int i=1; i<=N; i++) {
        scanf("%d",&Data[i]);
        Sum[i]=Sum[i-1]+Data[i];
    }

    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            T[i][j]=MIN;

    printf("%d",solve(N,M));



    return 0;
}
