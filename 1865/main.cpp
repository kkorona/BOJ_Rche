#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class edge {
public:
    int s,e,t;
    edge(int _s,int _e,int _t) : s(_s),e(_e),t(_t) {}
};

const long long LLINF = 1e18;

int main()
{

    int T;
    scanf("%d",&T);
    while(T--) {
        int N,M,W;
        scanf("%d%d%d",&N,&M,&W);

        vector < edge > E;

        for(int i=0; i<M; i++) {
            int s,e,t;
            scanf("%d%d%d",&s,&e,&t);
            E.push_back(edge(s,e,t));
            E.push_back(edge(e,s,t));
        }
        for(int i=0; i<W; i++) {
            int s,e,t;
            scanf("%d%d%d",&s,&e,&t);
            E.push_back(edge(s,e,-t));
        }

        vector < long long > adj(N+1,LLINF);
        adj[1]=0;

        for(int i=1; i<=N; i++) {
            for(int j=0; j<M*2+W; j++) {
                if(adj[E[j].e] > adj[E[j].s]+E[j].t)
                    adj[E[j].e] = adj[E[j].s]+E[j].t;
            }
        }

        int i;
        for(i=0; i<M*2+W; i++) {
            if(adj[E[i].e] > adj[E[i].s] + E[i].t)
                break;
        }
        if(i == M*2+W) printf("NO");
        else printf("YES");
        printf("\n");

    }

    return 0;
}
