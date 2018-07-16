#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 100001
#define rchk(n,lim) (n>=0&&n<lim)

int parent[MAX],visit[MAX];
int N,K;

vector <int > order;
queue <int > Q;

void bfs() {


    visit[N]=1;
    parent[N]=-1;
    Q.push(N);
    while(!Q.empty()) {
        int index=Q.front();
        int xx[3]={-1,1,index};
        for(int i=0; i<3; i++) {
            int X=index+xx[i];
            if(rchk(X,MAX) && visit[X] == 0) {
                visit[X]=1;
                parent[X]=index;
                Q.push(X);
            }
        }
        Q.pop();
    }
}

int main()
{

    scanf("%d %d",&N,&K);

    bfs();

    int index=K;
    while(parent[index]!=-1) {
        order.push_back(index);
        index=parent[index];
    }
    order.push_back(N);

    reverse(order.begin(),order.end());

    printf("%d\n",order.size()-1);
    for(int i=0; i<order.size(); i++)
        printf("%d ",order[i]);

    return 0;
}
