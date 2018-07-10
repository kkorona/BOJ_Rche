#include <iostream>

using namespace std;

int main()
{
    long long T[81];
    T[0]=0;
    T[1]=1;
    T[2]=1;
    int N;
    cin >> N;
    for(int i=3; i<=N; i++) {
        T[i] = T[i-1]+T[i-2];
    }
    cout << T[N]*4+T[N-1]*2;
    return 0;
}
