#include <cstdio>
#include <vector>
using namespace std;
vector < vector < int > > Map;

inline bool bchk(int lo,int tar,int hi) {
    return lo<=tar && tar < hi;
}

int main()
{
    int N;
    scanf("%d",&N);
    Map.resize(N);
    for(int i=0; i<N; i++)
        Map[i].resize(N,0);

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf("%d",&Map[i][j]);

    vector < vector < long long > > T(N);
    for(int i=0; i<N; i++)
        T[i].resize(N,0);

    T[0][0]=1;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(Map[i][j] == 0) continue;
            int key = Map[i][j];
            if(bchk(0,i+key,N)) T[i+key][j]+=T[i][j];
            if(bchk(0,j+key,N)) T[i][j+key]+=T[i][j];
        }
    }

    printf("%lld",T[N-1][N-1]);
    return 0;
}
