#include <cstdio>
#include <stack>
using namespace std;

stack <int > S;
int tower[500001];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&tower[i]);
    tower[0]=1e9;
    S.push(0);
    for(int i=1; i<=n; i++) {
        while(tower[S.top()] < tower[i]) S.pop();
        printf("%d ",S.top());
        S.push(i);
    }

    return 0;
}
