#include <cstdio>

using namespace std;

int main()
{
    int n,SumList[99];

    SumList[0]=0;
    SumList[1]=1;
    SumList[2]=2;
    SumList[3]=4;
    int t;
    scanf("%d",&t);
    for(int i=4; i<=20; i++)
            SumList[i]=SumList[i-3]+SumList[i-2]+SumList[i-1];
    for(;t>0; t--) {
        scanf("%d",&n);
        printf("%d\n",SumList[n]);
    }
    return 0;
}
