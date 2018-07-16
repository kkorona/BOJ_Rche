#include <cstdio>

using namespace std;

int main()
{
    int f0[41],f1[41];

    f0[0]=1; f1[0]=0;
    f0[1]=0; f1[1]=1;

    int t;
    scanf("%d",&t);
    while(t--) {
        int n;
        scanf("%d",&n);
        for(int i=2; i<=n; i++) {
            f0[i]=f0[i-1]+f0[i-2];
            f1[i]=f1[i-1]+f1[i-2];
        }
        printf("%d %d\n",f0[n],f1[n]);
    }
    return 0;
}
