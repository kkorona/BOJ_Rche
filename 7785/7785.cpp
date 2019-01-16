#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	map <string,int> members;
	while(n>0) {
    n=n-1;
		string name, state;
		cin >> name >> state;
		if(state.compare(string("enter")) == 0) {
			members[name]=1;
		}
		else {
			members[name]=0;
		}
	}
	
    vector <string> result;
	for(auto& member : members) {
		if(member.second) result.push_back(member.first);
	}
    sort(result.begin(),result.end());
    reverse(result.begin(),result.end());
    for(auto& member : result) cout << member << '\n';
	
	return 0;
}
	
