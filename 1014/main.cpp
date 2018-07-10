#include <cstdio>

using namespace std;

int main()
{

    long long T[10001]={0,};

    T[0] = 1;
    T[1] = 1;

    int N;

    scanf("%d",&N);

    N/=2;

    for(int i=2; i<=N; i++) {
        for(int j=0; j<i; j++) {
            T[i] += T[j] * T[i-j-1];
            T[i] %= 987654321;
        }
    }

    printf("%lld",T[N]);

    return 0;
}
