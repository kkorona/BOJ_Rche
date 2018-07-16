#include <cstdio>
#include <algorithm>
using namespace std;

int x1,y1,x2,y2,x3,y3,x4,y4;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d %d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
        int A1=(x2-x1) * (y2-y1);
        int Ac=(min(x2,x4)-max(x1,x3))*(min(y2,y4)-max(y1,y3));
        if(Ac < 0) printf("%d\n",A1);
        else printf("%d\n",(A1-Ac > 0 ) ? A1-Ac:0);
    }

    return 0;
}
