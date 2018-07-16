#include <bits/stdc++.h>
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie();

    int N,M;
    int board[1001],dice[1001];

    cin >> N >> M;
    for(int i=0; i<N; i++) {
        cin >> board[i];
    }

    for(int i=0; i<M; i++) {
        cin >> dice[i];
    }
    int cur = 0,ans = 0;
    for(int i=0; i<M; i++) {
        cur += dice[i];
        if(cur >= N-1) {
            ans = i+1;
            break;
        }
        cur += board[cur];
        if(cur >= N-1) {
            ans = i+1;
            break;
        }
    }
    cout << ans;

    return 0;
}
