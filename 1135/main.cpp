#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

vector < vector < int > > lower;
vector < int > time;
int ans = 0;
void transfer(int node) {
    priority_queue < int > pq;
    if(lower[node].empty()) {
        time[node] = 0; return;
    }

    for(int v : lower[node]) {
        transfer(v);
        pq.push(time[v]);
    }
    int cnt = 1;
    while(!pq.empty()) {
        time[node] = max(time[node], pq.top() + cnt);
        pq.pop();
        cnt++;
    }
    ans = max(ans,time[node]);
}

int main()
{
    int N,c;
    scanf("%d",&N);
    lower.resize(N);
    time.resize(N,-1);
    scanf("%d",&c);
    for(int i=1; i<N; i++) {
        scanf("%d",&c);
        lower[c].push_back(i);
    }

    transfer(0);

    printf("%d",ans);

    return 0;
}
