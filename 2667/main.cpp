#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair <int, int > Point;

queue <Point > Q;

bool visit[27][27];
int Map[27][27];

int bfs(int y,int x,int number) {
    int num_house=0, xx[4]={-1,1,0,0},yy[4]={0,0,-1,1};
    Point Node=make_pair(y,x);

    Q.push(Node);
    visit[Node.first][Node.second]=1;
    while(!Q.empty()) {

        Point index=Q.front();
        Map[index.first][index.second]=number;
        num_house++;

        for(int i=0; i<4; i++) {
            int Y=index.first+yy[i],X=index.second+xx[i];
            if(Map[Y][X] == 1 && visit[Y][X] == 0) {
                visit[Y][X]=1;
                Q.push(make_pair(Y,X));
            }
        }
        Q.pop();
    }
    return num_house;
}

int main()
{
    int N,cnt=0,ans[999];
    char temp[30];
    scanf("%d",&N);

    for(int i=1; i<=N; i++) {
        scanf("%s",temp);
        for(int j=1; j<=N; j++) {
            Map[i][j]=(int)(temp[j-1]-'0');
            if(Map[i][j] == 0) visit[i][j]=1;
        }
    }

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            if(visit[i][j] == 0) {
                ans[cnt]=bfs(i,j,cnt+1);
                cnt++;
            }
        }
    }

    sort(ans,ans+cnt);
    printf("%d\n",cnt);
    for(int i=0; i<cnt; i++)
        printf("%d\n",ans[i]);
    return 0;
}

/*
7
1110100
1110101
1110101
0000111
0110000
1111110
0111000

*/
