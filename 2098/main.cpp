#include <cstdio>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int N;

int U;

const int INF = 2000000000;

int solve(vector < vector <int> >& dp, vector < vector <int> >& Graph, int visit,int currentVertex, bool start=false) {

    //printf("%d / %d Solving\n",visit,currentVertex);

    if(!start && currentVertex == 1 ) {
        return (visit == U) ? (0) : INF;
    }

    if(dp[currentVertex][visit] != -1) return dp[currentVertex][visit];

    int ret=INF;

    for(int i=1; i<=N; i++) {
        if(Graph[currentVertex][i] > 0 && (visit & (1 << i)) == 0) {
            ret=min(ret,Graph[currentVertex][i]+solve(dp,Graph,visit | (1 << i),i));
        }
    }

    dp[currentVertex][visit]=ret;
    return ret;

}

int main()
{


    scanf("%d",&N);
    U=(1 << (N+1))-1;

    vector < vector <int> > Graph(N+1);
    vector < vector <int> > dp(N+1);

    for(int i=0; i<=N; i++)
        Graph[i].resize(N+1,0);

    for(int i=0; i<=N; i++)
        dp[i].resize((1<<(N+1)),-1);

    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++) {
            scanf("%d",&Graph[i][j]);
        }


    printf("%d",solve(dp,Graph,1,1,true));

    return 0;
}
