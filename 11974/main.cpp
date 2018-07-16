#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int st[7]={-1,-1,-1,-1,-1,-1,-1},fin[7]={-1,-1,-1,-1,-1,-1,-1};
int ans;

int main()
{
    int N,sum=0;
    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        int x;
        scanf("%d",&x);
        sum = (sum+x)%7;
        if(st[sum]== -1) st[sum]=i;
        fin[sum]=i;
    }

    for(int i=0; i<7; i++)  {
        if(fin[sum] != -1) ans=max(ans,fin[i]-st[i]);
        if(i == 0){
            ans=max(ans,fin[i]+1);
        }
    }
    printf("%d",ans);

    return 0;
}
