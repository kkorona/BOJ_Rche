#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

class Edge {
    public: int dest;
    int cost;

    Edge(int Dest,int Cost) {
        cost=Cost;
        dest=Dest;
    }

};

vector <Edge > List[100001];

int N,visit[100001],D_root[100001],D_Diam[100001],Maximum,Max_point;

void DFS(const int node,int D[]) {
    visit[node]=1;
    if(D[node] > Maximum) {
        Maximum=D[node];
        Max_point=node;
    }
    for(int i=0; i<List[node].size(); i++) {
        Edge k=List[node][i];
        if(visit[k.dest] == 0) {
            D[k.dest]=D[node]+k.cost;
            DFS(k.dest,D);
        }
    }
}

int main()
{

    scanf("%d",&N);


    for(int i=0; i<N; i++) {
        int a,b,w;
        scanf("%d",&a);
        while(1) {
            scanf("%d",&b);
            if(b == -1) break;
            scanf("%d",&w);
            Edge temp(b,w);
            List[a].push_back(temp);
            Edge temp2(a,w);
            List[b].push_back(temp2);
        }
    }

    D_root[1]=0;

    DFS(1,D_root);

    memset(visit,0,sizeof(visit));

    Maximum=0;

    DFS(Max_point,D_Diam);

    printf("%d",Maximum);


    return 0;
}
