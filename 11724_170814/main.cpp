#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector < vector <int > > List;
vector < bool > visit;

int N,M;

queue <int> Q;

int main()
{

    scanf("%d%d",&N,&M);

    List.resize(N+1);
    visit.resize(N+1);

    for(int i=1; i<=M; i++) {
        int st,ed;
        scanf("%d%d",&st,&ed);
        List[st].push_back(ed);
        List[ed].push_back(st);
    }

    int ans=0;

    for(int i=1; i<=N; i++) {
        if(!visit[i]) {
            ans++;
            Q.push(i);
            visit[i]=true;
            while(!Q.empty()) {
                int index=Q.front();
                Q.pop();
                int l=List[index].size();
                for(int j=0; j<l; j++) {
                    int tar=List[index][j];
                    if(!visit[tar]) {
                        visit[tar]=true;
                        Q.push(tar);
                    }
                }
            }
        }
    }

    printf("%d",ans);

    return 0;
}
