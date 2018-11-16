#include <bits/stdc++.h>

using namespace std;

int n;

int adj[1001][1001];
int degree[1001];

vector <int> ret;
vector <int> cur;
int nokori = 0;
bool flag = false;

void dfs(int here) {
    for(int i=1; i<=n; i++) {
        while(adj[here][i]) {
            adj[here][i]--;
            adj[i][here]--;
            dfs(i);
        }
    }
    ret.push_back(here);
}

void dump(const vector<int>& v) {
    for(int i : v) {
        cout << i <<" ";
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> adj[i][j];
            degree[i] += adj[i][j];
        }
    }

    for(int i=1; i<=n; i++) {
        if(degree[i] & 1) {
            cout << "-1";
            return 0;
        }
    }

    dfs(1);
    dump(ret);

    return 0;
}
