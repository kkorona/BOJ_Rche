#include <cstdio>

using namespace std;

bool numCheck(int n) {
    if(n == 1) return false;
    for(int i=2; i*i<=n; i++)
        if(n%i == 0) return false;
    return true;
}

int main()
{
    int n,ans=0;
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        int x;
        scanf("%d",&x);
        ans+=numCheck(x);
    }
    printf("%d",ans);
    return 0;
}
