#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector < string > Map;
vector < vector < int > > visit;
int R,C;

bool bchk(int lo,int tar,int hi) {
    return lo <= tar && tar < hi;
}

int DFS(int y,int x) {
    const int dx[4] = {-1,0,0,1}, dy[4] = {0,-1,1,0};
    static map <char,int> used;
    visit[y][x] = 1;
    used[Map[y][x]] = 1;
    int ret = 1;
    for(int i=0; i<4; i++) {
        int Y = y + dy[i], X = x + dx[i];
        if(bchk(0,Y,R) && bchk(0,X,C) && visit[Y][X] == 0 && used[Map[Y][X]] == 0) {
            used[Map[Y][X]]=1;
            visit[Y][X]=1;
            ret = max(ret, DFS(Y,X)+1);
            visit[Y][X]=0;
            used[Map[Y][X]]=0;
        }
    }
    return ret;
}

int main()
{
    cin >> R >> C;

    Map.resize(R,string(""));
    visit.resize(R,vector<int>(C,0));

    for(int i=0; i<R; i++) {
        cin >> Map[i];
    }

    cout << DFS(0,0);

    return 0;
}
