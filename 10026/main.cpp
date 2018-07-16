#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

#define ran_check(n,lim) (n < lim && n >= 0)

typedef pair<int,int > Point;

queue <Point > Q;

int N;
char Map[105][105],Map_RG[105][105];
bool visit[105][105],visit_RG[105][105];

void bfs(int y,int x) {
    int yy[4]={-1,1,0,0},xx[4]={0,0,-1,1};
    Q.push(make_pair(y,x));
    visit[y][x]=1;
    while(!Q.empty()) {
        Point index=Q.front();
        for(int i=0; i<4; i++) {
            int Y=index.first+yy[i],X=index.second+xx[i];
            if(ran_check(Y,N) && ran_check(X,N) && Map[Y][X] == Map[index.first][index.second] && visit[Y][X] == 0) {
                Q.push(make_pair(Y,X));
                visit[Y][X]=1;
            }
        }
        Q.pop();
    }
}

void bfs_RG(int y,int x) {
    int yy[4]={-1,1,0,0},xx[4]={0,0,-1,1};
    Q.push(make_pair(y,x));
    visit_RG[y][x]=1;
    while(!Q.empty()) {
        Point index=Q.front();
        for(int i=0; i<4; i++) {
            int Y=index.first+yy[i],X=index.second+xx[i];
            if(ran_check(Y,N) && ran_check(X,N) && Map_RG[Y][X] == Map_RG[index.first][index.second] && visit_RG[Y][X] == 0) {
                Q.push(make_pair(Y,X));
                visit_RG[Y][X]=1;
            }
        }
        Q.pop();
    }
}

int main()
{

    int ans=0,ans_RG=0;
    char* ptr;
    scanf("%d",&N);

    for(int i=0; i<N; i++) {
        scanf("%s",Map[i]);
        strcpy(Map_RG[i],Map[i]);
        ptr=Map_RG[i];
        while(ptr!=NULL) {
            ptr=strchr(ptr,'G');
            if(ptr!=NULL) *ptr='R';
        }
    }


    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            if(visit[i][j] == 0) {
                bfs(i,j);
                ans++;
            }
            if(visit_RG[i][j] == 0) {
                //printf("%d %d\n",i,j);
                bfs_RG(i,j);
                ans_RG++;
            }
        }

        printf("%d %d",ans,ans_RG);

    return 0;
}
