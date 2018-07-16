#include <cstdio>
#include <queue>

using namespace std;

#define rchk(x,lim) (x>=0&&x<lim) //���˻�

queue <pair <int,int > > Q;

int N,M,sy,sx,dy,dx;
char Map[505][505];
bool visit[505][505];

bool bfs() { // �ش� �������� �� �� �ִ°�?
    Q.push(make_pair(sy,sx));
    int yy[4]={-1,1,0,0},xx[4]={0,0,-1,1};
    bool ans=false;

    while(!Q.empty()) {
        pair <int,int > index=Q.front();
        int y=index.first,x=index.second;
        //printf("%d %d\n",y,x);
        for(int i=0; i<4; i++) {
            int Y=y+yy[i],X=x+xx[i];
            if(Y == dy && X == dx) ans=true; // �������� ���� ������ �� true(�������� X�� ���� �ְ�, .�ϼ��� ����)
            if(rchk(Y,N) && rchk(X,M) && visit[Y][X] == 0 && Map[Y][X] == '.') {
                visit[Y][X]=1;
                Q.push(make_pair(Y,X));
            }
        }
        Q.pop();
    }
    return ans;
}


bool exit_check() { // �ش� �������� Ż�ⱸ�� �������� �� �ִ°�?
    if(Map[dy][dx] == 'X') return true; // �ջ�� ���Ǳ��̸� �ٷ� ���� �� ����
    int yy[4]={-1,1,0,0},xx[4]={0,0,-1,1},check=0;
    for(int i=0; i<4; i++) { // ��ǥ������ �ջ�� ���Ǳ��� �ƴ� ��
        int Y=dy+yy[i],X=dx+xx[i];
        if(rchk(Y,N) && rchk(X,M) && Map[Y][X]=='.') check++; // �ֺ��� .�� �ΰ� �̻��̸� Ż�Ⱑ��(���� �� �Ѱ��� ���� �������� �̿��ؼ�)
        else if(rchk(Y,N) && rchk(X,M) && Y == sy && X == sx) check++; //�������� �ⱸ�� ��������϶�
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
    if(a && b) // �ش��������� �� �� �ְ�, �ⱸ�� Ż�Ⱑ���� �����ΰ�?
        printf("YES");
    else printf("NO");

    return 0;
}
