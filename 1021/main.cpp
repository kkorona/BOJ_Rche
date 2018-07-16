#include <cstdio>
#include <iterator>
#include <list>
using namespace std;

list <int> RDQ;
int main() {
    int N, M;
    scanf("%d%d",&N,&M);
    for(int i=1; i<=N; i++)
        RDQ.push_back(i);
    auto it = RDQ.begin();
    int ans=0;
    while(M--) {
        int x,cnt=0;;
        scanf("%d",&x);
        while((*it) != x) {
            it++;
            if(it == RDQ.end()) it=RDQ.begin();
            cnt++;
        }
        if(cnt * 2 > RDQ.size()) cnt = RDQ.size() - cnt;
        //printf("before : %d | ",*it);
        it=RDQ.erase(it);
        if(it == RDQ.end()) it=RDQ.begin();
        //printf("after :  %d\n",*it);
        ans += cnt;
    }
    printf("%d",ans);

    return 0;
}
