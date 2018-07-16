#include <iostream>
#include <vector>
using namespace std;
const long long q = 1000000003;

int main()
{
    int N,K;
    cin >> N >> K;
    if(K > N/2) {
        cout << 0;
    }
    else if(K == 1) cout << N;
    else {
        vector < vector < long long > > T(N+1,vector< long long >(N+1,0));
        T[0][0] = 1;
        T[1][0] = 0;
        T[1][1] = 1;
        for(int i=2; i<=N; i++) {
            T[i][0] = 0;
            T[i][1] = i;
            for(int j=2; j<=K; j++)
                T[i][j] = (T[i-2][j-1] + T[i-1][j] )% q;
        }
        cout << (((T[N][K] - T[N-4][K-2] ) % q )+ q ) % q;
    }
    return 0;
}
