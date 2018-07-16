#include <iostream>

using namespace std;

int Graph[11][11];
bool visit[11];
int Semi_cost[11];
int N,M;
const int INF = 1000000000;

void DFS(int Node, int Progress, int Cost) {
    //Start from vertex No.1
    visit[Node]=1;
    if(Progress == N) {
        if(Semi_cost[Node] > Cost)
            Semi_cost[Node]=Cost;
        return;
    }
    for(int i=1; i<=N; i++) {
        if(visit[i] == 0 && Graph[Node][i] != INF) {
            visit[i]=true;
            DFS(i,Progress+1, Cost+Graph[Node][i]);
            visit[i]=false;
        }
    }
}

int main()
{
    cin >> N;

    for(int i=1; i<=N; i++) {
        Semi_cost[i]=INF;
        for(int j=1; j<=N; j++) {
            cin >> Graph[i][j];
            if(Graph[i][j] == 0) Graph[i][j]=INF;
        }
    }

    DFS(1,1,0);

    int ans=INF;
    for(int i=2; i<=N; i++) {
        if(Graph[i][1] != INF && ans > Graph[i][1] + Semi_cost[i])
            ans=Graph[i][1] + Semi_cost[i];
    }

    cout << ans;

    return 0;
}
