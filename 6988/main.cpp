#include <cstdio>
#include <vector>
using namespace std;

const int LIMIT = 1e6 + 1;
int chk[LIMIT];
long long T[3001][3001];
int main()
{

    int N;
    scanf("%d",&N);
    vector <int> data(N+1,0);
    for(int i=1; i<=N; i++) {
        scanf("%d",&data[i]);
        chk[data[i]] = i;
    }
    long long ans = 0;
    int i,j,temp,ret;
    for(i=N-2; i>=1; i--) {
        for(j=N-1; j>=i+1; j--) {
            ret = data[j] - data[i] + data[j];
            if(ret >= LIMIT) continue;
            temp = chk[ret];
            if(temp != 0) {
                T[i][j] = max((long long)3*data[j],data[i] + T[j][temp]);
            }
            ans = max(ans,T[i][j]);
        }
    }
    printf("%lld",ans);
    return 0;
}
