#include <iostream>

using namespace std;

int main()
{
    int student[1001][5];
    int N,ans = 0,ansIdx;
    cin >> N;
    for(int i=1; i<=N; i++)
    for(int j=0; j<5; j++) {
        cin >> student[i][j];
    }

    for(int i=1; i<=N; i++) {
        int cnt = 0;
        for(int j=1; j<=N; j++) {
            for(int k=0; k<5; k++) {
                if(student[i][k] == student[j][k]) {
                    cnt++;
                    break;
                }
            }
        }
        if(cnt > ans) {
            ans = cnt;
            ansIdx = i;
        }
    }
    cout << ansIdx;
    return 0;
}
