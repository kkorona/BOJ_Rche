#include <cstdio>
#include <queue>

using namespace std;

#define MAX 100001
#define rchk(n,lim) (n>=0 && n<lim)

int visit[MAX],Time[MAX],N,K;

queue <int > Q;

void bfs() {
    int xx[2]={-1,1};
    visit[N]=1;
    Time[N]=0;
    Q.push(N);
    while(!Q.empty()) {
        int index=Q.front();
        //printf("%d\n",index);
        for(int i=index; i<MAX && i!=0; i*=2) {
            if(visit[i] == 0) {
                visit[i]=1;
                Time[i]=Time[index];
                Q.push(i);
            }
        }
        for(int i=0; i<2; i++) {
            int X=xx[i]+index;
            if(rchk(X,MAX) && visit[X]==0) {
                visit[X]=1;
                Time[X]=Time[index]+1;
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

    printf("%d",Time[K]);

    return 0;
}
