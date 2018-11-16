#include <bits/stdc++.h>

using namespace std;

vector < vector < int > > adj;
vector < vector < int > > SCC;
vector < int > dfsn;
vector < int > visit;
stack < int > stk;
int n,m;
int cnt = 1;
int dfs(int here) {
    stk.push(here);
    dfsn[here] = cnt++;

    int res = dfsn[here];
    for(int there : adj[here]) {
        if(dfsn[there] == 0) {
            res = min(res, dfs(there));
        }
        else if(visit[there] == 0) res = min(res, dfsn[there]);
    }

    // Popping out SCC Components when descendents' maxminum traceback node is here
    if(res == dfsn[here]) {
        vector <int> curSCC;
        while(1) {
            int t = stk.top();
            curSCC.push_back(t);
            visit[t] = 1;
            stk.pop();
            if(t == here) break;
        }
        sort(curSCC.begin(), curSCC.end());
        SCC.push_back(curSCC);
    }
    return res;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    cin >> n >> m;
    adj.resize(n+1);
    dfsn.resize(n+1,0);
    visit.resize(n+1,0);

    for(int i=0; i<m; i++) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for(int i=1; i<=n; i++) {
        if(dfsn[i] == 0) dfs(i);
    }
    sort(SCC.begin(),SCC.end());
    cout << SCC.size() << '\n';
    for(auto& curSCC : SCC) {
        for(int i : curSCC) {
            cout << i << ' ';
        }
        cout << "-1\n";
    }

    return 0;
}
