#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N,M;
vector < vector < int > > Map;

bool bchk(int lo,int tar,int hi) {
    return lo <= tar && tar < hi;
}

void BFS(vector < vector < int > >& visit, int sy,int sx) {
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
            if(bchk(0,Y,N) && bchk(0,X,M) && visit[Y][X] == 0 && Map[Y][X] == 1) {
                Q.push(make_pair(Y,X));
                visit[Y][X]=1;
            }
        }

    }

}

int main()
{

    int T;
    cin >> T;
    while(T--) {
        int K;
        cin >> M >> N >> K;
        Map.resize(N,vector<int>(M,0));

        while(K--) {
            int y,x;
            cin >> x >> y;
            Map[y][x] = 1;
        }
        vector < vector < int > > visit(N,vector<int>(M,0));
        int cnt = 0;
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(visit[i][j] == 0 && Map[i][j] == 1) {
                    cnt++;
                    BFS(visit,i,j);
                }
            }
        }
        cout << cnt << endl;
        Map.clear();
    }
    return 0;
}
