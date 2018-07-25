#include <bits/stdc++.h>
using namespace std;

struct classcomp {
    bool operator() (const string& lhs, const string& rhs) const {
        if(lhs.size() != rhs.size()) return lhs.size() < rhs.size();
        return (lhs.compare(rhs) < 0);
    }
} myclass;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
    int N;
    cin >> N;
    vector <string> result;
    while(N--) {
        string input;
        cin >> input;
        int _size = input.size();
        bool flag = false;
        string temp("");
        for(int i=0; i<_size; i++) {
            if(flag) { // 숫자 처리중
                if('0' <= input[i] && input[i] <= '9') { // 숫자가 계속 들어온다
                    if(temp.empty() && input[i] == '0') continue; // 000000000X 꼴의 숫자의 앞부분을 slice
                    temp.push_back(input[i]); //아니면 push
                }
                else { // 숫자가 끝나고 문자가 들어왔다
                    if(temp.empty()) temp.push_back('0'); // 000000000 을 0으로 처리
                    result.push_back(temp);
                    temp.clear();
                    flag = false;
                }
            }
            else {
                if('0' <= input[i] && input[i] <= '9') { //문자가 들어오다가 숫자가 들어왔다
                    flag = true;
                    if(input[i] == '0') continue; // 00000000~ 처리
                    temp.push_back(input[i]);
                }
            }
        }
        if(flag) { // 숫자로 line이 끝났다
            if(temp.empty()) temp.push_back('0');
            result.push_back(temp);
        }
    }
    sort(result.begin(),result.end(),myclass);
    for(string ret : result) cout << ret << "\n";
    return 0;
}
