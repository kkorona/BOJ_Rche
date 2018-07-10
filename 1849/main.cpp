#include <cstdio>

using namespace std;

long long tree[400001], arr[100001];

int init(int node, int lo, int hi) {
    if(lo == hi) {
        return tree[node] = 1;
    }
    int mid = (lo+hi)/2;
    return tree[node] = init(node*2, lo, mid)  + init(node*2+1, mid+1, hi);
}

void update(int node,int lo,int hi, int tar, int diff) {
    if(tar < lo || hi < tar) return;
    tree[node] += diff;
    if(lo == hi) return;
    int mid = (lo+hi)/2;
    update(node*2,lo,mid,tar,diff);
    update(node*2+1,mid+1,hi,tar,diff);
}

int query(int node,int lo,int hi,int target) {
    if(lo == hi) return hi;
    if(tree[node * 2] <= target) {
        target -= tree[node*2];
        return query(node*2+1, (lo+hi)/2+1, hi, target);
    }
    else {
        return query(node*2, lo, (lo+hi)/2, target);
    }
}

int main()
{
    int N;
    scanf("%d",&N);

    init(1,1,N);
    int x;
    for(int i=1; i<=N; i++) {
        scanf("%d",&x);
        int index = query(1,1,N,x);
        update(1,1,N,index,-1);
        arr[index] = i;
    }

    for(int i=1; i<=N; i++) printf("%lld\n",arr[i]);

    return 0;
}
