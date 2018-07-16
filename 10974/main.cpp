#include <cstdio>
#include <vector>

using namespace std;

vector <int > ans;

int used[10],cnt;

void perm(int len, int N) {
    if(len == N) {
        //printf("%d :",++cnt);
        for(int i=0; i<N; i++)
            printf("%d ",ans[i]);
        printf("\n"); return;
    }
    for(int i=0; i<N; i++) {
        if(used[i] == 0) {
            used[i]=1;
            ans.push_back(i+1);
            perm(len+1,N);
            ans.pop_back();
            used[i]=0;
        }
    }
}

int main()
{
    int N;
    scanf("%d",&N);
    perm(0,N);
    return 0;
}
