#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int N;
    scanf("%d",&N);

    vector <int > D(N+1,0);

    D[1]=1;
    D[2]=2;
    for(int i=3; i<=N; i++) {
        D[i]=D[i-1]%10007+D[i-2]%10007;
    }

    printf("%d",D[N]%10007);
    return 0;
}
