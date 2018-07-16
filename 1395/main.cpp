#include <cstdio>
#include <vector>
using namespace std;

int tree[400001];
int lazy[400001];

void u_lazy(int node, int x, int y) {
    if(!lazy[node])
        return;
    tree[node] = (y-x+1) - tree[node];
    if(x != y) {
        lazy[node * 2] ^= 1;
        lazy[node * 2 + 1] ^= 1;
    }
    lazy[node] = 0;
}

int update(int node, int st,int ed, int tst,int ted) {
    u_lazy(node,st,ed);
    if(ed < tst || ted < st) {
        return tree[node];
    }

    if(tst <= st && ed <= ted) {
        lazy[node] ^= 1;
        u_lazy(node,st,ed);
        return tree[node];
    }

    return tree[node] = update(node*2, st, (st+ed)/2, tst, ted) + update(node*2+1, (st+ed)/2+1, ed, tst, ted);

}

int query(int node, int st,int ed, int tst, int ted) {
    u_lazy(node,st,ed);
    if(ed < tst|| ted < st) return 0;
    if(tst <= st && ed <= ted) {
        return tree[node];
    }
    return query(node*2,st,(st+ed)/2,tst,ted) + query(node*2+1,(st+ed)/2+1,ed,tst,ted);
}

int main()
{
    int N,M;

    scanf("%d %d",&N, &M);

    while(M--) {
        int op,s,e;

        scanf("%d %d %d",&op,&s,&e);

        if(op == 0) {
            update(1,1,N,s,e);
        }
        else {
            printf("%d\n",query(1,1,N,s,e));
        }

    }

    return 0;
}
