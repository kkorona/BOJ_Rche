#include <cstdio>
#include <vector>

using namespace std;

const long long INF = 1e9;

inline bool rchk(int lo,int target,int hi) {
    return lo<=target && target<=hi;
}

int main()
{
    int N;
    scanf("%d",&N);
    long long T[101][10]={0,};

    for(int i=1; i<10; i++)
        T[1][i]=1;
    for(int i=2; i<=N; i++) {
        for(int j=0; j<10; j++) {
            if(rchk(0,j-1,9)) T[i][j]+=T[i-1][j-1];
            T[i][j]%=INF;
            if(rchk(0,j+1,9)) T[i][j]+=T[i-1][j+1];
            T[i][j]%=INF;
        }
    }

    long long ans=0;
    for(int i=0; i<10; i++)
        ans+=T[N][i]%INF;
    printf("%lld",ans%INF);
    return 0;
}
