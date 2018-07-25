#include <bits/stdc++.h>

using namespace std;

bool ladder[32][11];
int N,M,H;
int start[11];

bool placing(int curRow, int cnt,int limit) {
    bool ret = false;
    if(cnt < limit) {
        for(int i=curRow; i<=N; i++) {
            for(int j=1; j<H; j++) {
                if(!ladder[i][j] && !ladder[i][j-1] && !ladder[i][j+1]) {
                    ladder[i][j] = true;
                    ret = ret || placing(i,cnt+1,limit);
                    ladder[i][j] = false;
                }
            }
        }
    }
    else {
        ret = true;
        for(int i=1; i<=H; i++) start[i] = i;
        for(int i=1; i<=N; i++) {
            for(int j=1; j<H; j++) {
                if(ladder[i][j]) {
                    swap(start[j],start[j+1]);
                }
            }
        }
        for(int i=1; i<=H; i++) ret= ret && (start[i] == i);
    }
    return ret;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    cin >> H >> M >> N;

    int a,b;
    for(int i=0; i<M; i++) {
        cin >> a >> b;
        ladder[a][b] = true;
    }

    int ans = -1;
    for(int i=0; i<4; i++) {
        if(placing(0,0,i)) {
            ans = i;
            break;
        }
    }
    cout << ans;

    return 0;
}
