#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main()
{

    int T;
    scanf("%d",&T);

    while(T--) {

        vector < vector <int > > List;
        vector < int > visit;
        vector < int > colors;

        queue <int> Q;

        int N,M;


        scanf("%d%d",&N,&M);

        List.resize(N+1);
        visit.resize(N+1,0);
        colors.resize(N+1,0);

        for(int i=1; i<=M; i++) {
            int st,ed;
            scanf("%d%d",&st,&ed);
            List[st].push_back(ed);
            List[ed].push_back(st);
        }

        int ans=0;

        for(int i=1; i<=N; i++) {
            if(!visit[i]) {
                if(ans > 2) break;
                Q.push(i);
                visit[i]=1;
                colors[i]=1;
                while(!Q.empty()) {
                    int index=Q.front();
                    //printf("%d ",index);
                    Q.pop();
                    int l=List[index].size();
                    for(int j=0; j<l; j++) {
                        int tar=List[index][j];
                        if(visit[tar] && colors[tar] == colors[index]) ans=3;
                        if(!visit[tar]) {
                            visit[tar]=1;
                            colors[tar]=3-colors[index];
                            Q.push(tar);
                        }
                    }
                }
            }
        }

        printf("%s\n",(ans <= 2) ? "YES":"NO");

    }

    return 0;
}
