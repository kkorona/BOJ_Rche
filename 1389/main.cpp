#include <cstdio>
#include <algorithm>

using namespace std;

int Floyd[101][101];
int sum_Floyd[101];
int N,M;


const int INF = 1e9;
int main()
{
    scanf("%d%d",&N,&M);

    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            Floyd[i][j]=INF;

    for(int i=1; i<=N; i++)
        Floyd[i][i]=0;


    for(int i=0; i<M; i++) {
        int st,ed;
        scanf("%d%d",&st,&ed);
        Floyd[st][ed]=1;
        Floyd[ed][st]=1;
    }

    for(int k=1; k<=N; k++) {
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=N; j++) {
                 {
                    if(Floyd[i][j] > Floyd[i][k]+Floyd[k][j]) {
                        Floyd[i][j]=Floyd[i][k]+Floyd[k][j];
                    }
                }
            }
        }
    }

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++)
            sum_Floyd[i]+=Floyd[i][j];
    }

    int Min=INF,ans;
    for(int i=1; i<=N; i++) {
        if(Min > sum_Floyd[i]) {
            Min=sum_Floyd[i];
            ans=i;
        }
    }


    printf("%d",ans);

    return 0;
}
