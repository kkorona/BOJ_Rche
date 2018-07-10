#include <iostream>

using namespace std;

int main()
{
    int dx[4]={0,1,0,-1}, dy[4] = {1,0,-1,0};
    int C,R,K;
    cin >> C >> R >> K;
    if(K > R*C) {
        cout << 0;
        return 0;
    }
    int lx=1, mx=C, ly=1, my=R;
    int y=1,x=1;
    int i=0;
    for(int cnt=1; cnt<=K; cnt++) {
        if(cnt == K) cout << x << " " << y;
        y+=dy[i]; x+=dx[i];
        if(y > my) {
            y--;
            x++;
            i=(i+1)%4;
            lx++;
        }
        else if(x > mx) {
            x--;
            y--;
            i=(i+1)%4;
            my--;
        }
        else if(y < ly) {
            y++;
            x--;
            i=(i+1)%4;
            mx--;
        }
        else if(x < lx) {
            y++;
            x++;
            i=(i+1)%4;
            ly++;
        }
    }
    return 0;
}
