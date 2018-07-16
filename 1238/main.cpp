#include <cstdio>
#include <queue>

using namespace std;

#define INF 2147483647L
#define __LONG_LONG_MAX__ 9223372036854775807LL

typedef pair<int,int > Edge; // first :dest, second : cost

vector <Edge > List_Exact[1001],List_Oppo[1001];

vector <int > Cost_Exact,Cost_Oppo;
int N,M,X;

vector <int > dijkstra_Exact(int src) {

    vector <int > dist(N+1,INF);
    dist[src]=0;
    priority_queue<pair<int,int > > pq;
    pq.push(make_pair(0,src));
    while(!pq.empty()) {
        int cost=-pq.top().first;
        int here=pq.top().second;
        pq.pop();
        if(dist[here] < cost) continue;
        for(int i=0; i<List_Exact[here].size(); i++) {
            int there=List_Exact[here][i].first;
            int nextDist=cost + List_Exact[here][i].second;
            //printf("%d %d/",here,there);
            if(dist[there] > nextDist) {
                dist[there]=nextDist;
                pq.push(make_pair(-nextDist,there));
            }
        }
    }
    return dist;

}

vector <int > dijkstra_Oppo(int src) {
    vector <int > dist(N+1,INF);
    dist[src]=0;
    priority_queue<pair<int,int > > pq;
    pq.push(make_pair(0,src));
    while(!pq.empty()) {
        int cost=-pq.top().first;
        int here=pq.top().second;
        pq.pop();
        if(dist[here] < cost) continue;
        for(int i=0; i<List_Oppo[here].size(); i++) {
            int there=List_Oppo[here][i].first;
            int nextDist=cost + List_Oppo[here][i].second;
            //printf("%d %d/",here,there);
            if(dist[there] > nextDist) {
                dist[there]=nextDist;
                pq.push(make_pair(-nextDist,there));
            }
        }
    }
    return dist;
}

int main()
{
    scanf("%d%d%d",&N,&M,&X);

    for(int i=0; i<M; i++) {
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        List_Exact[a].push_back(make_pair(b,w));
        List_Oppo[b].push_back(make_pair(a,w));
    }

    Cost_Exact=dijkstra_Exact(X); //printf("\n");
    Cost_Oppo=dijkstra_Oppo(X); //printf("\n");

    int MAXX=-0x7fffffff;
    for(int i=1; i<Cost_Exact.size(); i++) {
        if(MAXX < Cost_Exact[i]+Cost_Oppo[i])
            MAXX= Cost_Exact[i]+Cost_Oppo[i];
        //printf("%d %d // ",Cost_Exact[i],Cost_Oppo[i]);
    }
    //printf("\n");

    printf("%d",MAXX);

    return 0;
}
