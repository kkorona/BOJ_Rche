#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N; 
		map <string, int> index;
		vector <int> arr(N,0);
		for(int i=0; i<N; i++) {
			string s;
			cin >> s;
			index[s] = i;
		}
		for(int i=0; i<N; i++) {
			string s;
			cin >> s;
			arr[index[s]] = i;
		}
		index.clear();
		vector <string> input;
		for(int i=0; i<N; i++) {
			string s;
			cin >> s;
			input.push_back(s);
		}
		for(int i=0;  i<N; i++) {
			cout << input[arr[i]] << " ";
		}
		input.clear();
		arr.clear();
		cout << endl;
	}
	
	return 0;
}
