#include <cstdio>

using namespace std;

int main()
{
    long long Fibo[100];
    Fibo[1]=Fibo[2]=1;
    Fibo[0]=0;
    int n;
    scanf("%d",&n);

    for(int i=3; i<=n; i++)
        Fibo[i]=Fibo[i-1]+Fibo[i-2];

    printf("%lld",Fibo[n]);
    return 0;
}
