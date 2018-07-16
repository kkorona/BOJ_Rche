#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int main() {
    vector < pii > input;
    priority_queue < int, vector<int>, greater<int> > pq;
    int N;
    cin >> N;
    for(int i=0; i<N; i++) {
        int s,e;
        cin >> s >> e;
        input.push_back({s,e});
    }
    sort(input.begin(),input.end());
    for(pii& q : input) {
        if(pq.empty()) {
            pq.push(q.second);
        }
        else if(pq.top() <= q.first) {
            pq.pop();
            pq.push(q.second);
        }
        else {
            pq.push(q.second);
        }
    }
    cout << pq.size();
    return 0;
}
