#include <cstdio>

using namespace std;

int CountArray[4000];

int main()
{
    int N,x;

    scanf("%d",&N);

    for(int i=0; i<N; i++) {
        scanf("%d",&x);
        CountArray[x+1000]=1;
    }

    for(int i=0; i<4000; i++)
        if(CountArray[i] > 0) printf("%d ",i-1000);

    return 0;
}
