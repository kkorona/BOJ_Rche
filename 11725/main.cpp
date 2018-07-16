#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector <int > Graph[100005];
queue <int > Q;

int Parent[100005],visit[100005],N;

void bfs(int start) {
    visit[start]=1;
    Q.push(start);
    while(!Q.empty()) {
        int index=Q.front();
        for(int i=0; i<Graph[index].size(); i++)
            if(visit[Graph[index][i]] == 0) {
                visit[Graph[index][i]]=1;
                Parent[Graph[index][i]]=index;
                Q.push(Graph[index][i]);
            }
        Q.pop();
    }
}

int main()
{
    scanf("%d",&N);
    for(int i=0; i<N-1; i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    bfs(1);

    for(int i=2; i<=N; i++)
        printf("%d\n",Parent[i]);
    return 0;
}
