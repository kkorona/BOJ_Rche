#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int dy[4] = {-1,1,0,0};
const int dx[4] = {0,0,-1,1};

vector < int > par;
vector < vector < int > > board;
vector < vector < int > > visit;
queue < pair<int,int> > Q;
int N,K;

int Find(int x) {
    return par[x] == x ? x : (par[x]=Find(par[x]));
}

inline int getPar(int y,int x) {
    return (y-1)*N+x;
}

int main()
{
    cin >> N >> K;
    board.resize(N+1,vector<int>(N+1,2e9));
    visit.resize(N+1,vector<int>(N+1,0));
    par.resize(N*N+1,0);
    for(int i=1; i<=N*N; i++)
        par[i] = i;
    for(int i=0; i<K; i++) {
        static int y,x;
        cin >> y >> x;
        board[y][x] = 0; Q.push(make_pair(y,x));
    }

    int ans=0,C=0;
    for(;;ans++) {
        while(!Q.empty()) {
            auto index = Q.front(); Q.pop();
            static int y,x;
            y = index.first;
            x = index.second;
            if(board[y][x] != ans) {
                Q.push(make_pair(y,x));
                break;
            }
            visit[y][x]=1; C++;
            for(int j=0; j<4; j++) {
                int Y = y+dy[j], X=x+dx[j];
                if(Y<1 || Y>N || X<1 || X>N) continue;
                if(visit[Y][X]) {
                    int a = Find(getPar(Y,X)), b = Find(getPar(y,x));
                    if(a != b) C--;
                    par[b] = a;
                }
                else if(board[Y][X] == 2e9) {
                    board[Y][X] = board[y][x] +1;
                    Q.push(make_pair(Y,X));
                }
            }
        }
        if(C == 1) break;
    }
    cout << ans;
    return 0;
}
