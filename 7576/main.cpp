#include <bits/stdc++.h>
using namespace std;

int N,M;

bool bchk(int lo,int tar,int hi) {
    return lo <= tar && tar < hi;
}

#define mp make_pair
#define pii pair < int,int >

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie();

    cin >> M >> N;
    vector < vector < int > > box(N+1,vector<int>(M+1,0));

    queue < pii > QQ;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> box[i][j];
            if(box[i][j] > 0) QQ.push(mp(i,j));
        }
    }

    int dy[4] = {-1,1,0,0};
    int dx[4] = {0,0,1,-1};

    while(!QQ.empty()) {
        int y = QQ.front().first, x = QQ.front().second;
        QQ.pop();
        for(int i=0; i<4; i++) {
            int Y = y + dy[i], X = x + dx[i];
            if(bchk(0,Y,N) && bchk(0,X,M)) {
                if(box[Y][X] == 0) {
                    box[Y][X] = box[y][x]+1;
                    QQ.push(mp(Y,X));
                }
            }
        }
    }

    int ans = 0;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++) {
            if(box[i][j] == 0) {
                cout << "-1"; return 0;
            }
            ans = max(ans, box[i][j]-1);
        }

    cout << ans;

    return 0;
}
