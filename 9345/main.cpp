#include <cstdio>
#include <algorithm>

using namespace std;

int n,m;
int min_Tree[400005],max_Tree[400005];
int Data[100005];

void build(int id,int lo,int hi) {
    if(lo == hi) {
        min_Tree[id]=Data[lo];
        max_Tree[id]=Data[lo];
        return;
    }
    int mid=(lo+hi)/2;
    build(2*id, lo,mid);
    build(2*id+1, mid+1, hi);
    min_Tree[id]=min(min_Tree[2*id],min_Tree[2*id+1]);
    max_Tree[id]=max(max_Tree[2*id],max_Tree[2*id+1]);
}

int query(int x,int y,int id, int lo,int hi,int type) {
    //printf("find_query_min %d %d %d %d %d >>",x,y,id,lo,hi);
    if(y < lo || hi < x) return (type == 0 ? 1e9:-1e9);
    if(x<=lo && hi<=y) return (type == 0 ? min_Tree[id]:max_Tree[id]);

    int mid=(lo+hi)/2;
    int temp;
    if(type == 0) temp=min(query(x,y,2*id,lo,mid,0),query(x,y,2*id+1,mid+1,hi,0));
    else temp=max(query(x,y,2*id,lo,mid,1),query(x,y,2*id+1,mid+1,hi,1));
    //printf(" %d\n",temp);
    return temp;
}
void update(int pos, int val, int id=1, int l=1, int r=n) // pos :갱신 위치 val :갱신 key
{
    if(l==r){ // 단말 노드에 도착
        min_Tree[id]=val;
        max_Tree[id]=val;
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid){ // 루트에서부터 내려가면서, 갱신된 단말노악 드가 어느 subtree에 있는지 파악
        update(pos,val,id*2,l,mid);
    }else{
        update(pos,val,id*2+1,mid+1,r);
    }
    min_Tree[id]=min(min_Tree[id*2],min_Tree[id*2+1]);
    max_Tree[id]=max(max_Tree[id*2],max_Tree[id*2+1]);
}

/*

루트에서부터 갱신된 노드를 찾아가면서 트리를 갱신하므로
전체 시간복잡도는 트리의 level인 log n
다른 함수와는 달리 pos,val을 인수로 받는 것을 유의할 것
build의 시간복잡도가 n이므로 build보다 훨씬 빠르다.

*/

int main()
{

    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d",&n,&m);
        for(int i=1; i<=n; i++) Data[i]=i;
        build(1,1,n);
        for(int i=0; i<m; i++) {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            b++;
            c++;
            if(a==0) {
                int temp=Data[b];
                Data[b]=Data[c];
                Data[c]=temp;
                update(b,Data[b]);
                update(c,Data[c]);
                //for(int i=1; i<=n; i++) printf("%d ",Data[i]);
                //printf("\n");
            }
            else {
                int q1=query(b,c,1,1,n,0), q2=query(b,c,1,1,n,1);
                //printf("%d %d ",q1,q2);
                if(q1 == b && q2 == c)
                    printf("YES\n");
                else printf("NO\n");
            }
        }
    }

    return 0;
}

// http://ideone.com/2z8BEl
// https://www.acmicpc.net/problem/9345
