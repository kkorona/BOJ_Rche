#include <cstdio>
#include <algorithm>

using namespace std;

const int INF = 9999;

int N;
int data[1001],T[1001];
int ans=0;

int main()
{
    scanf("%d",&N);
    for(int i=1; i<=N; i++)
        scanf("%d",&data[i]);
    T[1]=1;
    for(int i=2; i<=N; i++) {
        T[i]=1;
        for(int j=i; j>=1; j--) {
            if(data[j] < data[i]) {
                T[i]=max(T[i],T[j]+1);
            }
        }
        if(ans < T[i]) ans=T[i];
    }

    printf("%d",ans);
    return 0;
}
