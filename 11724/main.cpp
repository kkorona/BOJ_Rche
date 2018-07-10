#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector <int > List[1005];
queue <int > Q;
bool visit[1005];

void bfs(int Node) {
    int temp;
    Q.push(Node);
    visit[Node]=1;
    while(!Q.empty()) {
        int index=Q.front();
        for(int i=0; i<List[index].size(); i++) {
            temp=List[index][i];
            if(visit[temp] == 0) {
                Q.push(temp);
                visit[temp]=1;
            }
        }
        Q.pop();
    }
}

int main()
{
    int N,M,ans=0;
    scanf("%d %d",&N,&M);

    for(int i=0; i<M; i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        List[a].push_back(b);
        List[b].push_back(a);

    }

    for(int i=1; i<=N; i++) {
        if(visit[i] == 0) {
            bfs(i);
            ans++;
        }
    }

    printf("%d",ans);

    return 0;
}
