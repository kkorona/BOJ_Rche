#include<bits/stdc++.h>

using namespace::std;


typedef pair< int,int > pii;
const int N = 100001, M = 1000001, SQRT_N = 300;
pii query[N];
pair < pii,int > order[N];
int cnt[M];
long long a[N];
int n,q;
long long an;
long long ans[M];

void add(int idx){
    long long ks = cnt[a[idx]], s = a[idx];
    an-= ks*ks*s;
    cnt[a[idx]]++;
    ks++;
    an+= ks*ks*s;
}

void erase(int idx){
    long long ks = cnt[a[idx]], s = a[idx];
    an-= ks*ks*s;
    cnt[a[idx]]--;
    ks--;
    an+= ks*ks*s;
}

void go_query(const pii& prev,const pii& now){
    int l1 = prev.first;
    int r1 = prev.second;
    int l2 = now.first;
    int r2 = now.second;
    for(int i = l1-1; i>=l2; i--) add(i); // l1 > l2 인 경우, 구간이 늘어났으므로 노드 추가
    for(int i = r1+1; i<=r2; i++) add(i); // r1 < r2 인 경우, 구간이 늘어났으므로 노드 추가
    for(int i = l1; i<l2; i++) erase(i); // l1 < l2 인 경우, 구간이 줄었으므로 노드 삭제
    for(int i = r1; i>r2; i--) erase(i); // r1 > r2 인 경우, 구간이 줄었으므로 노드 삭제
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();

    cin >> n;
    cin >> q;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=q; i++){
        cin >>query[i].first >> query[i].second;
        order[i].first = make_pair(query[i].first/SQRT_N, query[i].second);
        order[i].second = i;
    }
    sort(order+1, order+q+1);
    for(int i=1; i<=q; i++){
        go_query(query[order[i-1].second], query[order[i].second]);
        ans[order[i].second] = an;
    }
    for(int i=1; i<=q; i++)
        cout << ans[i] << "\n";
    return 0;
}
