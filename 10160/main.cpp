#include <iostream>

using namespace std;

int main()
{
    int N,K;
    long long int state[7] = {0,}, prevstate[7];
    long long int flow[7][7] = {0,};
    cin >> N >> K;
    flow[0][0]= K-1; flow[0][1] = 1;
    flow[1][0]= K-2; flow[1][1] = 1; flow[1][2] = 1;
    flow[2][0] = K-2; flow[2][3] = flow[2][4] = 1;
    flow[3][0] = K-2; flow[3][1] = flow[3][5] = 1;
    flow[4][0] = K-2; flow[4][1] = flow[4][6] = 1;
    flow[5][0] = K-2; flow[5][3] = 1;
    flow[6][0] = K-2; flow[6][1] = 1;
    state[0] = K-1;
    state[1] = 1;
    for(int i=2; i<=N; i++) {
        for(int j=0; j<=6; j++) {
            prevstate[j] = state[j];
            state[j] = 0;
        }
        for(int j=0; j<=6; j++) {
            for(int k=0; k<=6; k++) {
                state[k] += (prevstate[j] * flow[j][k])%1000000009;
            }
        }
    }
    long long int ans = 0;
    for(int i=0; i<=6; i++)
        ans = (ans + state[i]) % 1000000009;

    cout << ans;
    return 0;
}
