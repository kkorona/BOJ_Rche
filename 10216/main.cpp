#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

#define rchk(n,lim) (n>=0 && n<lim)
#define square(x) ((x)*(x))
#define gap(a,b) ((a>b)?(a-b):(b-a))
#define sq_dist(a,b,c,d) (square(gap(a,b))+square(gap(c,d)))

int T,N,group;
bool Graph[3005][3005],visit[3005];

queue <int > Q;

void bfs(int start) {

    Q.push(start);
    visit[start]=1;
    while(!Q.empty()) {
        int index=Q.front();
        for(int i=0; i<N; i++) {
            if(Graph[index][i] == 1 && visit[i] == 0) {
                visit[i]=1;
                Q.push(i);
            }
        }
        Q.pop();
    }
}

int main()
{
    int y[3005],x[3005],r[3005],cnt=1;
    scanf("%d",&T);

    for(;T>0; T--) {
        scanf("%d",&N);
        memset(Graph,0,sizeof(Graph));
        memset(visit,0,sizeof(visit));
        group=0;
        for(int i=0; i<N; i++) {
            scanf("%d %d %d",&y[i],&x[i],&r[i]);

            for(int j=0; j<i; j++) {
                if(square(r[i]+r[j])>=sq_dist(y[i],y[j],x[i],x[j])) {
                    Graph[i][j]=Graph[j][i]=1;
                }
            }
        }
        /*
        for(int i=0; i<N; i++) {
            for(int j=0; j<N;j++)
                printf("%d ",Graph[i][j]);
            printf("\n");
        }
        */

        for(int i=0; i<N; i++)
            if(visit[i] == 0) {
                bfs(i);
                group++;
            }
        printf("%d\n",group);
    }

    return 0;
}
