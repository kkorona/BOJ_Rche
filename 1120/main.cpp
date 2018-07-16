#include <bits/stdc++.h>

using namespace std;

int main()
{
    string A,B;
    cin >> A >> B;
    int AA = A.size(),BB = B.size();
    int curErr = 1e9;
    for(int i=0; i<=BB-AA; i++) {
        int cnt = 0;
        for(int j=0; j<AA; j++) {
            int k = i+j;
            if(B[k] != A[j]) cnt++;
            if(cnt >= curErr) break;
        }
        if(cnt < curErr) {
            curErr=cnt;
        }
    }
    cout << curErr;
    return 0;
}
