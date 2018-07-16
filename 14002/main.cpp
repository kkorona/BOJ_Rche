#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n,ans=0,ansM;
int data[1001];

int T[1001];
int Memo[1001];

int main()
{
    scanf("%d",&n);

    for(int i=1; i<=n; i++)
        scanf("%d",&data[i]);

    for(int i=1; i<=n; i++) {
        T[i]=1;
        Memo[i]=0;
        for(int j=1; j<i; j++) {
            if(data[j] < data[i] && T[i] < T[j]+1) {
                T[i]=T[j]+1;
                Memo[i]=j;
            }
        }
        if(ans < T[i]) {
            ans=T[i];
            ansM=i;
        }
    }

    printf("%d\n",ans);
    vector < int > ret;
    while(ansM != 0) {
        ret.push_back(data[ansM]);
        ansM = Memo[ansM];
    }
    reverse(ret.begin(),ret.end());
    for(int i:ret) {
        printf("%d ",i);
    }


    return 0;
}
