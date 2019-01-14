#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int N,M;
	cin >> N;
	
	vector <int> arr(N+1,0);
	vector <int> sum(N+1,0);
	
	for(int i=1; i<=N; i++) {
		cin >> arr[i];
		sum[i] = sum[i-1] + arr[i];
	}
	
	cin >> M;
	
	for(int i=0; i<M; i++) {
		int st, ed;
		cin >> st >> ed;
		cout << sum[ed] - sum[st-1] << '\n';
	}
	
	return 0;
}
