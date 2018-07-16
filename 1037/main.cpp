#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{

    int n,a,b;
    vector <int> L;
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        int x;
        scanf("%d",&x);
        L.push_back(x);
    }
    sort(L.begin(),L.end());
    a=L[0]; b=L[n-1];
    printf("%d",a*b);

    return 0;
}
