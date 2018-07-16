#include <bits/stdc++.h>
using namespace std;

typedef pair <int,int> pii;
#define mp make_pair
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie();

    int T;
    cin >> T;
    while(T--) {
        int n;
        vector < vector < int > > cafes;
        vector < pii > ans;
        cafes.resize(100001);
        vector < int > labels;
        ans.push_back(mp(-1,0));
        cin >> n;
        for(int i=0; i<n; i++) {
            int y,x;
            cin >> x >> y;
            cafes[x].push_back(y);
        }
        for(int i=0; i<100001; i++) {
            if(cafes[i].size() == 0) {
                continue;
            }
            else if(cafes[i].size() == 1) {
                ans.push_back(mp(i,cafes[i][0]));
            }
            else {
                sort(cafes[i].begin(),cafes[i].end());
                int _n = cafes[i].size();
                if(cafes[i].front() == ans.back().second) {
                    for(int j=0; j<_n; j++) ans.push_back(mp(i,cafes[i][j]));
                }
                else {
                    for(int j=_n-1; j>=0; j--) ans.push_back(mp(i,cafes[i][j]));
                }
            }
        }
        int m,k;
        cin >> m;
        while(m--) {
            cin >> k;
            cout << ans[k].first << " " << ans[k].second << "\n";
        }
    }

    return 0;
}
