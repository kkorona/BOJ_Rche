#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector <int> input(N+1);
    vector <int> ans(N+1);
    for(int i=1; i<=N; i++) {
        ans[i] = i;
        cin >> input[i];
    }
    int start,finish;
    int rev_count = 0;
    bool do_reverse = false;
    vector < pair < int,int > > ret(2);
    ret[0] = make_pair(1,1);
    ret[1] = make_pair(2,2);
    for(int i=1; i<=N; i++) {
        if(input[i] != ans[i]) {
            if(rev_count >= 2) {
                do_reverse = true;
                break;
            }
            else {
                start = i;
                finish = i+1;
                while(input[finish] != ans[i]) finish++;
                reverse(input.begin()+start,input.begin()+finish+1);
                ret[rev_count] = make_pair(start,finish);
                rev_count ++;
            }
        }
    }
    if(do_reverse) {
        reverse(input.begin() + ret[1].first, input.begin() + ret[1].second + 1);
        reverse(input.begin() + ret[0].first, input.begin() + ret[0].second + 1);
        rev_count = 0;
        for(int i=N; i>=1; i--) {
            if(input[i] != ans[i]) {
                finish = i;
                start = i-1;
                while(input[start] != ans[i]) start--;
                reverse(input.begin()+start,input.begin()+finish+1);
                ret[rev_count] = make_pair(start,finish);
                rev_count++;
            }
        }
    }
    cout << ret[0].first << " " << ret[0].second << "\n" << ret[1].first << " " << ret[1].second;
    return 0;
}
