#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    scanf("%d",&N);
    long long Data[1001],Sum[1001];
    Sum[0]=0;

    for(int i=1; i<=N; i++)
        scanf("%lld",&Data[i]);

    sort(Data+1,Data+N+1);

    for(int i=1; i<=N; i++) {
        Sum[i]=Sum[i-1]+Data[i];
    }


    for(int i=1; i<=N+1; i++) {
        if(i == N+1) printf("%lld",Sum[i-1]+1);
        else if(Data[i] > Sum[i-1]+1) {
            printf("%lld",Sum[i-1]+1);
            break;
        }
    }
    return 0;
}
