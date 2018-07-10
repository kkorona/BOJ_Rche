#include <cstdio>
#include <cstring>

#define INF 987654321
using namespace std;

int N;
int Graph[105][105],D[105][105];


int main()
{
    memset(D,9999,sizeof(D));
    scanf("%d",&N);

    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++) {
            scanf("%d",&Graph[i][j]);
            if(Graph[i][j] == 0) Graph[i][j]=INF;
        }

    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            D[i][j]=Graph[i][j];

    for(int k=1; k<=N; k++)
        for(int i=1; i<=N; i++)
            for(int j=1; j<=N; j++)
                if(D[i][j]>D[i][k]+D[k][j])
                    D[i][j]=D[i][k]+D[k][j];

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++)
            printf("%d ",(D[i][j]!=INF && D[i][j]!=0) ? 1:0);
        printf("\n");
    }
    return 0;
}
