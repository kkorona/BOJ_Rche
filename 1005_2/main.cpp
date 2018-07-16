//BOJ 1005 ACM CRAFT - Dynammic Programming Solution

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 0x7fffffff;

int N,K,W;
int Val[1001][1001],dp[1001],Cost[1001];

int Filling(int Target) {
    if(dp[Target] != -1) return dp[Target];

    int temp=Cost[Target];

    for(int i=1; i<=N; i++) {
        if(Val[i][Target] == 1)
            temp=max(temp,Cost[Target]+Filling(i));
    }

    dp[Target]=temp;
    return temp;

}

int main()
{

    int T;
    scanf("%d",&T);

    while(T--) {

        scanf("%d%d",&N,&K);

        for(int i=1; i<=N; i++)
            scanf("%d",&Cost[i]);

        for(int i=0; i<K; i++) {
            int y,x;
            scanf("%d %d",&y,&x);
            Val[y][x]=1;
        }
        scanf("%d",&W);

        for(int i=1; i<=N; i++) {
            dp[i]=-1;
        }

        printf("%d\n",Filling(W));

        memset(Val,0,sizeof(Val));

    }

    return 0;
}
