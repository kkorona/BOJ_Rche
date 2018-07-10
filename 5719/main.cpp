#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

#define INF 99999999

int N,M,S,D;

typedef pair<int,int > P;

vector <P > List_Exact[501],List_Oppo[501];

vector <int > dijkstra(int src,vector <P > List[]) {
    vector <int > dist(N+1,INF);
    priority_queue <P > pq;
    dist[src]=0;
    pq.push(make_pair(0,src));
    while(!pq.empty()) {
        int cost=-pq.top().first;
        int here=pq.top().second;
        pq.pop();
        for(int i=0; i<List[here].size(); i++) {
            int there=List[here][i].first;
            int nextDist=List[here][i].second + cost;
            if(dist[there] < nextDist) {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist,there));
            }
        }
    }

}

int main()
{

    scanf("%d%d%d%d",&N,&M,&S,&D);

    for(int i=0; i<M; i++) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        List_Exact[a].push_back(make_pair(b,c));
        List_Oppo[b].push_back(make_pair(a,c));
    }

    vector <int > A=dijkstra(S,List_Exact);
    vector <int > B=dijkstra(D,List_Oppo);

    for(int i=0; i<N; i++) {
        vector <int> del_list;
        for(int j=0; j<List_Exact[i].size(); j++) {
            int v=List_Exact[i][j].first;
            int w=List_Exact[i][j].second;
            if(A[D] == A[i]+w+B[v])
                del_list.push_back(j);
        }
        for(int j=del_list.size()-1; j>=0; j--)
            List_Exact[i].erase(List_Exact[i].begin()+del_list[j]);
    }

    vector <int > Ans=dijkstra(S,List_Exact);

    printf("%d",Ans[D]);



    return 0;
}
