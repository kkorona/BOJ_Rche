#include <cstdio>
#include <queue>

using namespace std;

#define rchk(x,lim) (x>=0&&x<lim) //경계검사

queue <pair <int,int > > Q;

int N,M,sy,sx,dy,dx;
char Map[505][505];
bool visit[505][505];

bool bfs() { // 해당 지점까지 갈 수 있는가?
    Q.push(make_pair(sy,sx));
    int yy[4]={-1,1,0,0},xx[4]={0,0,-1,1};
    bool ans=false;

    while(!Q.empty()) {
        pair <int,int > index=Q.front();
        int y=index.first,x=index.second;
        //printf("%d %d\n",y,x);
        for(int i=0; i<4; i++) {
            int Y=y+yy[i],X=x+xx[i];
            if(Y == dy && X == dx) ans=true; // 목적지에 도달 가능할 때 true(목적지는 X일 수도 있고, .일수도 있음)
            if(rchk(Y,N) && rchk(X,M) && visit[Y][X] == 0 && Map[Y][X] == '.') {
                visit[Y][X]=1;
                Q.push(make_pair(Y,X));
            }
        }
        Q.pop();
    }
    return ans;
}


bool exit_check() { // 해당 지점에서 탈출구로 빠져나갈 수 있는가?
    if(Map[dy][dx] == 'X') return true; // 손상된 빙판길이면 바로 빠질 수 있음
    int yy[4]={-1,1,0,0},xx[4]={0,0,-1,1},check=0;
    for(int i=0; i<4; i++) { // 목표지점이 손상된 빙판길이 아닐 때
        int Y=dy+yy[i],X=dx+xx[i];
        if(rchk(Y,N) && rchk(X,M) && Map[Y][X]=='.') check++; // 주변에 .가 두개 이상이면 탈출가능(들어올 때 한개를 쓰고 나머지를 이용해서)
        else if(rchk(Y,N) && rchk(X,M) && Y == sy && X == sx) check++; //시작점과 출구가 연결상태일때
    }
    return check>1;
}

int main()
{
    scanf("%d %d",&N,&M);

    for(int i=0; i<N; i++)
            scanf("%s",Map[i]);
    scanf("%d%d%d%d",&sy,&sx,&dy,&dx);
    sy--; sx--; dy--; dx--;

    bool a=bfs(),b=exit_check();
    if(a && b) // 해당지점까지 갈 수 있고, 출구가 탈출가능한 조건인가?
        printf("YES");
    else printf("NO");

    return 0;
}
