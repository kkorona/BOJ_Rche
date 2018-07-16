#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector <int> L,R;
vector < vector < int > > T;

int f(int y,int x) {
    if(y > N || x > N) return 0;
    if(T[y][x] == -1) {
        T[y][x] = L[y] > R[x] ? f(y,x+1) + R[x] : max(f(y+1,x+1),f(y+1,x));
    }
    return T[y][x];
}

int main()
{
    cin >> N;
    L.resize(N+1,0), R.resize(N+1, 0);
    T.resize(N+1, vector<int>(N+1,-1));
    for(int i=1; i<=N; i++) {
        cin >> L[i];
    }
    for(int i=1; i<=N; i++) {
        cin >> R[i];
    }
    cout << f(1,1);
    return 0;
}
