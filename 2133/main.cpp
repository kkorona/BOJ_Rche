#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int N;
    scanf("%d",&N);

    vector <long long > T(N+1,0);
    T[0]=1;
    T[2]=3;
    for(int i=4; i<=N; i+=2) {
        T[i]=3*T[i-2];
        for(int j=4;j<=i;j+=2){
            T[i]+=2*T[i-j];
        }
    }
    printf("%lld",T[N]);
    return 0;
}
