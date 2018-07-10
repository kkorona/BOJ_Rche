#include <iostream>

using namespace std;

int N,M;
int K;

void next(int& y,int& x) {
    if(y == 0 && x == 0) {
        y=0; x=1;
    }
    else if(y == 0 && x == M) {
        y=1; x=M;
    }
    else if(y == N && x == M) {
        y=N; x=M-1;
    }
    else if(y == N && x == 0) {
        y=N-1; x=0;
    }
    else if(y == 0) x++;
    else if(x == M) y++;
    else if(y == N) x--;
    else y--;
}

int main()
{
    cin >> M >> N;
    cin >> K;
    int p,q;
    int py,px;
    int ps[101],qs[101];
    for(int i=1; i<=K; i++) {
        cin >> ps[i] >> qs[i];
    }
    cin >> p >> q;
    switch(p) {
            case 1 : py=0; px=q; break;
            case 2 : py=N; px=q; break;
            case 3 : py=q; px=0; break;
            case 4 : py=q; px=M; break;
        }
    int ans = 0;
    while(K--) {
        int fy,fx;
        p=ps[K+1],q=qs[K+1];
        switch(p) {
            case 1 : fy=0; fx=q; break;
            case 2 : fy=N; fx=q; break;
            case 3 : fy=q; fx=0; break;
            case 4 : fy=q; fx=M; break;
        }

        int y=py,x=px;
        int dist = 0;
        while(y != fy || x != fx) {
            next(y,x);
            dist++;
        }
        ans += min(dist,2*(N+M)-dist);

    }
    cout << ans;
    return 0;
}
