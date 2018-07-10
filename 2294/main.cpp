#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 200000;

int n,k;
int Coin[101],value[10001];

int main()
{

    scanf("%d %d",&n,&k);
    for(int j=1; j<=k; j++)
        value[j]=INF;
    for(int i=1; i<=n; i++) {
        scanf("%d",&Coin[i]);
        if(Coin[i] <= k)
            value[Coin[i]]=1;
    }

    for(int i=1; i<=k; i++) {
        if(value[i] != INF) {
            for(int j=1; j<=n; j++) {
                if(i+Coin[j] <= 10000) {
                    value[i+Coin[j]]=min(value[i+Coin[j]],value[i]+1);
                }
            }
        }
    }

    printf("%d",value[k] != INF ? value[k] : -1);

}
