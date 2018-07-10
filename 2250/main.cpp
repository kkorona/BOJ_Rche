#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,cnt=1;
class node {
public:
    int l,r,index,level;
    node(int l=-1,int r=-1) : l(l), r(r) {}
};

vector < int > isRoot;
vector < node > graph;
vector < int > L;
vector < int > R;

void preorder(int index,int level) {
    node& n = graph[index];
    if(n.l > 0) preorder(n.l,level+1);
    n.index = cnt;
    L[level] = min(cnt,L[level]);
    R[level] = max(cnt,R[level]);
    cnt++;
    n.level = level;
    if(n.r > 0) preorder(n.r,level+1);
}

int main() {

    cin >> N;
    isRoot.resize(N+1,1);
    graph.resize(N+1);
    L.resize(10001,1e9);
    R.resize(10001,0);
    for(int i=1; i<=N; i++) {
        static int idx,ll,rr;
        cin >> idx >> ll >> rr;
        graph[idx]=node(ll,rr);
        if(ll > 0) isRoot[ll] = 0;
        if(rr > 0) isRoot[rr] = 0;
    }
    int root = 0;
    for(int i=1; i<=N; i++) {
        if(isRoot[i]) root=i;
    }
    preorder(root,1);

    int ans=0,ansIndex;
    for(int i=1; i<=N; i++) {
        if(L[i] > R[i]) continue;
        if(ans < R[i] - L[i] + 1) {
            ans = R[i] - L[i] + 1;
            ansIndex = i;
        }
    }
    cout << ansIndex << " " << ans;
    return 0;
}
