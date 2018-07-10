#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

int main()
{
    map <string,int> P;
    set <string> ans;
    int N,M;
    cin >> N >> M;
    while(N--) {
        string input;
        cin >> input;
        P[input]=1;
    }
    while(M--) {
        string input;
        cin >> input;
        if(P[input] == 1) ans.insert(input);
    }
    cout << ans.size() << endl;
    for(auto str:ans)
        cout << str << endl;
    return 0;
}
