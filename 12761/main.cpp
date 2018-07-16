#include <cstdio>
#include <queue>
using namespace std;

#define rchk(n,lim) (n>=0&&n<=lim)

int visit[100005],cost[100005];
int N,M,A,B;

queue <int > Q;

void BFS(int node) {
    visit[node]=1;
    cost[node]=0;
    Q.push(node);
    while(!Q.empty()) {
        int index=Q.front();
        //printf("%d %d\n",index,cost[index]);
        if(index == M) break;
        int xx[8]={-1,1,-A,A,-B,B,index*(A-1),index*(B-1)};
        for(int i=0; i<8; i++) {
            if(rchk(index+xx[i],100000)&&visit[index+xx[i]]==0) {
                Q.push(index+xx[i]);
                visit[index+xx[i]]=1;
                cost[index+xx[i]]=cost[index]+1;
            }
        }
        Q.pop();
    }
}

int main()
{
    scanf("%d %d %d %d",&A,&B,&N,&M);

    BFS(N);

    printf("%d",cost[M]);

    return 0;
}
