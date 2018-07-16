#include <cstdio>
#include <cstring>

using namespace std;

int Tree[800001];
int indx[100001];
int n,m;

void update(int pos,int val,int idx,int l,int r) {
    if(l==r) {
        Tree[idx]=val;
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid) update(pos,val,idx<<1,l,mid);
    else update(pos,val,idx<<1|1,mid+1,r);
    /*
    if(mid > pos) { <- °ýÈ£ ¹Ý´ë·Î Àû¾î³ù¾úÀ½ ;;
        update(pos,val,idx<<1|1,mid+1,r);
    }
    else {
        update(pos,val,idx<<1,l,mid);
    }
    */
    Tree[idx]=Tree[idx<<1]+Tree[idx<<1|1];
}

int sum(int x,int y,int idx,int l,int r) {
    if(l > y || x > r) return 0;
    if(x <= l && r <= y) return Tree[idx];
    int mid=(l+r)/2;
    return sum(x,y,idx<<1,l,mid)+sum(x,y,idx<<1|1,mid+1,r);
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)
            indx[i]=n-i;
        for(int i=0; i<n; i++)
            update(i,1,1,0,n+m-1);
        for(int i=0; i<m; i++) {
            int x;
            scanf("%d",&x);
            int j=indx[x];
            printf("%d ",sum(j+1,n+m-1,1,0,n+m-1));
            update(j,0,1,0,n+m-1);
            indx[x]=n+i;
            update(indx[x],1,1,0,n+m-1);
        }
        printf("\n");
        memset(Tree,0,sizeof(Tree));
    }
    return 0;
}
