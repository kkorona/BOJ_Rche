#include <iostream>

using namespace std;

bool isPrime(int x) {
    if(x == 1) return false;
    for(int j=2; j*j<=x; j++) {
        if(x%j == 0) return false;
    }
    return true;
}

int main()
{
    int M,N;
    cin >> M >> N;
    int minimum = 1e9, sum=0;
    for(int i=M; i<=N; i++) {
        if(isPrime(i)) {
            minimum = min(minimum,i);
            sum += i;
        }
    }
    if(minimum != 1e9)
        cout << sum << "\n" << minimum;
    else
        cout << -1;
    return 0;
}
