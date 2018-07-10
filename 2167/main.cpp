#include <cstdio>

using namespace std;

int main()
{
    int N,M,x,y,p,q;
    int Data,Sum[301][301]={0,};

    scanf("%d%d",&N,&M);
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++) {
            scanf("%d",&Data);
            Sum[i][j]=Sum[i-1][j]+Sum[i][j-1]-Sum[i-1][j-1]+Data;
        }

    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d%d%d",&p,&q,&x,&y);
        printf("%d\n",Sum[x][y]-Sum[p-1][y]-Sum[x][q-1]+Sum[p-1][q-1]);
    }
    return 0;
}
