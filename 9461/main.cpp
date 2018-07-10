#include <cstdio>

using namespace std;

int main()
{
    long long D[101];
    D[1]=D[2]=D[3]=1;
    D[4]=D[5]=2;

    for(int i=6; i<=100; i++) D[i]=D[i-5]+D[i-1];

    int T;
    scanf("%d",&T);

    while(T--) {
        int x;
        scanf("%d",&x);
        printf("%lld\n",D[x]);
    }
    return 0;
}
