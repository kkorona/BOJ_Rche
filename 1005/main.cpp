//BOJ 1005 ACM CRAFT - Topology Sort Solution

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int graph[1001][1001],D[1001],N,K,W;
int visit[1001];
vector <int > Tier[1001];
vector <int > Order;

void dfs(int x) {
    visit[x]=1;
    for(int i=0; i<n; i++)
        if(graph[i][x] == 1 && visit[i] == 0)
            dfs(x);
    Order.push_back(x);
}

vector <int > t_sort(int start) {

    dfs(start);
    reverse(Order.begin(),Order.end());
    return Order;
}

int main()
{

    int T;
    scanf("%d",&T);
    for(;T>0; T--) {
        scanf("%d %d",&N,&K);
        for(int i=0; i<N; i++)
            scanf("%d",&D[i]);
        for(int i=0; i<K; i++) {
            int y,x;
            scanf("%d %d",&y,&x);
            graph[y][x]=1;
        }
        scanf("%d",&W);
        vector <int > temp=t_sort(W);
    }

    return 0;
}
