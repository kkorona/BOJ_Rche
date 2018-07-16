#include <cstdio>

using namespace std;

int main()
{
    int res=1;
    int n;
    scanf("%d",&n);
    while(n--) {
        int temp;
        scanf("%d",&temp);
        res+=temp-1;
    }
    printf("%d",res);
    return 0;
}
