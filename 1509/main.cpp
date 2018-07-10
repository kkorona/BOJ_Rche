#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

int main()
{

    string Input;

    cin >> Input;

    int N = Input.size();

    vector < vector < int > > isPalin(N);
    vector < int > dp(N+1,numeric_limits<int>::max());

    for(int i=0; i<N; i++) {
        isPalin[i].resize(N);
        isPalin[i][i]=1;
    }

    for(int i=0; i<N; i++) {
        for(int j=1; i-j >=0 && i+j < N; j++) {
            if(isPalin[i-j+1][i+j-1] == 1 && Input[i-j] == Input[i+j]) {
                isPalin[i-j][i+j]=1;
            }
        }
        if(i < N-1 && Input[i] == Input[i+1]) {
            isPalin[i][i+1]=1;
            for(int j=1; i-j >=0 && i+j+1 < N; j++) {
                if(isPalin[i-j+1][i+j] == 1 && Input[i-j] == Input[i+j+1]) {
                    isPalin[i-j][i+j+1]=1;
                }
            }
        }
    }

    dp[0]=0;
    dp[1]=1;
    for(int i=2; i<=N; i++) {
        int index=i-1;
        for(int j=0; j<=index; j++) {
            if(isPalin[j][index] == 1) {
                dp[i]=min(dp[i],dp[j]+1);
            }
        }
    }

    cout << dp[N];


    return 0;
}
