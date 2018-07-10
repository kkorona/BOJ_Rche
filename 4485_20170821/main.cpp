#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

bool bchk(int lo,int tar,int hi) {
    return lo <= tar && tar < hi;
}

int main()
{
   int cnt=1;

   int dy[4] = {-1,1,0,0}, dx[4] = {0,0,-1,1};
   int N;
   scanf("%d",&N);
   while(N!=0) {

        vector < vector < int > > Map(N);
        for(int i=0; i < N; i++)
            Map[i].resize(N,0);

        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                scanf("%d",&Map[i][j]);

        vector < vector < int > > adj(N);
        for(int i=0; i < N; i++)
            adj[i].resize(N,INF);

        adj[0][0]=Map[0][0];

        queue < pair < int,int > > Q;

        Q.push(make_pair(0,0));

        while(!Q.empty()) {
            int y = Q.front().first;
            int x = Q.front().second;
            Q.pop();
            for(int i=0; i<4; i++) {
                int Y=y+dy[i], X=x+dx[i];
                if(bchk(0,Y,N) && bchk(0,X,N) && adj[Y][X] > adj[y][x] + Map[Y][X]) {
                    adj[Y][X] = adj[y][x] + Map[Y][X];
                    Q.push(make_pair(Y,X));
                }
            }
        }

        printf("Problem %d: %d\n",cnt++,adj[N-1][N-1]);

        scanf("%d",&N);
   }

    return 0;
}
