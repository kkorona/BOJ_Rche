#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector <int> Next;
vector <int> ans;
vector <int> visit;
vector<int> temp;
bool dfs(int start, int x) {
    if(visit[x] == 1 && x == start) {
        return true;
    }
    else if(visit[x] == 1) return false;
    else {
        visit[x] = 1;
        if(dfs(start, Next[x])) {
            ans.push_back(x);
            return true;
        }
        else {
            visit[x]=0;
            return false;
        }
    }
}
int main() {
    cin >> N;
    Next.resize(N+1,0);
    visit.resize(N+1,0);
    for(int i=1; i<=N; i++)
        cin>>Next[i];
    for(int i=1; i<=N; i++) {
        if(visit[i] != 0) continue;
        dfs(i,i);
    }
    sort(ans.begin(),ans.end());
    cout << ans.size() << endl;
    for(int v : ans) {
        cout << v << endl;
    }
    return 0;
}
