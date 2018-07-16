#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector <int> vertical(6,0);
vector <int> horizental(6,0);
int lshift = 0, rshift = 0;
const int N = 5;
int board[N+1][N+1] = {0,};
map <int, pair<int,int> > location;

int main()
{

    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++) {
            cin >> board[i][j];
            location[board[i][j]] = make_pair(i,j);
        }

    bool flag = false;
    int cur,cnt=0;
    for(int i=1;  i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin >> cur;
            if(flag) continue;
            int y = location[cur].first;
            int x = location[cur].second;
            vertical[y]++;
            horizental[x]++;
            if(x == y)
                lshift++;
            if(x+y == N+1)
                rshift++;
            if(vertical[y] == 5) cnt++;
            if(horizental[x] == 5) cnt++;
            if(lshift == 5) {
                cnt++; lshift = -1;
            }
            if(rshift == 5) {
                cnt++; rshift = -1;
            }
            if(cnt >= 3) {
                cout <<  (i-1)*5 + j << endl;
                flag = true;
            }
        }
    }
    return 0;
}
