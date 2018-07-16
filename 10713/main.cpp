#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    int N,M;
    cin >> N >> M;
    vector <int> P(M+1,0);
    vector <long long> A(N,0);
    vector <long long> B(N,0);
    vector <long long > C(N,0);
    vector <int> visit(N+1,0);
    for(int i=1; i<=M; i++) {
        cin >> P[i];
    }

    for(int i=1; i<N; i++) {
        cin >> A[i] >> B[i] >> C[i];
    }

    for(int i=1; i<=M-1; i++) {
        int a = min(P[i],P[i+1]), b = max(P[i],P[i+1]);
        visit[a]++;
        visit[b]--;
    }

    int curvis = 0;
    long long ans = 0;
    for(int i=1; i<N; i++) {
        curvis += visit[i];
        ans += min(A[i] * curvis, B[i] * curvis + C[i]);
    }
    cout << ans;

    return 0;
}
