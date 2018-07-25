#include <cstdio>
#include <algorithm>
#define MAX_N 100000
typedef long long ll;
using namespace std;
ll seg[4 * MAX_N], n, x, v;
pair<ll, ll> q[MAX_N + 1];
ll r[MAX_N + 1];
ll update(ll pos, ll val, ll node, ll x, ll y) {
    if (y < pos || pos < x)
        return seg[node];
    if (x == y)
        return seg[node] = val;
    ll mid = (x + y) >> 1;
    return seg[node] = update(pos, val, node * 2, x, mid) + update(pos, val, node * 2 + 1, mid + 1, y);
}
ll query(ll lo, ll hi, ll node, ll x, ll y) {
    if (y < lo || hi < x)
        return 0;
    if (lo <= x&&y <= hi)
        return seg[node];
    ll mid = (x + y) >> 1;
    return query(lo, hi, node * 2, x, mid) + query(lo, hi, node * 2 + 1, mid + 1, y);
}
int main() {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        update(i, 1, 1, 1, n);
        scanf("%lld", &x);
        q[i - 1] = { x,i };
    }
    sort(q, q + n);
    for (auto y : q) {
        ll idx = y.second;
        ll res = query(1, idx, 1, 1, n)*y.first + query(idx + 1, n, 1, 1, n)*(y.first - 1) + v;
        v += y.first;
        update(idx, 0, 1, 1, n);
        r[idx] = res;
    }
    for (int i = 1; i <= n; i++)
        printf("%lld\n", r[i]);
    return 0;
}