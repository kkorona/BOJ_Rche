#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int A,B,P,Q;
int state[100001][4];

struct Z {
    int a,b;
};
queue < pair < int,int > > q;

int& D(int a,int b) {
    if(a == 0) return state[b][0];
    if(a == A) return state[b][1];
    if(b == 0) return state[a][2];
    if(b == B) return state[a][3];
    return state[0][2];
}

void push(int a,int b,int d) {
    if(D(a,b) < 2e9) return;
    D(a,b) = d;
    q.push({a,b});
}

int main()
{
    cin >> A >> B >> P >> Q;
    for(int i=0; i<=B; i++)
        for(int j=0; j<4; j++)
            state[i][j] = 2e9;
    push(0,0,0);
    while(!q.empty()) {
        auto current = q.front();
        q.pop();
        int a = current.first, b = current.second, d = D(a,b);
        push(0,b,d+1);
        push(a,0,d+1);
        push(A,b,d+1);
        push(a,B,d+1);
        int v = min(A-a,b);
        push(a+v,b-v,d+1);
        v = min(a,B-b);
        push(a-v,b+v,d+1);
    }
    cout << (D(P,Q) < 2e9 ? D(P,Q) : -1) ;

    return 0;
}
