#include <cstdio>

using namespace std;
int Data[2000000];
int main()
{
    int N;


    scanf("%d",&N);

    for(int i=1; i<=N; i++)
        Data[i]=i;
    int F=1,T=N+1,ans=1,temp;
    while(N>0) {
        F++; N--;
        if(N == 1) ans=Data[F];
        temp=Data[F];
        F++;
        Data[T]=temp;
        T++;
    }
    printf("%d",ans);
    return 0;
}
