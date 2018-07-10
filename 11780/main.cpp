#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector < vector < int > > T;
vector < vector < int > > LastVisit;
int N,M;

const int INF = 1e9;

void reconstruct(int u,int v,vector<int>& path) {
    if(LastVisit[u][v] == -1) {
        path.push_back(u);
        if(u!=v) path.push_back(v);
    }
    else {
        reconstruct(u,LastVisit[u][v],path);
        path.pop_back();
        reconstruct(LastVisit[u][v],v,path);
    }
}

int main()
{

    cin >> N >> M;

    T.resize(N+1,vector<int>(N+1,INF));
    LastVisit.resize(N+1,vector<int>(N+1,-1));

    while(M--) {
        int u,v,c;
        cin >> u >> v >> c;
        T[u][v] = min(T[u][v], c);
    }

    for(int i=1; i<=N; i++) T[i][i] = 0;

    for(int k=1; k<=N; k++) {
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=N; j++) {
                if(T[i][j] > T[i][k] + T[k][j])
                {
                    T[i][j] = T[i][k] + T[k][j];
                    LastVisit[i][j] = k;
                }
            }
        }
    }

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cout << T[i][j] << " ";
        }
        cout << endl;
    }

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            vector <int> path;
            stack <int> S;
            if(i != j && T[i][j] != INF) {
                reconstruct(i,j,path);
            }
            cout << path.size();
            for(int v : path) cout << " " << v;
            cout << endl;
        }
    }

    return 0;
}
