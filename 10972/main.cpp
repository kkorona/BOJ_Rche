#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N;

int main()
{

    int data[10001];

    scanf("%d",&N);
    for(int i=0; i<N; i++)
        scanf("%d",&data[i]);

    vector <int > perm(data,data+N);

    bool check = next_permutation(perm.begin(),perm.end());

    if(check)
        for(int i=0; i<N; i++)
            printf("%d ",perm[i]);
    else printf("-1");
    return 0;
}
