#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class path {
    public:
    long long c;
    int dest;

    path(int mdest,long long mc) {
        dest=mdest;
        c=mc;
    }
};

vector <path > Graph[10001];

int departure,destination;
int N,M;

queue <int > Q;

bool Decide(long long c) {

    bool visit[10001]={0,};
    Q.push(departure);
    visit[departure]=true;
    while(!Q.empty() && !visit[destination]) {
        int index=Q.front();
        Q.pop();
        int _size=Graph[index].size();
        for(int i=0; i<_size; i++) {
            if(visit[Graph[index][i].dest] == false && Graph[index][i].c >= c) {
                Q.push(Graph[index][i].dest);
                visit[Graph[index][i].dest]=true;
            }
        }
    }

    while(!Q.empty()) Q.pop();

    return visit[destination];
}

long long Optimize() {
    long long lo=1, hi=1000000000;
    long long ans=0;
    while(lo<= hi) {
        long long mid = (lo+hi)/2;

        if(Decide(mid)) {
            ans=mid;
            lo=mid+1;
        }
        else hi=mid-1;
    }
    return ans;
}

int main()
{

    scanf("%d%d",&N,&M);

    for(int i=0; i<M; i++) {
        int a,b;
        long long c;
        scanf("%d%d%lld",&a,&b,&c);
        Graph[a].push_back(path(b,c));
        Graph[b].push_back(path(a,c));
    }

    scanf("%d%d",&departure,&destination);

    printf("%lld",Optimize());


    return 0;
}
