#include <cstdio>
#include <algorithm>
using namespace std;

int D[101][10001];
class coin {
    public:
    int val,amount;
    bool operator < (const coin& C) const {
        return val < C.val;
    }
} Coin[101];

int main()
{
    int T,K;
    scanf("%d%d",&T,&K);
    for(int i=1; i<=K; i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        Coin[i].val=x; Coin[i].amount=y;
    }
    sort(Coin,Coin+K);

    D[0][0]=1;
    for(int i=1; i<=K; i++) {
        for(int k=0; k<=Coin[i].amount; k++) {
            for(int j=0; j<=T; j++){
                if(j+Coin[i].val*k > T) break;
                D[i][j+Coin[i].val*k]+=D[i-1][j];
            }

        }

    }
    /*
    for(int i=1; i<=K; i++) {
        for(int j=0; j<=T; j++)
            printf("%d ",D[i][j]);
        printf("\n");
    }
*/
    printf("%d",D[K][T]);

    return 0;
}
