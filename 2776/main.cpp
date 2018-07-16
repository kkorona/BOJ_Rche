#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int T,N,M;

vector <int > Memo;

void B_Search(const int key) {
    int lo=0,hi=N-1;
    while(lo<=hi) {
        int mid=(lo+hi)/2;
        if(Memo[mid] > key) hi=mid-1;
        else if(Memo[mid] < key ) lo=mid+1;
        else {
            printf("1\n");
            return;
        }
    }
    printf("0\n");
    return;
}

int main()
{

   int T,k;
   scanf("%d",&T);

   for(; T>0; T--) {
        scanf("%d",&N);
        for(int i=0; i<N; i++) {
            scanf("%d",&k);
            Memo.push_back(k);
        }
        sort(Memo.begin(),Memo.end());
        scanf("%d",&M);
        for(int i=0; i<M; i++) {
            scanf("%d",&k);
            B_Search(k);
        }
        Memo.erase(Memo.begin(),Memo.end());
   }

    return 0;
}
