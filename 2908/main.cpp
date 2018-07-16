#include <bits/stdc++.h>

using namespace std;

int main()
{
    string A,B;
    cin >> A >> B;
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    for(int i=0; i<3; i++) {
        if(A[i] > B[i]) {
            cout << A;
            return 0;
        }
        else if(A[i] < B[i]) {
            cout << B;
            return 0;
        }
    }
    return 0;
}
