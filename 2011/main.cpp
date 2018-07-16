#include <iostream>
#include <string>

using namespace std;

const int INF = 1e6;

int main()
{
    string S;
    cin >> S;
    int n = S.size();
    int* T = new int[n];

    for(int i=0; i<n; i++)
        T[i]=0;

    if(S[0] != '0') T[0]++;

    if(n >= 1) {
        if(S[1] != '0') T[1]=T[0];
        if(S[0] == '1') T[1]++;
        if(S[0] == '2' && '0' <= S[1] && S[1] <= '6') T[1]++;
    }

    for(int i=2; i<n; i++) {
        if(S[i] != '0')
            T[i]=T[i-1];
        if(S[i-1] == '1')
            T[i]+=T[i-2];
        if(S[i-1] == '2' && '0' <= S[i] && S[i] <= '6')
            T[i]+=T[i-2];
        T[i]%=INF;
    }
    /*
    for(int i=0; i<n; i++)
        cout << T[i] << " ";
    cout << endl;
    */
    cout << T[n-1];

    return 0;
}
