#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

typedef pair<int,int> pii;

int main()
{
    int T;
    scanf("%d",&T);

    while(T--) {

        int n,d,c;
        scanf("%d%d%d",&n,&d,&c);

        vector < vector < pii > > adjList(n+1);

        for(int i=0; i<d; i++) {
            static int a,b,s;
            scanf("%d%d%d",&a,&b,&s);
            adjList[b].push_back(make_pair(s,a));
        }

        priority_queue < pii, vector<pii>, greater<pii> > pq;
        int time_spend = 0, cnt = 1;
        vector < int > T(n+1,1e9);
        pq.push(make_pair(0,c));
        T[c] = 0;
        while(!pq.empty()) {
            pii cur = pq.top();
            pq.pop();
            int curDist = T[cur.second];
            time_spend = max(time_spend,curDist);
            int curVertex = cur.second;

            for(pii v : adjList[curVertex]) {
                if(curDist + v.first < T[v.second]) {
                    if(T[v.second] == 1e9) cnt++;
                    T[v.second] = curDist + v.first;
                    pq.push(make_pair(T[v.second],v.second));
                }
            }

        }

        printf("%d %d\n",cnt, time_spend);

        adjList.clear();

    }

    return 0;
}
