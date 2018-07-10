#include <cstdio>
#include <queue>

using namespace std;

#define rchk(n,lim) (n>=0 && n<lim)
#define MAX 100001

queue <int > Q;

int N,K;
int best_time[MAX];
int visit[MAX];

void bfs() {

    while(!Q.empty()) {
        int index=Q.front();
        int xx[3]={-1,1};
        xx[2]=index;

        //printf("%d %d\n",index,visit[index]);

        /*
        for(int i=1; i<=23; i++)
            printf("%4d ",i);
        printf("\n");
        for(int i=1; i<=23; i++)
            printf("%4d ",visit[i]);
        printf("\n");
        for(int i=1; i<=23; i++)
            printf("%4d ",best_time[i]);
        printf("\n\n");
        char c=getchar();
        */
        if(index != K && best_time[index] < best_time[K])  {
            for(int i=0; i<3; i++) {
                int X=index+xx[i];
                if(rchk(X,MAX)) {
                    if(visit[X] == 0) {
                        visit[X]=visit[index];
                        best_time[X]=best_time[index]+1;
                        Q.push(X);
                    }
                    else if(visit[X] > 0 && best_time[X] == best_time[index]+1) {
                        visit[X]+=visit[index];
                    }
                }
            }
        }
        Q.pop();
    }

}

int main()
{
    scanf("%d %d",&N,&K);

    for(int i=0; i<MAX; i++)
        best_time[i]=MAX;

    best_time[N]=0;
    visit[N]=1;
    Q.push(N);
    bfs();
    printf("%d\n%d",best_time[K],visit[K]);

    return 0;
}
