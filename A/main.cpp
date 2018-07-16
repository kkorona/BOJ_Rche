#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N,d;
    vector <int> a;
    scanf("%d%d",&N,&d);
    a.resize(N,0);
    for(int i=0; i<N; i++)
        scanf("%d",&a[i]);
    sort(a.begin(),a.end());

    int ans=0x7ffffff;

    for(int i=0; i<N; i++) {
        for(int j=N-1; j>=i; j--) {
            if(a[j]-a[i] <= d) {
                ans = min(ans, N-j-1 + i);
            }
        }
    }
    printf("%d",ans);
    return 0;
}
