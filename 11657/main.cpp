#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

class Edge {
    public:
    int y,x,val;
    Edge(int _y,int _x,int _val) : y(_y),x(_x),val(_val) {}
};

int N,M;

int Graph[501][501];
int adj[501];

const int INF = 1e9;

int main()
{

    scanf("%d%d",&N,&M);
     vector < Edge > E;


    for(int i=1; i<=N; i++)
        adj[i]=INF;

    for(int i=0; i<M; i++) {
        int y,x,val;
        scanf("%d%d%d",&y,&x,&val);
        E.push_back(Edge(y,x,val));
    }


    for(int i=1; i<=N; i++) {
        Graph[i][i]=0;
        for(int j=1; j<=N; j++)
            if(Graph[i][j] != INF)
                E.push_back(Edge(i,j,Graph[i][j]));
    }

    adj[1]=0;

    for(int i=1; i<=N; i++) {
        for(int j=0; j<M; j++) {
            if(adj[E[j].x] > adj[E[j].y] + E[j].val) {
                adj[E[j].x] = adj[E[j].y] + E[j].val;
            }
        }
    }

    for(int i=0; i<M; i++) {
        if(adj[E[i].x] > adj[E[i].y] + E[i].val) {
            printf("-1");
            return 0;
        }
    }

    for(int i=2; i<=N; i++)
        printf("%d\n",(adj[i] != INF) ? adj[i] : -1);

    return 0;
}
