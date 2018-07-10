#include <cstdio>

using namespace std;

const int div=1000000000;
int N,K,T[201][201];

int main()
{
    scanf("%d %d",&N,&K);
    for(int i=0; i<=N; i++) T[i][1]=1;
    for(int i=0; i<=K; i++) T[0][i]=1;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=K; j++) {
            T[i][j]=((T[i-1][j]%div)+(T[i][j-1]%div))%div;
        }
    }

    printf("%d",T[N][K]);

    return 0;
}
