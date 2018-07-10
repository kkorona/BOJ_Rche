#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int Graph[1005][1005],temp[1005],visit[1005];
int N,M;
bool impossible=false;

vector <int > order;

void dfs(int index) {
    visit[index]=1;
    for(int i=1; i<=N; i++)
        if(visit[i] == 0 && Graph[index][i] == 1)
            dfs(i);
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
        int K;
        scanf("%d",&K);
        for(int j=0; j<K; j++) {
            scanf("%d",&temp[j]);
            for(int k=0; k<j; k++) {
                Graph[temp[k]][temp[j]]=1;
            }
        }
    }

    vector <int > Answer=t_sort();

    for(int i=Answer.size()-1; i>=1; i--)
        for(int j=i-1; j>=0; j--)
            if(Graph[Answer[i]][Answer[j]] == 1)
                impossible=true;

    if(!impossible) {

        for(int i=0; i<Answer.size(); i++)
            printf("%d\n",Answer[i]);
    }
    else printf("0");

    return 0;
}
