#include <cstdio>

using namespace std;

const int INF = 1e9;

int M,N,L,G;
int hor[101][101],ver[101][101],d[101][101][201][2];

void Assign(int& a,int b) {
    if(a > b) a= b;
}

int main()
{
    int t,D;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d%d%d",&N,&M,&L,&G);
        for(int i=0; i<N; i++)
            for(int j=0; j<M-1; j++)
                scanf("%d",&hor[i][j]);
        for(int i=0; i<N-1; i++)
            for(int j=0; j<M; j++)
                scanf("%d",&ver[i][j]);

        for(int i=0; i<=N; i++)
            for(int j=0; j<=M; j++)
                for(int k=0; k<=N+M+2; k++)
                    d[i][j][k][0]=d[i][j][k][1]=INF;
        d[0][0][0][0]=d[0][0][0][1]=0;
        for(int i=0; i<=N; i++)
            for(int j=0; j<=M; j++)
                for(int k=0; k<=i+j+2; k++) {
                    if(i+1<N) {
                        Assign(d[i+1][j][k][0],d[i][j][k][0]+ver[i][j]);
                        Assign(d[i+1][j][k+1][0],d[i][j][k][1]+ver[i][j]);
                    }
                    if(j+1<M) {
                        Assign(d[i][j+1][k][1],d[i][j][k][1]+hor[i][j]);
                        Assign(d[i][j+1][k+1][1],d[i][j][k][0]+hor[i][j]);
                    }
                }
            int ans = -1;
        for (int i = 0; i <= (N+M+2); ++i) {
          if (d[N-1][M-1][i][0] <= G || d[N-1][M-1][i][1] <= G) {
            ans = (N + M - 2)*L  + i;
            break;
          }
        }
        printf("%d\n",ans);
    }
    return 0;
}
