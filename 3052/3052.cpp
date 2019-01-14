#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	set <int> mods;
	
	for(int i=0; i<10; i++) {
		int x;
		cin >> x;
		mods.insert(x%42);
	}
	
	cout << mods.size();
	
	return 0;
}
