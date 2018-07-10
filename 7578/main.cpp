#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector <int> tree;
vector <int> Line2;

int idx[1000001];

int sum(int node,int st,int ed, int l,int r) {
    if(st > r || ed < l ) return 0;
    if(l <= st && ed <= r) return tree[node];
    return sum(node*2,st,(st+ed)/2,l,r) + sum(node*2+1,(st+ed)/2+1,ed,l,r);
}

void update(int node,int st,int ed,int tar) {
    if(ed < tar || st > tar) return;
    if(st == ed) {
        tree[node]=1;
        return;
    }
    tree[node]++;
    update(node*2,st,(st+ed)/2,tar);
    update(node*2+1,(st+ed)/2+1,ed,tar);
}

int main()
{
    int N;
    cin >> N;

    int h = (int)ceil(log2(N));
    tree.resize(1 << (h+1),0);
    Line2.resize(N,0);
    int x;
    for(int i=0; i<N; i++) {
        cin >> x;
        idx[x] = i;
    }
    for(int i=0; i<N; i++) {
        cin >> x;
        Line2[idx[x]] = i;
    }

    long long ans = 0;
    for(int i=0; i<N; i++) {
        ans += sum(1,0,N-1,Line2[i],N-1);
        update(1,0,N-1,Line2[i]);
    }

    cout << ans;

    return 0;
}
