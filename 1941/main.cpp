#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

char classroom[5][5];

const int N = 5;

int ans=0;

int dy[4] = {-1,1,0,0}, dx[4] = {0,0,-1,1};

bool rchk(int lo,int tar,int hi) {
    return lo <= tar && tar < hi;
}

pair <int,int> bfs(vector <int>& pick,int start) {
    int nS=0;
    queue <int> Q;
    Q.push(start);
    int afford[25]={0,};
    for(int i=0; i<7; i++) {
        afford[pick[i]]=1;
    }
    afford[start]=0;
    int cnt=0;
    while(!Q.empty()) {
        int index=Q.front();
        cnt++;
        Q.pop();
        int y = index/5, x = index%5;
        if(classroom[y][x] == 'S') nS++;
        for(int i=0; i<4; i++) {
            int Y=y+dy[i],X=x+dx[i];
            int tar = Y*5 + X;
            if(rchk(0,Y,N) && rchk(0,X,N) && afford[tar] == 1) {
                Q.push(tar);
                afford[tar]=0;
            }
        }
    }
    return make_pair(cnt,nS);
}

void get7(vector <int>& pick, int curpick) {
    if(pick.size() == 7) {
        pair <int,int> chk = bfs(pick,pick[0]);
        if(chk.first == 7 && chk.second >= 4) {
            ans++;
        }
    }
    else {
        for(int i=curpick+1; i<25; i++) {
            pick.push_back(i);
            get7(pick,i);
            pick.pop_back();
        }
    }
}

int main() {

    for(int i=0; i<5; i++)
        scanf("%s",classroom[i]);
    vector <int> Ans;
    get7(Ans,-1);

    printf("%d",ans);

    return 0;
}
