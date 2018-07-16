/*
#include <iostream>
#include <vector>
using namespace std;

vector < long long > tree(3000001,0);

int ret = 0;

void update(int node,int st,int ed,int target, int diff) {
    if(target < st || ed < target) return;
    tree[node] += diff;
    if(st != ed) {
        update(node*2,st,(st+ed)/2,target,diff);
        update(node*2+1,(st+ed)/2+1,ed,target,diff);
    }
}

long long query(int node,int st,int ed,int k) {
    if(st == ed && ret == 0) {
        cout << st << "\n";
        return st;
    }
    if(ret == 0 && (tree[node*2] >= k))
        return query(node*2,st,(st+ed)/2,k);
    k -= tree[node*2];
    return query(node*2+1,(st+ed)/2+1,ed,k);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    int T;
    long long p,q,idx;
    cin >> T;
    while(T--) {
        int order;
        cin >> order;
        if(order == 1) {
            cin >> p;
            idx = query(1,1,1000000,p);
            ret = 0;
            update(1,1,1000000,idx,-1);
        }
        else {
            cin >> p >> q;
            update(1,1,1000000,p,q);
        }
    }

    return 0;
}
*/

