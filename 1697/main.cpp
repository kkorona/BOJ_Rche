#include <cstdio>
#include <queue>
using namespace std;

#define rchk(n,lim) (n>=0&&n<=lim)

int visit[100005],cost[100005];
int N,K;

queue <int > Q;

void BFS(int node) {
    visit[node]=1;
    cost[node]=0;
    Q.push(node);
    while(!Q.empty()) {
        int index=Q.front();
        //printf("%d %d\n",index,cost[index]);
        if(index == K) break;
        if(rchk(index+1,100000)&&visit[index+1]==0) {
            Q.push(index+1);
            visit[index+1]=1;
            cost[index+1]=cost[index]+1;
        }
        if(rchk(index-1,100000)&&visit[index-1]==0) {
            Q.push(index-1);
            visit[index-1]=1;
            cost[index-1]=cost[index]+1;
        }
        if(rchk(index*2,100000)&&visit[index*2]==0) {
            Q.push(index*2);
            visit[index*2]=1;
            cost[index*2]=cost[index]+1;
        }
        Q.pop();
    }
}

int main()
{
    scanf("%d %d",&N,&K);

    BFS(N);

    printf("%d",cost[K]);

    return 0;
}
