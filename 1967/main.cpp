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

vector <Edge > List[10001];

int N,visit[10001],D_root[10001],D_Diam[10001],Maximum,Max_point;

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


    for(int i=0; i<N-1; i++) {
        int a,b,w;
        scanf("%d %d %d",&a,&b,&w);
        Edge temp(b,w);
        List[a].push_back(temp);
        Edge temp2(a,w);
        List[b].push_back(temp2);
    }

    D_root[1]=0;

    DFS(1,D_root);

    memset(visit,0,sizeof(visit));

    Maximum=0;

    DFS(Max_point,D_Diam);

    printf("%d",Maximum);


    return 0;
}
