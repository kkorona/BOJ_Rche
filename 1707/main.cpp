#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

vector <int > List[20005];
queue <int > Q;

int visit[20005],Case;

void bfs(int start) {
    visit[start]=1;
    Q.push(start);
    while(!Q.empty()) {
        int index=Q.front();
        //printf("%d ",index);
        for(int i=0; i<List[index].size(); i++) {
            int tar=List[index][i];
            if(visit[tar] == 0) {
                visit[tar]=-visit[index];
                Q.push(tar);
            }
            else if(visit[tar] == visit[index]) {
                Case=0; return;
            }
        }
        Q.pop();
    }
}

int main()
{
    int cnt,V=0,E,T;

    scanf("%d",&T);

    for(;T>0; T--) {
        cnt=0;
        Case=1;
        for(int i=1; i<=V; i++)
            List[i].erase(List[i].begin(),List[i].end());
        memset(visit,0,sizeof(visit));
        scanf("%d %d",&V,&E);
        for(int i=0; i<E; i++) {
            int a,b;
            scanf("%d %d",&a,&b);
            List[a].push_back(b);
            List[b].push_back(a);
        }
        for(int i=1; i<=V; i++) {
            if(visit[i] == 0) bfs(i);
        }
        printf("%s\n",Case==1?"YES":"NO");
    }
    return 0;
}
