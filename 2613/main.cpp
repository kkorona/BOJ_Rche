#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();

    int lo=1,hi=30001;
    int marble[301];
    int N,M,ans;
    cin >> N >> M;

    for(int i=0; i<N; i++) {
        cin >> marble[i];
        lo = max(lo, marble[i]);
    }

    while(lo<=hi) {
        int mid = (lo+hi)/2;

        int cnt = 0, sum = 0;
        for(int i=0; i<N; i++) {
            if(sum + marble[i] > mid) {
                cnt++;
                sum = marble[i];
            }
            else {
                sum += marble[i];
            }
        }
        cnt++;
        if(cnt <= M) {
            hi = mid - 1;
            ans = mid;
        }
        else {
            lo = mid + 1;
        }
    }
    cout << ans <<"\n";
    int sum = 0, cnt = 0;
    vector < int > ret;
    for(int i=0; i<N; i++) {
        if(sum + marble[i] > ans) {
            ret.push_back(cnt);
            sum = marble[i];
            cnt = 1;
        }
        else {
            cnt++;
            sum += marble[i];
        }
    }
    ret.push_back(cnt);
    if(ret.size() < M) {
        vector <int> temp;
        while(ret.size() + temp.size() < M) {
            int cur = ret.back();
            ret.pop_back();
            while(cur > 0 && ret.size() + temp.size() < M) {
                cur--;
                temp.push_back(1);
            }
        }

        ret.insert(ret.end(),temp.begin(),temp.end());
    }

    for(int a : ret) cout << a << " ";

    return 0;
}
