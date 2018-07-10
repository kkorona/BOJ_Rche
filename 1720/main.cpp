#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    long long T[31];
    T[0]=1;
    T[1]=1;
    for(int i=2; i<=N; i++) T[i] = T[i-1] + 2*T[i-2];
   cout << (T[N] + T[N/2] + (N%2 == 0) * 2 * T[N/2-1] )/ 2;

    return 0;
}
