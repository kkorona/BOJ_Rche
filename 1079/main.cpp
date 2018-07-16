#include <bits/stdc++.h>

using namespace std;

int state[1<<16];
int score[16];
int R[16][16];
int N;

int target;
int ans = 0;

void bfs() {
    int idx=0;
    queue <int> Q;
    Q.push(idx);

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    fill(state,state+(1<<16),-1);

    cin >> N;

    for(int i=0; i<N; i++)
        cin >> score[i];
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> R[i][j];
    cin >> target;
    target = 1 << (target-1);

    state[0] = 0;
    bfs();

    return 0;
}
