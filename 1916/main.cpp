#include <cstdio>
#include <queue>
#include <vector>
#define MAXV 20001
#define __LONG_LONG_MAX__ 9223372036854775807LL

using namespace std;

vector <int> Graph[MAXV],Cost[MAXV];
queue <int> Queue;


int main()
{
    int V,E,K,Dest;
    long long Shortest_Path[MAXV];
    scanf("%d%d",&V,&E);

    for(int i=0; i<E; i++) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        Graph[u].push_back(v); Cost[u].push_back(w);
    }
    scanf("%d%d",&K,&Dest);

    for(int i=1; i<=V; i++) {
        Shortest_Path[i]=__LONG_LONG_MAX__;
    }

    Queue.push(K);
    Shortest_Path[K]=0;

    while(!Queue.empty()) {
        int S_Vertex=Queue.front();
        for(int i=0; i<Graph[S_Vertex].size(); i++) {
            if(Shortest_Path[Graph[S_Vertex][i]] > Shortest_Path[S_Vertex]+Cost[S_Vertex][i]) {
                Shortest_Path[Graph[S_Vertex][i]] = Shortest_Path[S_Vertex]+Cost[S_Vertex][i];
                Queue.push(Graph[S_Vertex][i]);
            }
        }
        /*for(int i=1; i<=V; i++)
            printf("%d ",Shortest_Path[i]);
        printf("\n");*/
        Queue.pop();
    }

    printf("%d",Shortest_Path[Dest]);


    return 0;
}
