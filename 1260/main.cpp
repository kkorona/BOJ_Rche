#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
vector <int > Edge[1005];
queue <int > Q;
bool visit[1005];

void DFS(int start) {
    visit[start]=1;
    printf("%d ",start);
    for(int i=0; i<Edge[start].size(); i++)
        if(visit[Edge[start][i]] == 0) DFS(Edge[start][i]);
}
void BFS(int start) {
    Q.push(start);
    visit[start]=1;
    while(!Q.empty()) {
        int x=Q.front();
        printf("%d ",x);
        Q.pop();
        for(int i=0; i<Edge[x].size(); i++)
            if(visit[Edge[x][i]] == 0) {
                visit[Edge[x][i]]=1;
                Q.push(Edge[x][i]);
            }
    }
}
int main()
{
    int V;
    scanf("%d %d %d",&N,&M,&V);

    for(int i=0; i<M; i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        Edge[a].push_back(b);
        Edge[b].push_back(a);
    }
    for(int i=1; i<=N; i++)
        sort(Edge[i].begin(),Edge[i].end());
    DFS(V);
    printf("\n");
    memset(visit,0,sizeof(visit));
    BFS(V);
    return 0;
}

/*

*/
