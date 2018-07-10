#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int N,M;
        queue <int> Q;
        queue <int> subQ;
        int cnt = 0, ans;
        scanf("%d%d",&N,&M);
        vector<int>Documents(N,0);
        for(int i=0; i<N; i++) {
            scanf("%d",&Documents[i]);
            Q.push(Documents[i]);
            subQ.push(i);
        }
        sort(Documents.begin(),Documents.end());
        for(int i=N-1; i>=0; i--) {
            int t = Documents[i];
            while(Q.front() != t) {
                int temp = Q.front();
                Q.pop();
                Q.push(temp);
                temp = subQ.front();
                subQ.pop();
                subQ.push(temp);
            }
            cnt++;
            Q.pop();
            if(subQ.front() == M) ans = cnt;
            subQ.pop();
        }
        printf("%d\n",ans);
    }
    return 0;
}
