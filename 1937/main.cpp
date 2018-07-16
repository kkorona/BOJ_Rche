#include <iostream>
#include <vector>
using namespace std;

vector < vector < int > > T;
vector < vector < int > > Map;
int N;

const int dy[4] = {-1,1,0,0}, dx[4] = {0,0,-1,1};

bool bchk(int lo,int tar,int hi) {
    return lo <= tar && tar < hi;
}

int dfs(int y,int x) {
    int &ret = T[y][x];
    if(ret == 0) {
        ret = 1;
        for(int i=0; i<4; i++) {
            int Y = y+dy[i], X = x+dx[i];
            if(bchk(0,Y,N) && bchk(0,X,N) && Map[Y][X] < Map[y][x]) {
                ret = max(ret,dfs(Y,X)+1);
            }
        }
    }
    return ret;
}

int main() {

    cin >> N;
    Map.resize(N,vector<int>(N,0));
    T.resize(N,vector<int>(N,0));
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> Map[i][j];
        }
    }
    int ans = 0;

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            dfs(i,j);
            ans = max(ans,T[i][j]);
        }
    }

    cout << ans;

    return 0;
}
