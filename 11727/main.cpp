#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int N;
    scanf("%d",&N);

    vector <int > T(N+1,0);
    T[1]=1;
    T[2]=3;

    for(int i=3; i<=N; i++)
        T[i]=T[i-1]%10007+2*T[i-2]%10007;

    printf("%d",T[N]%10007);

    return 0;
}
