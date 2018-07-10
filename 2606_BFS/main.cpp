#include <cstdio>
#include <queue>

using namespace std;

int N,M;
int Graph[101][101];
int visit[101];

int main()
{
    scanf("%d%d",&N,&M);
    for(int i=0; i<M; i++) {
        int st,ed;
        scanf("%d%d",&st,&ed);
        Graph[st][ed]=1;
        Graph[ed][st]=1;
    }

    queue <int> Q;
    visit[1]=1;
    Q.push(1);
    while(!Q.empty()) {
        int index=Q.front();
        Q.pop();
        for(int i=1; i<=N; i++)
            if(visit[i] == 0 && Graph[index][i] == 1) {
                visit[i]=1;
                Q.push(i);
            }
    }

    int ans=0;
    for(int i=1; i<=N; i++)
        ans+=visit[i];

    printf("%d",ans-1);

    return 0;
}
