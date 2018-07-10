#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define ran_check(n,lim) (n < lim && n >= 0)

int N,M,K,Board[105][105],visit[105][105];

queue <pair <int,int > > Q;

int bfs(int y,int x) {

    int yy[4]={-1,1,0,0},xx[4]={0,0,-1,1},Sq=0;

    visit[y][x]=1;
    Q.push(make_pair(y,x));

    while(!Q.empty()) {
        pair <int,int > index=Q.front();
        Sq++;
        for(int i=0; i<4; i++) {
            int X=index.second+xx[i],Y=index.first+yy[i];
            if(ran_check(X,M) && ran_check(Y,N) && visit[Y][X] == 0) {
                Q.push(make_pair(Y,X));
                visit[Y][X]=1;
            }
        }

        Q.pop();
    }

    return Sq;

}

int main()
{

    vector <int > ans;
    scanf("%d %d %d",&N,&M,&K);

    for(int i=0; i<K; i++) {
        int a,b,c,d;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        for(int j=b; j<d; j++)
            for(int k=a; k<c; k++) {
                Board[j][k]=1;
                visit[j][k]=1;
            }
    }

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            if(visit[i][j] == 0)
                ans.push_back(bfs(i,j));

    sort(ans.begin(),ans.end());

    printf("%d\n",ans.size());
    for(int i=0; i<ans.size(); i++)
        printf("%d ",ans[i]);

    return 0;
}
