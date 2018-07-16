#include <cstdio>
#include <queue>

using namespace std;

priority_queue <int > A,B;

int main()
{
    int n,m,T,ans,k;

    scanf("%d",&T);
    for(;T>0; T--) {
        scanf("%d %d",&n,&m);

        ans=0;

        for(int i=0; i<n; i++) {
            scanf("%d",&k);
            A.push(k);
        }
        for(int i=0; i<m; i++) {
            scanf("%d",&k);
            B.push(k);
        }

        for(int i=0; !B.empty();) {
            while(A.top() > B.top() && !A.empty()) {
                A.pop();
                i++;
            }
            ans+=i;
            B.pop();
        }

        while(!A.empty()) A.pop();

        printf("%d\n",ans);
    }

    return 0;
}
