#include <cstdio>
#include <algorithm>

using namespace std;


int main()
{
    int x,y,w,h;

    scanf("%d%d%d%d",&x,&y,&w,&h);

    int ans=min(min(w-x,x),min(h-y,y));
    printf("%d",ans);

    return 0;
}
