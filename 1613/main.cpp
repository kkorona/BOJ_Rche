#include <cstdio>

using namespace std;

int Floyd[401][401];
int N,M;

const int INF = 1e9;

int main()
{
    scanf("%d%d",&N,&M);

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            Floyd[i][j]=INF;
        }
    }

    for(int i=1; i<=N; i++) {
        Floyd[i][i]=0;
    }

    for(int i=1; i<=M; i++) {
        int st,ed;
        scanf("%d%d",&st,&ed);
        Floyd[st][ed]=1;
    }

    for(int k=1; k<=N; k++) {
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=N; j++) {
                if(Floyd[i][j] > Floyd[i][k]+Floyd[k][j]) {
                    Floyd[i][j]=Floyd[i][k]+Floyd[k][j];
                }
            }
        }
    }

    int T;
    scanf("%d",&T);
    while(T--) {
        int st,ed,ans;
        scanf("%d%d",&st,&ed);
        if(Floyd[st][ed] != INF) ans=-1;
        else if(Floyd[ed][st] != INF) ans=1;
        else ans=0;
        printf("%d\n",ans);
    }

    return 0;
}
