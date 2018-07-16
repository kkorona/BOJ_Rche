#include <iostream>
#include <vector>
using namespace std;

int ty,tx;
bool isValidRange(int y,int x) {
    return (y <= ty && x <= tx) || (y >= ty && x >= tx);
}

vector < vector < int > > T;

int main()
{

    int N,M,K;

    cin >> N >> M >> K;

    T.resize(N,vector<int>(M,0));
    K--;
    if(K<0) K++;
    ty = K/M, tx = K%M;
    T[0][0]=1;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(K != 0 && !isValidRange(i,j)) continue;
            int up = (i>0) ? T[i-1][j] : 0;
            int lp = (j>0) ? T[i][j-1] : 0;
            T[i][j] += up+lp;
        }
    }
    /*
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cout << T[i][j] << " ";
        }
        cout << endl;
    }
    */
    cout << T[N-1][M-1];

    return 0;
}
