#include <cstdio>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;

const int INF = 1e9;

class Point {
public:
    int x,y;
    Point(int _y=0, int _x=0) : x(_x),y(_y) {};
};

int getDist(const Point& P1,const Point& P2) {
    return abs(P2.y-P1.y)+abs(P2.x-P1.x);
}


vector < Point > Task;

int dist[1010][1010];
int dp[1010][1010];



int main() {

    int N,W;

    scanf("%d%d",&N,&W);

    Task.push_back(Point(1,1));
    Task.push_back(Point(N,N));
    W+=2;
    for(int i=2; i<W; i++) {
        int y,x;
        scanf("%d%d",&y,&x);
        Task.push_back(Point(y,x));
    }

    for(int i=0; i<W; i++) {
        for(int j=0; j<W; j++) {
            dist[i][j]=getDist(Task[i],Task[j]);
            dp[i][j]=INF;
        }
    }

    dp[0][1]=0;

    for(int i=0; i<W-1; i++) {
        for(int j=1; j<W-1; j++) {
            int k=max(i,j)+1;
            if(dp[k][j] > dp[i][j]+dist[i][k]) {
                dp[k][j]=dp[i][j]+dist[i][k];
            }
            if(dp[i][k] > dp[i][j] + dist[j][k]) {
                dp[i][k]=dp[i][j]+dist[j][k];
            }
        }
    }

    for(int i=0; i<W-1; i++) {
        for(int j=0; j<W-1; j++) {
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }

    int ans=INF;

    for(int i=0; i<W-1; i++) {
        ans=min(ans,dp[W-1][i]);
        ans=min(ans,dp[i][W-1]);
    }

    printf("%d\n",ans);


    return 0;
}
