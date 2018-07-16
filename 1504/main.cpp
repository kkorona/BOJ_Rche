#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

#define INF 2147483647L

typedef pair<int,int > P;

vector <int > Cost[4];

vector <P > List[801];

int N,M,Index[4];

vector <int > dijkstra(int src) {
    priority_queue <P > pq;
    vector <int > dist(N+1,INF);
    dist[src]=0;
    pq.push(make_pair(0,src));
    while(!pq.empty()) {
        int cost=-pq.top().first;
        int here=pq.top().second;
        pq.pop();
        for(int i=0; i<List[here].size(); i++) {
            int there=List[here][i].first;
            int nextDist=List[here][i].second+cost;
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

    scanf("%d %d",&N,&M);
    for(int i=0; i<M; i++) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        List[a].push_back(make_pair(b,c));
        List[b].push_back(make_pair(a,c));
    }
    scanf("%d %d",&Index[1],&Index[2]);
    Index[0]=1; Index[3]=N;

    for(int i=0; i<4; i++) {
        Cost[i]=dijkstra(Index[i]);
    }

    int a,b; a=b=-1;
    if(Cost[0][Index[1]] != INF && Cost[1][Index[2]] != INF && Cost[2][Index[3]] != INF)
        a=Cost[0][Index[1]]+Cost[1][Index[2]]+Cost[2][Index[3]];
    if(Cost[0][Index[2]] != INF && Cost[2][Index[1]] != INF && Cost[1][Index[3]] != INF)
        b=Cost[0][Index[2]]+Cost[2][Index[1]]+Cost[1][Index[3]];

    if(b < a) a=b;
    printf("%d",a);

    return 0;
}
