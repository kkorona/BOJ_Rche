#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int N,M;
	cin >> N >> M;
	
	vector < long long > modList(M,0);
	
	long long x;	
	long long sum = 0;
	long long ans = 0;
	modList[0] = 1;
	
	for(int i=1; i<=N; i++) {
		cin >> x;
		sum =  sum + x;
		ans += modList[sum%M];
		modList[sum%M]++;		
	}
	
	cout << ans;
	
	return 0;
}
