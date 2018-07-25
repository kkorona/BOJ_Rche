#include<bits/stdc++.h>
using namespace std;
int t, n, x[501];
int main() {
    for (scanf("%d", &t); t--;) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", x + i);
        long long i = 5,
            a = -x[1] + 3 * x[2] - 3 * x[3] + x[4],
            b = 9 * x[1] - 24 * x[2] + 21 * x[3] - 6 * x[4],
            c = -26 * x[1] + 57 * x[2] - 42 * x[3] + 11 * x[4],
            d = 24 * x[1] - 36 * x[2] + 24 * x[3] - 6 * x[4];
        for (; i <= n; i++) if (6 * x[i] ^ a*i*i*i + b*i*i + c*i + d) break;
        cout << (i > n ? "YES" : "NO") << "\n";
    }
    return 0;
}