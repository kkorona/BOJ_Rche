#include <cstdio>

using namespace std;

int Board[16][16],Max,ans;

int Ver[16],xpy[31],xmy[31];

int N;

void tracking(int X,int boarded) { // 3 4, 4 3
    int pass;

    if(boarded > N) return;

    if(X== N) {
        if(boarded == N) {
            ans++;
        }
        return;
    }
    for(int i=0; i<N; i++) {

        pass=0;

        if(Ver[i] == 1) pass=1;
        if(xpy[X+i] == 1) pass=1;
        if(xmy[X-i+N] == 1) pass=1;

        if(!pass) {
            Ver[i] = 1 ;
            xpy[X+i] = 1 ;
            xmy[X-i+N] = 1 ;
            Board[X][i]=1;
            tracking(X+1,boarded+1);

            Ver[i] = 0 ;
            xpy[X+i] = 0 ;
            xmy[X-i+N] = 0 ;
            Board[X][i]=0;
        }

    }
}

int main()
{

    scanf("%d",&N);

    tracking(0,0);

    printf("%d\n",ans);

    return 0;
}
