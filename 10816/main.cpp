#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int > Data;

int main()
{
    int n,m,k;

    scanf("%d",&n);

    for(int i=0; i<n; i++) {
        scanf("%d",&k);
        Data.push_back(k);
    }

    sort(Data.begin(),Data.end());

    scanf("%d",&m);

    for(int i=0; i<m; i++) {
        scanf("%d",&k);
        printf("%d ",upper_bound(Data.begin(),Data.end(),k)-lower_bound(Data.begin(),Data.end(),k));
    }

    return 0;
}
