#include <cstdio>
#include <map>

using namespace std;

typedef pair<int,int> pii;

int visit[30][30];

int N;
double percent[4];
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

double ans = 0;

double calculate(int turn, int y,int x) {


    if(turn == 0) {
        return 1.0;
    }
    double ret = 0;
    visit[y][x] = 1;

    for(int i=0; i<4; i++) {
        int Y = y + dy[i], X = x + dx[i];
        if(visit[Y][X] == 0) {
            ret += calculate(turn - 1,Y,X) * percent[i];
        }
    }

    visit[y][x] = 0;
    return ret;
}

int main()
{
    scanf("%d",&N);

    int x;
    for(int i=0; i<4; i++) {
        scanf("%d",&x);
        percent[i] = (double)x / 100;
    }

    ans = calculate(N,15,15);

    printf("%.9lf",ans);

    return 0;
}
