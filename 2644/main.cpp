#include <cstdio>
#include <cstring>

#define INF 987654321
using namespace std;

int N;
int Graph[105][105],D[105][105];


int main()
{

    int X,Y,M,p,q;

    memset(D,9999,sizeof(D));
    scanf("%d%d%d%d",&N,&p,&q,&M);

    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            Graph[i][j] = (i==j)?0:INF;

    for(int i=1; i<=M; i++) {
            scanf("%d %d",&X,&Y);
            Graph[X][Y]=1;
            Graph[Y][X]=1;
        }



    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            D[i][j]=Graph[i][j];

    for(int k=1; k<=N; k++)
        for(int i=1; i<=N; i++)
            for(int j=1; j<=N; j++)
                if(D[i][j]>D[i][k]+D[k][j])
                    D[i][j]=D[i][k]+D[k][j];

    printf("%d ",(D[p][q]!=INF) ? D[p][q]:-1);
    return 0;
}

/*

2
1 2
0

*/
