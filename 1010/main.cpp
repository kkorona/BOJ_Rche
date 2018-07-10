#include <cstdio>

using namespace std;

long long res=1;

int main()
{
    int n,m,t;

    scanf("%d",&t);

    while(t--) {
        res=1;
        scanf("%d%d",&m,&n);
        if(m > n/2) m=n-m;
        for(int i=n-m+1; i<=n; i++) {
            res*=i;
        }
        for(int i=2; i<=m; i++) {
            res/=i;
        }
        printf("%lld\n",res);

    }
    return 0;
}
