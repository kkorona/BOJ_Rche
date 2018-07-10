#include <cstdio>

using namespace std;

#define PI 3.141592
#define modity 1000000000000000000

long long Memo[1001][1001];
long long Pibonacci(int n,int pi) {
    if(Memo[n][pi] != 0) return Memo[n][pi];
    if(n < PI * (pi+1)) return 1;
    return Memo[n][pi]=(Pibonacci(n-1,pi) + Pibonacci(n,pi+1))%modity;
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%lld",Pibonacci(n,0));
    return 0;
}
