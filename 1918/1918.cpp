#include <bits/stdc++.h>
using namespace std;
bool isPop(char in, char now) {
	if (in == '(') return false;
	if ((now == '*' || now == '/') && (in == '+' || in == '-')) return false;
	return true;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string S;
	cin >> S;
	stack<char> ST;
    int _size = S.length();
	for(int i=0; i<_size; i++) {
		if ('A' <= S[i] && S[i] <= 'Z') {
			cout << S[i];
			continue;
		}
		if (S[i] == '(') {
			ST.push(S[i]);
			continue;
		}
		if (S[i] == ')') {
			while (ST.top() != '(') {
				cout << ST.top();
				ST.pop();
			}
			ST.pop();
			continue;
		}
		while (!ST.empty() && isPop(ST.top(), S[i])) {
			cout << ST.top();
			ST.pop();
		}
		ST.push(S[i]);
	}
	while (!ST.empty()) {
		cout << ST.top();
		ST.pop();
	}
}
