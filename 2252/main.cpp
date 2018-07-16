#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int > List[32001];
int visit[32001];
vector <int > order;
int N,M;

void dfs(int index) {
    visit[index]=1;
    for(int i=0; i<List[index].size(); i++) {
        int k=List[index][i];
        if(visit[k] == 0) dfs(k);
    }
    order.push_back(index);
}

vector <int > t_sort() {
    for(int i=1; i<=N; i++)
        if(visit[i] == 0) dfs(i);
    reverse(order.begin(),order.end());
    return order;
}

int main()
{

    scanf("%d %d",&N,&M);

    for(int i=0; i<M; i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        List[a].push_back(b);
    }

    t_sort();
    for(int i=0; i<order.size(); i++)
        printf("%d ",order[i]);

    return 0;
}
