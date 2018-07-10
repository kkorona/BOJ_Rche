#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define rchk(n,lim) (n>=0 && n<lim)

int R,C,N,Map[1005][1005],cost[1005][1005],ans=987654321;
int xx[10],yy[10];

queue <pair<int,int > > Q;

void bfs() {
    int success=0,Dest;
    while(!Q.empty()) {
        pair <int,int> index = Q.front();
        if(index.first == R-1) { // 마지막 행의 보도블럭에 도착했을 때 바로 탈출
            Dest=index.second; // 해당 블럭 위치 저장
            success=1;
            break;
        }
        for(int i=0; i<N; i++) {
            int Y=index.first+yy[i],X=index.second+xx[i];
            //경계검사 + 첫번째 행의 블록이 아님 + 세로블록임 + 이전것보다 적은 횟수로 갈 수 있을 때 Queue에 push
            if(rchk(Y,R) && rchk(X,C) && Y > 0 && Map[Y][X] == 1 && cost[Y][X] > cost[index.first][index.second]+1) {
                cost[Y][X]=cost[index.first][index.second]+1;
                Q.push(make_pair(Y,X));
            }
        }
        Q.pop();
    }
    while(!Q.empty()) Q.pop(); // Queue 초기화
    if(success) // 출근 성공시 정답 갱신
        if(cost[R-1][Dest] < ans)
            ans=cost[R-1][Dest];
}

int main()
{

    scanf("%d %d",&R,&C);
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++) {
            scanf("%d",&Map[i][j]);
            cost[i][j]=987654321; // 가중치 초기화
        }

    scanf("%d",&N);
    for(int i=0; i<N; i++)
        scanf("%d %d",&yy[i],&xx[i]);

    for(int i=0; i<C; i++) {
        if(Map[0][i] == 1) {
            Q.push(make_pair(0,i));
            cost[0][i]=0;
        }
    }
    bfs();
    printf("%d",ans==987654321 ? -1:ans);
    return 0;
}
