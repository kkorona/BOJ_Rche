#include <cstdio>
#include <algorithm>

using namespace std;

int n,ans=0;
int data[1001];

int T[1001];

int main()
{
    scanf("%d",&n);

    for(int i=1; i<=n; i++)
        scanf("%d",&data[i]);

    T[1]=1;

    for(int i=2; i<=n; i++) {
        T[i]=1;
        for(int j=1; j<i; j++) {
            if(data[j] < data[i] && T[i] < T[j]+1) {
                T[i]=T[j]+1;
            }
        }
        if(ans < T[i]) ans=T[i];
    }

    printf("%d",ans);

    return 0;
}
