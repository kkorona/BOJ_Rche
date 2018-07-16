#include <iostream>
#include <vector>
using namespace std;

int p1[15], p2[15];
int gWin[6],gLose[6],gDraw[6];
int win[6],lose[6],draw[6];
bool available;

void backtrack(int cur) {
    if(cur == 15) {
        available = true;
        return;
    }
    int t1 = p1[cur];
    int t2 = p2[cur];
    gWin[t1]++; gLose[t2]++;
    if(gWin[t1] <= win[t1] && gLose[t2] <= lose[t2])
        backtrack(cur+1);
    gWin[t1]--; gLose[t2]--;
    gDraw[t1]++; gDraw[t2]++;
    if(gDraw[t1] <= draw[t1] && gDraw[t2] <= draw[t2])
        backtrack(cur+1);
    gDraw[t1]--; gDraw[t2]--;
    gWin[t2]++; gLose[t1]++;
    if(gWin[t2] <= win[t2] && gLose[t1] <= lose[t1])
        backtrack(cur+1);
    gWin[t2]--; gLose[t1]--;
}

void genScore() {
    available = false;
    for(int i=0; i<6; i++) {
        gWin[i] = 0;
        gDraw[i] = 0;
        gLose[i] = 0;
        if(win[i] + lose[i] + draw[i] != 5) return;
    }
    backtrack(0);
}

int main()
{
    int loop=4,i;
    int cnt = 0;
    for(i=0; i<5; i++)
        for(int j=i+1; j<6; j++) {
            p1[cnt] = i;
            p2[cnt] = j;
            cnt++;
        }
    while(loop--) {
        for(int i=0; i<6; i++)
            cin >> win[i] >> draw[i] >> lose[i];
        int ans = 0;
        genScore();
        if(available)
            ans = 1;
        cout << ans << " ";
    }
    return 0;
}
