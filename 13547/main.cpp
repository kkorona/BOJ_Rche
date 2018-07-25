#include<bits/stdc++.h>

using namespace::std;


typedef pair< int,int > pii;
const int N = 100005, M = 1000005, SQRT_N = 300;
pii query[N];
pair < pii,int > order[N];
int cnt[M];
int a[N];
int n,q;
int an;
int ans[M];

void add(int idx){
    if(cnt[a[idx]]==0) an++; // �̹� �߰��� ���ο� ���� ����
    cnt[a[idx]]++;
}

void erase(int idx){
    cnt[a[idx]]--;
    if(cnt[a[idx]]==0) an--; // �̹� ������ �� ���� ��� �����
}

void go_query(const pii& prev,const pii& now){
    int l1 = prev.first;
    int r1 = prev.second;
    int l2 = now.first;
    int r2 = now.second;
    for(int i = l1-1; i>=l2; i--) add(i); // l1 > l2 �� ���, ������ �þ���Ƿ� ��� �߰�
    for(int i = r1+1; i<=r2; i++) add(i); // r1 < r2 �� ���, ������ �þ���Ƿ� ��� �߰�
    for(int i = l1; i<l2; i++) erase(i); // l1 < l2 �� ���, ������ �پ����Ƿ� ��� ����
    for(int i = r1; i>r2; i--) erase(i); // r1 > r2 �� ���, ������ �پ����Ƿ� ��� ����
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    cin >> q;
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
