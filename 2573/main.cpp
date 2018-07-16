#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N,M;
vector < vector < int > > Map;
vector < vector < int > > visit;

const int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};
bool bchk(int lo,int tar,int hi) {
    return lo <= tar && tar < hi;
}

void BFS(int sy,int sx) {
    queue < pair < int,int > > Q;
    visit[sy][sx] = 1;
    Q.push(make_pair(sy,sx));
    while(!Q.empty()) {
        pair < int,int > index = Q.front();
        Q.pop();
        int y = index.first, x=index.second;
        for(int i=0; i<4; i++) {
            int Y = y+dy[i], X = x+dx[i];
            if(bchk(0,Y,N) && bchk(0,X,M) && visit[Y][X] == 0 && Map[Y][X] > 0) {
                visit[Y][X]=1;
                Q.push(make_pair(Y,X));
            }
        }
    }
}

int main()
{
    cin >> N >>M;
    Map.resize(N,vector<int>(M,0));
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin >> Map[i][j];

    int ans = 0, year = 0;

    while(1) {
        bool allmelted = true;
        vector< vector < int > > melt(N,vector<int>(M,0));
        visit.resize(N,vector<int>(M,0));
        int rchk = 0;
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(visit[i][j] == 0 && Map[i][j]) {
                    allmelted = false;
                    BFS(i,j);
                    rchk++;
                }
            }
        }
        if(allmelted) break;
        if(rchk > 1) {
            ans = year;
            break;
        }
        visit.clear();
        year++;

        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(Map[i][j] == 0) continue;
                for(int l = 0; l<4; l++) {
                    int Y = i+dy[l],X = j+dx[l];
                    if(bchk(0,Y,N) && bchk(0,X,M) && Map[Y][X] == 0) melt[i][j]++;
                }
            }
        }

        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                Map[i][j] -= melt[i][j];
                if(Map[i][j] < 0) Map[i][j] = 0;
            }
        }
    }

    cout << ans;
    return 0;
}
