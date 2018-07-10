#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <queue>
using namespace std;

const int INF = 1e9;
int N,K;
int comparicity(const string& r1,const string& r2) {
    static int diff;
    diff = 0;
    for(int i=0; i<K; i++)
        if(r1[i] != r2[i]) diff++;
    return diff;
}

int main()
{
    cin >> N >> K;
    map <int,string> decode;
    vector < vector < int > > adj(N+1,vector<int>(N+1,INF));
    for(int i=1; i<=N; i++) {
        static string input;
        cin >> input;
        decode[i] = input;
    }
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            if(adj[i][j] != INF) continue;
            string& r1 = decode[i];
            string& r2 = decode[j];
            if(comparicity(r1,r2) == 1) {
                adj[i][j] = 1;
                adj[j][i] = 1;
            }
        }
    }

    int dep,dest;
    cin >> dep >> dest;
    queue <int> Q;
    Q.push(dep);
    vector <int> T(N+1,INF);
    vector <int> via(N+1,0);
    T[dep] = 0;
    while(!Q.empty()) {
        int index = Q.front();
        Q.pop();
        for(int i=1; i<=N; i++) {
            if(T[i] > T[index] + adj[index][i]) {
                T[i] = T[index] + adj[index][i];
                via[i] = index;
                Q.push(i);
            }
        }
    }
    if(T[dest] == INF) cout << -1;
    else {
        vector <int> ans;
        ans.push_back(dest);
        while(via[dest] != 0) ans.push_back(dest=via[dest]);
        reverse(ans.begin(),ans.end());
        for(int v : ans)
            cout << v << " ";
    }
    return 0;
}
