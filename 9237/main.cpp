#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(int a,int b)  { return (a>b);}

int main()
{
    int n,data[100001];
    scanf("%d",&n);

    for(int i=0; i<n; i++) scanf("%d",&data[i]);
    vector <int > Sapling(data,data+n);
    sort(Sapling.begin(),Sapling.end(),cmp);
    int Max=0;
    for(int i=0; i<n; i++)
        if(Max < Sapling[i]+i+1) Max=Sapling[i]+i+1;
    printf("%d\n",Max+1);
    return 0;
}
