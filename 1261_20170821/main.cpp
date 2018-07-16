#include <cstdio>
#include <queue>
using namespace std;

int N,M;
char Map[101][101];
int dist[101][101];
const int INF = 1e9;

bool bchk(int lo,int tar,int hi) {
    return lo <=tar && tar < hi;
}

void dijkstra(const pair < int,int >& node) {
    queue < pair < int,int > > Q;
    Q.push(node);

    int dy[4]={-1,1,0,0},dx[4]={0,0,-1,1};

    while(!Q.empty()) {
        pair < int,int > index = Q.front();
        Q.pop();

        int y = index.first;
        int x = index.second;

        for(int i=0; i<4; i++) {
            int Y=y+dy[i],X=x+dx[i];
            if(bchk(0,Y,N) && bchk(0,X,M) && dist[Y][X] > dist[y][x] + Map[Y][X] - '0') {
                dist[Y][X] = dist[y][x] + Map[Y][X] - '0';
                Q.push(make_pair(Y,X));
            }
        }
    }
}

int main()
{

    scanf("%d%d",&M,&N);

    for(int i=0; i<N; i++) {
        scanf("%s",Map[i]);
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            dist[i][j] = INF;
        }
    }

    dist[0][0]=0;

    dijkstra(make_pair(0,0));

    printf("%d",dist[N-1][M-1]);

    return 0;
}
