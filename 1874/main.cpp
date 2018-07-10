#include <cstdio>
#include <stack>

using namespace std;

stack <int > Stack;

int main()
{
    int n,Data[100005],k=0,t=0,p=0;
    char ans[300000];

    scanf("%d",&n);

    for(int i=0; i<n; i++) {
        scanf("%d",&Data[i]);
    }

    while(t < n) {
        Stack.push(t+1); ans[p++]='+'; t++;
        while(!Stack.empty() && Stack.top() == Data[k]) {
            ans[p++]='-'; k++;
            Stack.pop();
        }
    }
    if(!Stack.empty()) printf("NO");
    else for(int i=0; i<p; i++) printf("%c\n",ans[i]);

    return 0;
}
