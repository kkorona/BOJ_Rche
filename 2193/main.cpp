#include <cstdio>

using namespace std;

int main()
{
    long long Pinary_0[99],Pinary_1[99]; //0으로 끝나는 이친수, 1로 끝나는 이친수
    Pinary_1[1]=1; Pinary_0[1]=0;

    int n;
    scanf("%d",&n);

    for(int i=2; i<=n; i++) {
        Pinary_0[i]=Pinary_0[i-1]+Pinary_1[i-1];
        Pinary_1[i]=Pinary_0[i-1];
    }

    printf("%lld",Pinary_0[n]+Pinary_1[n]);
    return 0;
}
