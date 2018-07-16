#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

#define rchk(n,lim) (n>=0&&n<lim)

queue <pair <int,int > > Q;
int Data[105][105],N,M,Melted[105][105],Fin_Hour=0;
bool visit[105][105];

bool C_check(int y,int x) { //Cheese_check
    int yy[4]={-1,1,0,0},xx[4]={0,0,-1,1};
    for(int i=0; i<4; i++) {
        int Y=y+yy[i],X=x+xx[i];
        if(rchk(Y,N) && rchk(X,M) && Data[Y][X] == 0)
            return true;
    }
    return false;
}

void Ans_bfs(int y,int x) {

    Q.push(make_pair(y,x));
    visit[y][x]=1;

    while(!Q.empty()) {
        pair <int,int > index=Q.front();
        int y=index.first,x=index.second;
        int yy[4]={-1,1,0,0},xx[4]={0,0,-1,1};
        for(int i=0; i<4; i++) {
            int Y=y+yy[i],X=x+xx[i];
            if(rchk(X,M) && rchk(Y,N) && Melted[Y][X] == Fin_Hour && visit[Y][X] == 0) {
                visit[Y][X]=1;
                Q.push(make_pair(Y,X));
            }
        }
        Q.pop();
    }

}

bool bfs() {
    bool executed=false;
    while(!Q.empty()) {
        pair <int,int > index=Q.front();
        int y=index.first,x=index.second;
        //printf("%d %d\n",y,x);
        int yy[4]={-1,1,0,0},xx[4]={0,0,-1,1};
        for(int i=0; i<4; i++) {
            int Y=y+yy[i],X=x+xx[i];
            if(rchk(X,M) && rchk(Y,N) && Data[Y][X] == 0 && visit[Y][X] == 0) {
                visit[Y][X]=1;
                Melted[Y][X]=Fin_Hour
                Q.push(make_pair(Y,X));
            }

            else if(rchk(X,M) && rchk(Y,N) && Data[Y][X] == 1 && visit[Y][X] == 0) {
                executed=true;
                Data[Y][X]=0;
                visit[Y][X]=1;
                Melted[Y][X]=Fin_Hour;
            }
        }

        Q.pop();

    }

    return executed;

}

int main()
{

    int Cheese=0;
    scanf("%d %d",&N,&M);


    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            scanf("%d",&Data[i][j]);

    do {
        Fin_Hour++;
        for(int i=0; i<N; i++) {
            Q.push(make_pair(0,i));
            Q.push(make_pair(N-1,i));
        }

        for(int i=1; i<N-1; i++) {
            Q.push(make_pair(i,1));
            Q.push(make_pair(i,N-1));
        }

        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++)
                printf("%d ",Melted[i][j]);
            printf("\n");
        }
        printf("\n");

        memset(visit,0,sizeof(visit));

    }while(bfs());



    memset(visit,0,sizeof(visit));

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            if(Melted[i][j] == Fin_Hour && visit[i][j] == 0) {
                Ans_bfs(i,j);
                Cheese++;
            }

    printf("%d\n%d",Fin_Hour,Cheese);


    return 0;
}
