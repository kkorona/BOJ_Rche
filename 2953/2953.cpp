#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int N = 5;
	int ansval = 0, ans;
	for(int idx = 1; idx <= 5; idx++) {
		int sum, x;
		sum = 0;
		for(int i=0; i<4; i++) {
			cin >> x;
			sum += x;
			
		}
		if(ansval < sum) {
			ansval = sum;
			ans = idx;
		}
	}
	
	cout << ans << " " << ansval;
	
	return 0;
}
