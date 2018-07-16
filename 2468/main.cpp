#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector < vector < int > > Map;

bool bchk(int lo,int tar,int hi) {
    return lo <= tar && tar < hi;
}

void BFS(vector < vector < int > >& visit, int sy,int sx,int K) {
    int dy[4] = {-1,1,0,0}, dx[4] = {0,0,-1,1};
    queue < pair < int,int > > Q;
    Q.push(make_pair(sy,sx));
    visit[sy][sx] = 1;
    while(!Q.empty()) {
        pair < int,int > index = Q.front();
        int y=index.first, x = index.second;
        Q.pop();
        for(int i=0; i<4; i++) {
            int Y = y+dy[i], X = x+dx[i];
            if(bchk(0,X,N) && bchk(0,Y,N) && visit[Y][X] == 0 && Map[Y][X] > K) {
                Q.push(make_pair(Y,X));
                visit[Y][X]=1;
            }
        }

    }

}

int main()
{
    cin >> N;
    Map.resize(N,vector<int>(N,0));

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> Map[i][j];

    int ans = 1;
    for(int k=1; k<=100; k++) {
        vector < vector < int > > visit(N,vector<int>(N,0));
        int cnt = 0;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(visit[i][j] == 0 && Map[i][j] > k) {
                    cnt++;
                    BFS(visit,i,j,k);
                }
            }
        }
        ans = max(ans,cnt);
    }

    cout << ans;
    return 0;
}
