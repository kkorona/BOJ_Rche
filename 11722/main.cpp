#include <cstdio>

using namespace std;

int main()
{
    int D[1001],D_index[1001],Data[1001],n,ans=1;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&Data[i]);
    D[1]=1;
    D_index[1]=Data[1];
    for(int i=2; i<=n; i++) {
        D[i]=-1;
        for(int j=1; j<i; j++) {
            if(D_index[j] > Data[i] && D[i] < D[j]+1) {
                D[i]=D[j]+1;
                D_index[i]=Data[i];
            }
        }
        if(D[i] == -1) {
            D[i]=1;
            D_index[i]=Data[i];
        }
        if(D[i] > ans) ans=D[i];
    }
    printf("%d",ans);
    return 0;
}
