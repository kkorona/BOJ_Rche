#include <iostream>
#include <vector>
using namespace std;

vector < vector < int > > paper(101,vector<int>(101,0));

bool bchk(int lo,int tar,int hi) {
    return lo <= tar && tar < hi;
}

int main()
{
    int N;
    cin >> N;

    while(N--) {
        int sy,sx;
        cin >> sy >> sx;
        for(int i=sy; i < sy+10; i++) {
            for(int j = sx; j < sx+10; j++) {
                paper[i][j] = 1;
            }
        }
    }

    int dy[4] = {-1,1,0,0};
    int dx[4] = {0,0,1,-1};
    int ans = 0;
    for(int i=0; i<=100; i++) {
        for(int j=0; j<=100; j++) {
            static int Y,X;
            int cnt = 0;
            if(paper[i][j] == 0) continue;
            for(int k=0; k<4; k++) {
                Y = i + dy[k], X = j + dx[k];
                if(bchk(0,Y,101) && bchk(0,X,101)) {
                    if(paper[Y][X] == 0) cnt++;
                }
            }
            ans += cnt;
        }
    }
    cout << ans;

    return 0;
}
