#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector < vector <int> > adj;
vector < vector <int> > T;
vector < int > loc;
vector < int > jump;
vector < int > type;
int N;
const int MOD = 1000;

int f(int x,int y) {
    int& ret = T[x][y];
    if(ret != -1) return ret;
    ret = 0;
    if(x != N-1 && y != N-1) {
        if(adj[N-1][x] && adj[y][N-1]) ret = 1;
    }
    for(int i = max(x,y)+1; i<N; i++ ) {
        if(adj[i][x])
            ret += f(i,y);
        ret %= MOD;
        if(adj[y][i])
            ret += f(x,i);
        ret %= MOD;
    }
    return ret;
}

int main()
{

    cin >> N;
    adj.resize(N+1,vector<int>(N+1,0));
    T.resize(N+1,vector<int>(N+1,-1));
    loc.resize(N+1,0);
    jump.resize(N+1,0);
    type.resize(N+1,0);

    for(int i=0; i<N; i++)
        cin >> loc[i] >> jump[i] >> type[i];
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if(abs(loc[i] - loc[j]) <= jump[i] && !((i > j) && !type[i]))
                adj[i][j] = 1;

    cout << f(0,0);

    return 0;
}
